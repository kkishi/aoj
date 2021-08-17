#include <bits/stdc++.h>

#include "aoj.h"
#include "intervals.h"

void Main() {
  ints(n, m, q);
  V<tuple<int, int, int, int, int>> v;
  rep(m) {
    ints(d, a, b);
    v.eb(d, 1, a, b, 0);
  }
  rep(i, q) {
    ints(e, s, t);
    v.eb(e, 0, s, t, i);
  }
  sort(all(v));
  Intervals is;
  V<bool> ans(q);
  for (auto [d, elevator, a, b, i] : v) {
    if (elevator) {
      is.Erase(a, b);
      is.Insert(a, b);
    } else {
      ans[i] = (b <= a) || (is.Mex(a) >= b);
    }
  }
  each(e, ans) wt(bool(e));
}
