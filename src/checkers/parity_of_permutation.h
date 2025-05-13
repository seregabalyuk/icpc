void checker(auto& cin, auto& cout) {
  int n;
  cin >> n;
  vector<int> per(n);
  for (auto& x: per) cin >> x;
  cout << parity_of_permutation(per) << '\n';
}