void upd(auto& tree, int i, const auto& val) {
  while (i < tree.size()) {
    tree[i] += val;
    i += i & -i;
  }
}

auto query(auto& tree, int i) {
  auto res = tree[i];
  i -= i & -i;
  while (i > 0) {
    res += tree[i];
    i -= i & -i;
  }
  return res;
}