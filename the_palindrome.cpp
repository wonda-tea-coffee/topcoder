#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

class ThePalindrome
{
public:
  int find(string s)
  {
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      string ss = s.substr(i);
      if (is_reversible(ss))
      {
        return i + n;
      }
    }
    return -1;
  }

private:
  bool is_reversible(string s)
  {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
      if (s[i] != s[n - i - 1])
        return false;
    }
    return true;
  }
};
