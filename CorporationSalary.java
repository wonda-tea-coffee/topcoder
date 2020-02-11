import java.util.*;

public class CorporationSalary {
  static int n;
  static Map<Integer, List<Integer>> bukas = new HashMap<>();
  static long[] memo;

  public long totalSalary(String[] relations) {
    n = relations.length;
    memo = new long[n];

    for (int i = 0; i < n; i++) {
      List<Integer> list = new ArrayList<>();
      for (int j = 0; j < n; j++) {
        if (relations[i].charAt(j) == 'N')
          continue;

        list.add(j);
      }
      bukas.put(i, list);
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
      List<Integer> buka = bukas.get(i);
      if (buka.size() == 0) {
        memo[i] = 1;
        ans++;
        continue;
      }

      for (int j = 0; j < buka.size(); j++) {
        ans += salary(buka.get(j));
      }
    }

    return ans;
  }

  public long salary(int i) {
    if (memo[i] > 0) {
      return memo[i];
    }
    List<Integer> buka = bukas.get(i);
    long ret = 0;
    if (buka.size() == 0) {
      ret = 1;
    } else {
      for (int j = 0; j < buka.size(); j++) {
        ret += salary(buka.get(j));
      }
    }
    return memo[i] = ret;
  }
}