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

class CorporationSalary {
  public:
  ll memo[55];
  long long totalSalary(vector <string> relations) {
    REP(i, 55) memo[i] = -1;

    ll ret = 0;

    REP(i, relations.size()) {
      ret += salary(i, relations);
    }

    cout << memo[0] << endl;
    cout << memo[1] << endl;
    cout << memo[2] << endl;
    cout << memo[3] << endl;

    return ret;
  }

  private:
  ll salary(int i, vector<string> relations) {
    if (memo[i] != -1) return memo[i];

    ll ret = 0;
    REP(j, relations.size()) {
      if (relations[i][j] == 'Y') {
        ret += salary(j, relations);
      }
    }

    if (ret == 0) {
      memo[i] = 1;
    } else {
      memo[i] = ret;
    }

    return memo[i];
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  CorporationSalary *cs = new CorporationSalary;
  cout << cs->totalSalary({"NNYN","NNYN","NNNN","NYYN"}) << endl;
}