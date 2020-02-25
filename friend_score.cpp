#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <set>
#include <iostream>
using namespace std;

class FriendScore
{
public:
  int highestScore(vector<string> friends)
  {
    int ans = 0;
    int n = friends.size();
    for (int i = 0; i < n; i++)
    {
      ans = max(ans, score(friends, i));
    }
    return ans;
  }

private:
  int score(vector<string> friends, int i)
  {
    int n = friends.size();
    string f = friends[i];
    set<int> nums;
    for (int j = 0; j < n; j++)
    {
      if (f[j] == 'N')
      {
        continue;
      }

      nums.insert(j);
      for (int k = 0; k < n; k++)
      {
        if (k == i)
        {
          continue;
        }

        if (friends[k][j] == 'Y')
        {
          nums.insert(k);
        }
      }
    }

    return nums.size();
  }
};

int main()
{
  FriendScore *fs = new FriendScore();
  cout << fs->highestScore({"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"}) << endl;
}
