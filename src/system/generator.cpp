#include "generators/Permutation.h"
#include "generators/Default.h"
#include "generators/Program.h"
#include "generators/Randnum.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>



int main(int args, char** argv) {
  int n;
  std::cin >> n;
  Program program;

  std::string word;
  std::map<std::string, int> names;
  bool is_new_value = false;
  bool is_have_params = false;
  bool is_end = false;
  std::vector<std::string> command;
  auto& fabric = FabricGenerator::instance();

  auto add_command = [&]() {
    if (command.size() == 0) return 0;
    if (is_end) {
      program.commands.emplace_back();
      int i = 0;
      if (is_new_value) {
        int id_val = names.size() + 1;
        names[command[i ++]] = id_val;
        program.commands.back().id_value = id_val;
      }
      auto& fabric = FabricGenerator::instance();
      auto gen_name = command[i ++];
      if (fabric.count(gen_name)) {
        program.commands.back().generate = fabric.get(gen_name);
      } else {
        std::cout << "not found " << gen_name << '\n';
        program.commands.pop_back();
        is_have_params = false;
        is_new_value = false;
        is_end = false;
        command.clear();
        return 1;
      }
      for (; i < command.size(); ++ i) {
        int id = 0;
        if (names.count(command[i])) {
          id = - names[command[i]];
        } else {
          id = program.strings.size();
          program.strings.emplace_back(command[i]);
        }
        program.commands.back().params.emplace_back(id);
      }
      is_have_params = false;
      is_new_value = false;
      is_end = false;
      command.clear();
    } else if (!is_have_params) {
      if (command.size() < 2 && is_new_value) return 0;
      program.commands.emplace_back();
      int i = 0;
      if (is_new_value) {
        int id_val = names.size() + 1;
        names[command[i ++]] = id_val;
        program.commands.back().id_value = id_val;
      }
      auto& fabric = FabricGenerator::instance();
      program.commands.back().generate = fabric.get("default");
      int id = 0;
      if (names.count(command[i])) {
        id = - names[command[i]];
      } else {
        id = program.strings.size();
        program.strings.emplace_back(command[i]);
      }
      program.commands.back().params.emplace_back(id);
      is_have_params = false;
      is_new_value = false;
      is_end = false;
      command.clear();
    }
    return 0;
  };

  while (std::cin) {
    char c = std::cin.get();
    switch (c) {
    case '(':
      is_have_params = true;
      if (word.size())
      command.emplace_back(word);
      word.clear();
      break;
    case '=':
      is_new_value = true;
      if (word.size())
      command.emplace_back(word);
      word.clear();
      break;
    case ')':
      is_end = true;
      if (word.size())
      command.emplace_back(word);
      word.clear();
      break;
    case ',':
      if (word.size())
      command.emplace_back(word);
      word.clear();
      break;
    case ' ':
    case '\n':
    case EOF:
      if (!is_have_params || is_end) {
        if (word.size())
        command.emplace_back(word);
        word.clear();
      }
      break;
    default:
      if (word.size() == 0) {
        if (add_command()) {
          return 1;
        }
      }
      word.push_back(c);
      break;
    }
  }
  if (add_command()) {
    return 1;
  }

  std::ofstream fout(argv[1]);

  fout << n << '\n';
  srand(std::time(0));
  for (auto i: std::views::iota(0, n)) {
    fout << program.execute(rand());
  }
}