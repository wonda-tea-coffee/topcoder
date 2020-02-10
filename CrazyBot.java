import java.util.*;

public class CrazyBot {
  public static int N;
  public static int EAST;
  public static int WEST;
  public static int SOUTH;
  public static int NORTH;
  public static int[][] dist;

  public double getProbability(int n, int east, int west, int south, int north) {
    N = n;
    EAST = east;
    WEST = west;
    SOUTH = south;
    NORTH = north;
    dist = new int[][] { { 1, 0, EAST }, { -1, 0, WEST }, { 0, 1, SOUTH }, { 0, -1, NORTH } };

    Set<String> set = new HashSet<>();
    set.add("0,0");
    return dfs(1, 0, 0, 0, set);
  }

  public double dfs(double prob, int n, int x, int y, Set<String> set) {
    if (n == N)
      return prob;

    double ret = .0;

    for (int i = 0; i < 4; i++) {
      int[] d = dist[i];
      int dx = d[0];
      int dy = d[1];
      int p = d[2];

      int nx = x + dx;
      int ny = y + dy;
      String v = Integer.toString(nx) + "," + Integer.toString(ny);

      if (!set.contains(v)) {
        set.add(v);
        ret += dfs(prob * p / 100, n + 1, nx, ny, set);
        set.remove(v);
      }
    }

    return ret;
  }

  public static void main(String[] main) {
    System.out.println(new CrazyBot().getProbability(14, 25, 25, 25, 25));
  }
}