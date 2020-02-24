#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

class InterestingParty
{
public:
  int bestInvitation(vector<string> first, vector<string> second)
  {
    map<string, int> map;
    first.insert(first.end(), second.begin(), second.end());

    int ans = 0;
    for (int i = 0; i < first.size(); i++)
    {
      string f = first.at(i);
      if (map.count(f))
      {
        map.at(f) += 1;
      }
      else
      {
        map.insert(make_pair(f, 1));
      }
      ans = max(ans, map.at(f));
    }

    return ans;
  }
};
