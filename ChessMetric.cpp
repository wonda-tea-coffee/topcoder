#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i,n)   for (int i = 0; i < (n); ++i)
#define SORT(a)    sort((a).begin(), (a).end());
#define UNIQ(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define FIND(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define REVERSE(a) reverse((a).begin(), (a).end());

using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7

const int MAX_SIZE = 105;
const int MAX_MOVES = 50;
const int dx[16] = {0, 1, 1, 1, 0, -1, -1, -1, 1, 2, 2, 1, -1, -2, -2, -1};
const int dy[16] = {-1, -1, 0, 1, 1, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int SIZE;
ll dp[MAX_SIZE][MAX_SIZE][MAX_MOVES];

class ChessMetric {
  public:
  ll howMany(int size, vector <int> start, vector <int> end, int numMoves) {
    SIZE = size;
    REP(i, MAX_SIZE)REP(j, MAX_SIZE)REP(k, MAX_MOVES) dp[i][j][k] = -1;

    dp[start[0]][start[1]][0] = 1;

    return solve(end[0], end[1], numMoves);
  }

  private:
  ll solve(int x, int y, int move) {
    // cout << "x = " << x << ", y = " << y << ", move = " << move << endl;
    if (dp[x][y][move] != -1) return dp[x][y][move];
    if (move == 0) return 0;

    ll ret = 0;
    REP(i, 16) {
      int nx = x - dx[i];
      int ny = y - dy[i];
      if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
        ret += solve(nx, ny, move - 1);
      }
    }

    return dp[x][y][move] = ret;

    return 0;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ChessMetric *cm = new ChessMetric;
  cout << cm->howMany(3, {0, 0}, {1, 0}, 1) << endl;
}