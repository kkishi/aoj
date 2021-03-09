#include <bits/stdc++.h>

#include "aoj.h"
#include "bidirected_graph.h"
#include "rerooting.h"

struct DP {
  int height;
  int steps;
};

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(u, v);
    g.AddEdge(u - 1, v - 1);
  }
  V<DP> res = Rerooting<DP, int>(
      g,
      [](DP a, DP b) -> DP {
        return {max(a.height, b.height),
                a.steps + b.steps + min(a.height, b.height)};
      },
      [](const auto&, DP x) -> DP {
        return {x.height + 1, x.steps + 1};
      });
  each(r, res) wt(r.steps);
}
