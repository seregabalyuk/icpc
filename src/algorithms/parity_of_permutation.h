bool parity_of_permutation(const vector<int>& per) {
  int n = per.size();
  if (n == 1) return false;
  vector<int> pos(n);
  vector<int> cur(n);
  for (auto i: views::iota(0, n)) {
    cur[i] = per[i] - 1;
  }
  for (auto i: views::iota(0, n)) {
    pos[cur[i]] = i;
  }
  auto do_cycle = [&] (int i, int j, int k) {
    int tmp = cur[i];
    cur[i] = cur[j];
    cur[j] = cur[k];
    cur[k] = tmp;

    pos[cur[i]] = i;
    pos[cur[j]] = j;
    pos[cur[k]] = k;
  };
  for (auto i: views::iota(0, n)) {
    if (pos[i] != i) {
      int j = pos[i];
      if (j != n - 1) 
        do_cycle(i, j, n - 1);
      else
        do_cycle(i, j, n - 2);
    }
  }
  return cur[n - 1] != n - 1;
}