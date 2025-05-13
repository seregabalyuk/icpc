#pragma once
#include "Generator.h"
#include <ranges>
#include <numeric>
#include <random>


std::string permutation_generate(
  size_t seed,
  const std::vector<std::string>& params
) {
  std::mt19937 rand(seed);
  std::string out;
  if (params.size() == 1) {
    int n = std::stoi(params[0]);
    std::vector<int> per(n);
    std::iota(per.begin(), per.end(), 1);
    for(int i: std::views::iota(0, n)) {
      int j = rand() % n;
      std::swap(per[i], per[j]);
    }
    for (auto x: per) {
      out += std::to_string(x) + " ";
    }
  }
  return out;
}


namespace {
  struct PermutationRegistrator {
    PermutationRegistrator() {
      auto& fabric = FabricGenerator::instance();
      fabric.registrate(
        "permutation", 
        permutation_generate
      );
    }
  } permutationRegistrator;
}