#include <bits/stdc++.h>

#include "aoj.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  int N = 1000;
  vector dp(N + 1, vector(N + 1, mint(0)));
  rep(i, N + 1) rep(j, N + 1) {
    if (j == 0) {
      dp[i][j] = 0;
    } else if (i == 0) {
      dp[i][j] = 1;
    } else {
      dp[i][j] += dp[i][j - 1];
      if (i - j >= 0) {
        dp[i][j] += dp[i - j][j];
      }
    }
  }
  ints(n, k);
  if (n - k < 0) {
    wt(0);
  } else {
    wt(dp[n - k][k]);
  }
}
