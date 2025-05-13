#pragma once
#include "Generator.h"
#include <random>
#include <ranges>


std::string randnum_generate(
  size_t seed,
  const std::vector<std::string>& params
) {
  std::mt19937_64 rand(seed);
  std::string out;
  if (params.size() == 2) {
    long long min = std::stoll(params[0]);
    long long max = std::stoll(params[1]);
    long long num = rand() % (max - min + 1) + min;
    out = std::to_string(num);
  } 
  if (params.size() == 3) {
    long long min = std::stoll(params[0]);
    long long max = std::stoll(params[1]);
    for(int i: std::views::iota(0, std::stoi(params[2]))) {
      out += std::to_string(rand() % (max - min + 1) + min);
      out.push_back(' ');
    }
  }
  return out;
}

namespace {
  struct RandomintRegistrator {
    RandomintRegistrator() {
      auto& fabric = FabricGenerator::instance();
      fabric.registrate(
        "randnum", 
        randnum_generate
      );
    }
  } randomintRegistrator;
}