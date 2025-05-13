ll gcd(ll a, ll b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}