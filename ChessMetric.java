public class ChessMetric {
  public long howMany(int size, int[] start, int[] end, int numMoves) {
    int[][] dist = new int[][] { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 },
        { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 }, { -1, -2 }, { 1, -2 }, { -1, 2 }, { 1, 2 }, };
    long[][][] ans = new long[numMoves + 1][size][size];

    ans[0][start[0]][start[1]] = 1;

    for (int i = 0; i < numMoves; i++) {
      for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
          if (ans[i][y][x] == 0)
            continue;

          for (int di = 0; di < 16; di++) {
            int ny = y + dist[di][0];
            int nx = x + dist[di][1];

            if (ny < 0 || ny >= size || nx < 0 || nx >= size)
              continue;

            ans[i + 1][ny][nx] += ans[i][y][x];
          }
        }
      }
    }

    return ans[numMoves][end[0]][end[1]];
  }
}