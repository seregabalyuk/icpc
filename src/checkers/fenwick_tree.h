void checker(auto& cin, auto& cout) {
  int n, q;
  cin >> n >> q;
  vector<int> tree(n + 1, 0);
  while (q --) {
    string str;
    cin >> str;
    if (str == "upd") {
      int i, val;
      cin >> i >> val;
      upd(tree, i, val);
    }
    if (str == "query") {
      int i;
      cin >> i;
      cout << query(tree, i) << '\n';
    }
  }
}