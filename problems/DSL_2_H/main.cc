#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"

void Main() {
  ints(n, q);
  add_min::segtree st(V<int>(n, 0));
  rep(q) {
    ints(k, s, t);
    ++t;
    if (k == 0) {
      ints(x);
      st.apply(s, t, x);
    } else {
      wt(st.prod(s, t));
    }
  }
}
