#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class CrazyBot
{
public:
  bool visited[100][100] = {{false}};
  double prob[4];
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};
  double getProbability(int n, int east, int west, int south, int north)
  {
    prob[0] = north / 100.0;
    prob[1] = south / 100.0;
    prob[2] = west / 100.0;
    prob[3] = east / 100.0;

    return dfs(50, 50, n);
  }

  double dfs(int x, int y, int n)
  {
    if (visited[y][x])
    {
      return 0;
    }
    if (n == 0)
    {
      return 1;
    }

    visited[y][x] = true;

    double ret = 0;
    for (int i = 0; i < 4; i++)
    {
      ret += dfs(x + dx[i], y + dy[i], n - 1) * prob[i];
    }

    visited[y][x] = false;

    return ret;
  }
};

int main()
{
  CrazyBot *c = new CrazyBot;
  cout << c->getProbability(14, 25, 25, 25, 25) << endl;
}