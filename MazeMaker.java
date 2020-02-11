import java.util.*;

public class MazeMaker {
  public int longestPath(String[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol) {

    Queue<int[]> queue = new LinkedList<>();
    int h = maze.length;
    int w = maze[0].length();
    int[][] mins = new int[h][w];
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        mins[i][j] = Integer.MAX_VALUE;
      }
    }
    mins[startRow][startCol] = 0;

    queue.add(new int[] { startRow, startCol, 0 });

    while (!queue.isEmpty()) {
      int[] values = queue.poll();
      int y = values[0];
      int x = values[1];
      int c = values[2];

      for (int mi = 0; mi < moveRow.length; mi++) {
        int ny = y + moveRow[mi];
        int nx = x + moveCol[mi];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
          continue;

        if (maze[ny].charAt(nx) != '.')
          continue;

        if (c + 1 >= mins[ny][nx])
          continue;

        mins[ny][nx] = c + 1;

        queue.add(new int[] { ny, nx, c + 1 });
      }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (maze[i].charAt(j) != '.')
          continue;

        if (mins[i][j] == Integer.MAX_VALUE) {
          return -1;
        } else {
          ans = Math.max(ans, mins[i][j]);
        }
      }
    }

    return ans;
  }

  public static void main(String[] args) {
    MazeMaker mm = new MazeMaker();
    System.out.println(
        mm.longestPath(new String[] { "..X.X.X.X.X.X." }, 0, 0, new int[] { 2, 0, -2, 0 }, new int[] { 0, 2, 0, -2 }));
  }
}