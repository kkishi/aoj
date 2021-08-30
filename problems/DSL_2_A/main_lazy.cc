#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"

void Main() {
  ints(n, q);
  update_min::segtree r(V<int>(n, (1LL << 31) - 1));
  rep(q) {
    ints(com, x, y);
    if (com == 0) {
      r.set(x, y);
    } else {
      wt(r.prod(x, y + 1));
    }
  }
}
