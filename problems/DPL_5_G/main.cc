#include <bits/stdc++.h>

#include "aoj.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  vector dp(n + 1, vector(k + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) rep(j, k) dp[i + 1][j + 1] = dp[i][j] + (j + 1) * dp[i][j + 1];
  mint ans = 0;
  rep(i, 1, k + 1) ans += dp[n][i];
  wt(ans);
}
