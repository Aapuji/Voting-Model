#include <vector>
#include <cmath>

#define GRID_SIZE 1000

struct point {
  int x;
  int y;
};

typedef point pt;

struct Grid {
  const int range = GRID_SIZE;
  const int min_val = 0;
  const int max_val = min_val + GRID_SIZE;

  std::vector<pt> points;
  std::vector<pt> refpoints;

  void add(const pt P) {
    points.push_back(P);
  }
  void add_Refpoint(const pt R) {
    refpoints.push_back(R);
  }
};
