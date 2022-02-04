#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./grid.cpp"
#include "./voters.cpp"


#define NUM_VOTERS 300
#define NUM_CANDIDATES 3

#define GET_MACRO(_1, _2, NAME, ...) NAME
#define MIN(x, y) (x < y ? x : y)

int main() {
  using namespace std;

  Grid GRID;

  // Random Number Seed
  srand(time(0));
  cout << GRID.max_val;
  // Voters
  for (int i = 0; i < NUM_VOTERS; i++) {
    GRID.add(
      pt {
        rand() % GRID.max_val,
        rand() % GRID.max_val
      }
    );
  }

  // Candidates
  cand *candidates[NUM_CANDIDATES];
  cand C1 = {333, 333}; candidates[0] = &C1;
  cand C2 = {500, 500}; candidates[1] = &C2;
  cand C3 = {666, 666}; candidates[2] = &C3;
  C1.name = "Bob";
  C2.name = "Alice";
  C3.name = "Gyrant";


  for (const pt voter : GRID.points) {
    cout << '(' << voter.x << ',' << voter.y << ')' << endl;
    double min = GRID.max_val;
    int c = 0;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
      cand *candidate = candidates[i];
      double dist = sqrt(
        (candidate->x - voter.x) * (candidate->x - voter.x) +
        (candidate->y - voter.y) * (candidate->y - voter.y)
      );
      if (dist < min) {
        min = dist;
        c = i;
      }
    }
    candidates[c]->score++;
  }

  for (cand *candidate : candidates) {
    cout << candidate->name << ' ' << candidate->score << endl;
  }

}
