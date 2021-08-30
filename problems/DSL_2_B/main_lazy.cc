#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"

void Main() {
  ints(n, q);
  add_sum::segtree r(V<add_sum::S>(n, {0, 1}));
  rep(q) {
    ints(com, x, y);
    --x;
    if (com == 0) {
      r.apply(x, y);
    } else {
      wt(r.prod(x, y).val);
    }
  }
}
