#include <bits/stdc++.h>

#include "aoj.h"

void Main() {
  ints(n, m, p);
  VV<int> g(n);
  rep(m) {
    ints(v, u);
    --v, --u;
    g[v].pb(u);
    g[u].pb(v);
  }

  V<double> dp(1 << n);
  rep(mask, 1 << n) {
    dp[mask] = 1;
    int i = __builtin_ctz(mask);
    for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
      if (hasbit(sub, i)) {
        double x = 1.0;
        rep(i, n) if (hasbit(sub, i)) each(j, g[i]) if (hasbit(mask ^ sub, j))
            x *= p / 100.0;
        dp[mask] -= dp[sub] * x;
      }
    }
  }
  wt(dp[(1 << n) - 1]);
}
