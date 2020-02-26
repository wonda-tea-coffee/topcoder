#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class NumberMagicEasy
{
public:
  int theNumber(string answer)
  {
    vector<vector<int>> c = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 9, 10, 11, 12},
        {1, 2, 5, 6, 9, 10, 13, 14},
        {1, 3, 5, 7, 9, 11, 13, 15}};

    for (int i = 1; i <= 16; i++)
    {
      string a = "";
      for (int j = 0; j < 4; j++)
      {
        auto result = find(c[j].begin(), c[j].end(), i);
        if (result == c[j].end())
        {
          a += "N";
        }
        else
        {
          a += "Y";
        }
      }
      // cout << i << " " << a << endl;
      if (a == answer)
      {
        return i;
      }
    }

    return -1;
  }
};

int main()
{
  NumberMagicEasy *c = new NumberMagicEasy;
  cout << c->theNumber("YNYY") << endl;
}