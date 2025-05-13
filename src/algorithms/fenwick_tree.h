void upd(auto& tree, size_t i, const auto& val) {
  while (i < tree.size()) {
    tree[i] += val;
    i += i & -i;
  }
}

auto query(auto& tree, size_t i) {
  auto res = tree[i];
  i -= i & -i;
  while (i > 0) {
    res += tree[i];
    i -= i & -i;
  }
  return res;
}