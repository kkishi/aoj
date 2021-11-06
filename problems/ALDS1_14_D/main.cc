#include <bits/stdc++.h>

#include "aoj.h"
#include "suffix_array.h"

void Main() {
  strings(t);
  V<int> sa = SuffixArray(t);
  ints(q);
  rep(q) {
    strings(p);
    auto [l, r] = SuffixArraySearch(t, sa, p);
    wt(l != r ? 1 : 0);
  }
}
