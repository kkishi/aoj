#include <bits/stdc++.h>

#include "aoj.h"
#include "bidirected_graph.h"
#include "rerooting.h"

void Main() {
  ints(n);
  BidirectedGraph<int> g(n);
  rep(n - 1) {
    ints(s, t, w);
    g.AddEdge(s, t, w);
  }
  V<int> res = Rerooting<int, int>(
      g, [](int a, int b) { return max(a, b); },
      [](const auto& e, int x) { return e.weight + x; });
  wt(*max_element(all(res)));
}
