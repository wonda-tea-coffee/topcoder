#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

class InterestingDigits
{
public:
  vector<int> digits(int base)
  {
    vector<int> ret = {};

    for (int d = 2; d < base; d++)
    {
      if ((base - 1) % d == 0)
      {
        ret.push_back(d);
      }
    }

    return ret;
  }
};
