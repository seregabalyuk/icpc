#pragma once
#include "Generator.h"
#include <random>

struct Program {
  struct Command {
    Command() {}
    size_t id_value = 0;
    Generate generate;
    std::vector<int> params;
  };

  std::vector<Command> commands;
  std::vector<std::string> strings;
  Program() {}
  std::string execute(size_t seed) {
    std::mt19937_64 rand(seed);
    std::vector<std::string> valstrings(commands.size());
    for (const auto& command: commands) {
      auto id = command.id_value;
      std::vector<std::string> in;
      for (auto param: command.params) {
        if (param < 0) {
          in.emplace_back(valstrings[-param]);
        } else {
          in.emplace_back(strings[param]);
        }
      }
      valstrings[id] += command.generate(rand(), in);
      valstrings[id].push_back('\n');
    }
    return valstrings[0];
  }
};