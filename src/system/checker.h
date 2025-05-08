namespace NAMESPACE {
  #define STRINGIFY(x) #x
  #define INCLUDE_PATH(x) STRINGIFY(x)
  #include INCLUDE_PATH(ALGORITHM)
  #include INCLUDE_PATH(CHECKER)
}