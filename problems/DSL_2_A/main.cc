#include <bits/stdc++.h>

#include "aoj.h"
#include "min_segment_tree.h"

void Main() {
  ints(n, q);
  MinSegmentTree<int> r(n);
  rep(i, n) r.Set(i, (1LL << 31) - 1);
  rep(q) {
    ints(com, x, y);
    if (com == 0) {
      r.Set(x, y);
    } else {
      wt(r.Aggregate(x, y + 1));
    }
  }
}
