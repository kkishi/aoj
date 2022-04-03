#include <bits/stdc++.h>
#include <lazysegtree.h>

#include "aoj.h"
#include "heavy_light_decomposition.h"

void Main() {
  ints(n, q);
  Graph<int> g(n);
  rep(n - 1) {
    ints(a, b);
    g.AddEdge(a, b);
    g.AddEdge(b, a);
  }
  HeavyLightDecomposition hld(g, attr_on_edge);
  add_sum::segtree t(n);
  rep(q) {
    ints(k);
    if (k == 0) {
      ints(u, v);
      int ans = 0;
      each(l, r, hld.Path(u, v)) ans += t.prod(l, r).val;
      wt(ans);
    } else {
      ints(v, x);
      auto [l, r] = hld.Subtree(v);
      t.apply(l, r, x);
    }
  }
}
