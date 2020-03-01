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

class HandsShaking {
  public:
  ll countPerfect(int n) {
    ll dp[51] = {};
    dp[0] = 1;
    for (int i = 2; i <= n; i += 2) {
      for (int j = 0; j <= i - 2; j += 2) {
        dp[i] += dp[j] * dp[i - j - 2];
      }
    }

    return dp[n];
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  HandsShaking *hs = new HandsShaking;
  cout << hs->countPerfect(8) << endl;
}