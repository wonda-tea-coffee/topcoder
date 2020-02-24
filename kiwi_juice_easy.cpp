#include <vector>
using namespace std;

class KiwiJuiceEasy
{
public:
  vector<int>
  thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)
  {
    int m = fromId.size();
    for (int i = 0; i < m; i++)
    {
      int move = min(capacities[toId[i]] - bottles[toId[i]], bottles[fromId[i]]);
      bottles[fromId[i]] -= move;
      bottles[toId[i]] += move;
    }
    return bottles;
  }
};