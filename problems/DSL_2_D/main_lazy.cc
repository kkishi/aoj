#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"

void Main() {
  ints(n, q);
  update_min::segtree st(V<int>(n, (1LL << 31) - 1));
  rep(q) {
    ints(k);
    if (k == 0) {
      ints(s, t, x);
      st.apply(s, t + 1, x);
    } else {
      ints(i);
      wt(st.get(i));
    }
  }
}
