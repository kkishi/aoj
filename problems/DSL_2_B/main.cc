#include <bits/stdc++.h>

#include "add_segment_tree.h"
#include "aoj.h"

void Main() {
  ints(n, q);
  AddSegmentTree<int> r(n);
  rep(q) {
    ints(com, x, y);
    --x;
    if (com == 0) {
      r.Set(x, r.Get(x) + y);
    } else {
      wt(r.Aggregate(x, y));
    }
  }
}
