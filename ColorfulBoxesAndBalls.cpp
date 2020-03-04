#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
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
#define OUT(d) cout << (d);
#define OUT_L(d) std::cout<<(d)<<"\n";
#define Yes() printf("Yes\n");
#define No() printf("No\n");
#define YES() printf("YES\n");
#define NO() printf("NO\n");
#define CEIL(x, y) ((x + y - 1) / (y))

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

class ColorfulBoxesAndBalls {
  public:
  int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
    int ans = INT_MIN;

    // 赤箱に赤玉をいくつ入れるか
    for (int x = 0; x <= numRed; x++) {
      if (numRed - x > numBlue) continue;

      // 青箱に入れる赤玉の個数(=赤箱に入れる青玉の個数)
      int v1 = numRed - x;
      // 青箱に入れる青玉の個数
      int v2 = numBlue - v1;

      ans = max(ans, x * onlyRed + v1 * 2 * bothColors + v2 * onlyBlue);
    }

    return ans;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  OUT_L(INT_MIN)
}
