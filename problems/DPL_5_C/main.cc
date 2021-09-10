#include <bits/stdc++.h>

#include "aoj.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  mint ans = 0;
  rep(i, k) ans += (even(i) ? 1 : -1) * mint::Comb(k, i) * mint(k - i).Pow(n);
  wt(ans);
}
