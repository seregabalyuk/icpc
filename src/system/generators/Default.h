#pragma once
#include "Generator.h"


std::string default_generate(
  size_t seed,
  const std::vector<std::string>& params
) {
  auto str = params[0];
  if (str.size() && str.back() == '\n') {
    str.pop_back();
  }
  return str;
}

namespace {
  struct DefaultRegistrator {
    DefaultRegistrator() {
      auto& fabric = FabricGenerator::instance();
      fabric.registrate(
        "default", 
        default_generate
      );
    }
  } defaultRegistrator;
}