#include <bits/stdc++.h>

#include "aoj.h"
#include "binary_search.h"

using ld = long double;
#define double ld

void Main() {
  const int di[] = {0, 1, 0, -1};
  const int dj[] = {1, 0, -1, 0};

  ints(w, h);
  V<string> c(h);
  cin >> c;

  vector dist(h, vector(w, big));
  queue<tuple<int, int>> que;
  rep(i, h) rep(j, w) if (c[i][j] == 's') {
    dist[i][j] = 0;
    que.emplace(i, j);
  }
  bool can_jump = false;
  double g = -1;
  while (!que.empty()) {
    auto [i, j] = que.front();
    que.pop();
    if (c[i][j] == 'g') {
      g = dist[i][j];
      continue;
    }
    if (c[i][j] == '*') can_jump = true;
    rep(k, 4) {
      int ni = i + di[k];
      int nj = j + dj[k];
      if (c[i][j] == '#') continue;
      if (chmin(dist[ni][nj], dist[i][j] + 1)) {
        que.emplace(ni, nj);
      }
    }
  }
  if (!can_jump) {
    wt(g);
    return;
  }

  double big = 1e20;
  double s;
  BinarySearch<double>(big, 0, [&](double x) {
    VV<double> dist(h, vector(w, big));
    low_priority_queue<tuple<double, int, int>> que;
    auto push = [&](double d, int i, int j) {
      if (dist[i][j] <= d) return;
      dist[i][j] = d;
      que.emplace(d, i, j);
    };
    rep(i, h) rep(j, w) {
      char C = c[i][j];
      if (C == 'g') push(0, i, j);
      if (C == '*') push(x, i, j);
    }
    while (!que.empty()) {
      auto [d, i, j] = que.top();
      que.pop();
      if (dist[i][j] < d) continue;
      if (c[i][j] == 's') s = d;
      rep(k, 4) {
        int ni = i + di[k];
        int nj = j + dj[k];
        char C = c[ni][nj];
        if (C == '#' || C == '*') continue;
        push(d + 1, ni, nj);
      }
    }
    int cnt = 0;
    double sum = 0;
    rep(i, h) rep(j, w) {
      char C = c[i][j];
      if (C != '#' && C != '*' && C != 'g') {
        assert(dist[i][j] < big);
        ++cnt;
        sum += dist[i][j];
      }
    }
    return x > sum / cnt;
  });
  wt(s);
}
