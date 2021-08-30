#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"

void Main() {
  ints(n, q);
  add_sum::segtree st(n);
  rep(q) {
    ints(k);
    if (k == 0) {
      ints(s, t, x);
      st.apply(s - 1, t, x);
    } else {
      ints(t);
      wt(st.get(t - 1).val);
    }
  }
}
