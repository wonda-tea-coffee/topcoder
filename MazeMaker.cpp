#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class MazeMaker
{
public:
  int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol)
  {
    const int INF = 100000000;
    int h = maze.size();
    int w = maze[0].size();
    int mins[h][w];
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        mins[i][j] = INF;
      }
    }

    queue<int> qRow;
    queue<int> qCol;
    queue<int> qCost;

    qRow.push(startRow);
    qCol.push(startCol);
    qCost.push(0);
    mins[startRow][startCol] = 0;

    while (!qRow.empty())
    {
      int row = qRow.front();
      int col = qCol.front();
      int cost = qCost.front();
      qRow.pop();
      qCol.pop();
      qCost.pop();

      for (int mi = 0; mi < moveRow.size(); mi++)
      {
        int nRow = row + moveRow[mi];
        int nCol = col + moveCol[mi];

        if (nRow < 0 || nRow >= h || nCol < 0 || nCol >= w)
        {
          continue;
        }
        if (maze[nRow][nCol] == 'X')
        {
          continue;
        }
        if (mins[nRow][nCol] <= cost + 1)
        {
          continue;
        }

        mins[nRow][nCol] = cost + 1;
        qRow.push(nRow);
        qCol.push(nCol);
        qCost.push(cost + 1);
      }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
      for (int j = 0; j < w; j++)
      {
        // cout << mins[i][j] << " ";
        if (maze[i][j] == 'X')
        {
          continue;
        }
        if (mins[i][j] == INF)
        {
          return -1;
        }
        else
        {
          ans = max(ans, mins[i][j]);
        }
      }
      // cout << endl;
    }
    return ans;
  }
};

int main()
{
  MazeMaker *c = new MazeMaker;
  cout << c->longestPath({"......."}, 0, 0, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}) << endl;
}