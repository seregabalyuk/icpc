#pragma once
#include <string>
#include <vector>
#include <map>
#include <functional>


using Generate = std::function<
  std::string(
    size_t seed,
    const std::vector<std::string>&
  )
>;

#include <iostream>
class FabricGenerator {
  FabricGenerator() {};
public:
  std::map<std::string, Generate> _generators;
  
  FabricGenerator(const FabricGenerator&) = delete;

  static FabricGenerator& instance() {
    static FabricGenerator fabric;
    return fabric;
  }

  void registrate(const std::string& name, Generate func) {
    _generators.emplace(name, func); 
  }

  Generate get(const std::string& name) {
    return _generators[name];
  }

  size_t count(const std::string& name) {
    return _generators.count(name);
  }
};



