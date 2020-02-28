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
#include <tuple>
#include <vector>

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define SORT(a) sort((a).begin(), (a).end());
#define UNIQ(a) SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());

using namespace std;
using ll = long long;
using P = pair<int,int>;
using namespace std;

const int MOD = 1000000007; // 10^9 + 7

class BadNeighbors {
  public:
  int maxDonations(vector <int> donations) {
    int dp[45][2] = {{0}};
    int n = donations.size();

    dp[0][0] = donations[0];
    dp[1][0] = donations[0];
    dp[0][1] = 0;
    dp[1][1] = donations[1];

    for (int i = 2; i < n - 1; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + donations[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + donations[i]);
    }
    dp[n - 1][0] = dp[n - 2][0];
    if (n >= 3) {
      dp[n - 1][1] = max(dp[n - 2][1], dp[n - 3][1] + donations[n - 1]);
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  BadNeighbors *bn = new BadNeighbors;
  cout << bn->maxDonations({10, 3, 2, 5, 7, 8}) << endl;
}