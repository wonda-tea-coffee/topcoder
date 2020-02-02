import java.util.*;

public class InterestingDigits {
  public int[] digits(int base) {
    int n = base - 1;
    List<Integer> list = new ArrayList<>();
    for (int d = 2; d <= n; d++) {
      if (n % d == 0) {
        list.add(d);
      }
    }

    int[] ans = new int[list.size()];
    for (int i = 0; i < list.size(); i++) {
      ans[i] = list.get(i);
    }

    return ans;
  }
}