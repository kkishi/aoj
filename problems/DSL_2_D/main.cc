#include <bits/stdc++.h>

#include "aoj.h"
#include "intervals.h"

void Main() {
  ints(n, q);
  Intervals is;
  rep(q) {
    ints(k);
    if (k == 0) {
      ints(s, t, x);
      is.Erase(s - 1, t);
      is.Insert(s - 1, t, x);
    } else {
      ints(i);
      auto I = is.Find(i - 1);
      int ans = (1LL << 31) - 1;
      if (I) ans = I->value;
      wt(ans);
    }
  }
}
