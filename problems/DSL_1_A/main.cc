#include <bits/stdc++.h>

#include "aoj.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  DisjointSet ds(n);
  rep(q) {
    ints(com, x, y);
    if (com == 0) {
      ds.Union(x, y);
    } else {
      wt(int(ds.Same(x, y)));
    }
  }
}
