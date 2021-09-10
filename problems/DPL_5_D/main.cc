#include <bits/stdc++.h>

#include "aoj.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  wt(mint::Comb(n + k - 1, k - 1));
}
