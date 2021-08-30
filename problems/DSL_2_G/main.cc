#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"

void Main() {
  ints(n, q);
  add_sum::segtree st(n);
  rep(q) {
    ints(k, s, t);
    --s;
    if (k == 0) {
      ints(x);
      st.apply(s, t, x);
    } else {
      wt(st.prod(s, t).val);
    }
  }
}
