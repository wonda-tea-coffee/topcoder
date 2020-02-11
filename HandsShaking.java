public class HandsShaking {
  static long[] memo;

  public long countPerfect(int n) {
    memo = new long[n + 1];

    return solve(n);
  }

  private long solve(int n) {
    if (n <= 4) {
      return n / 2;
    }
    if (memo[n] > 0) {
      return memo[n];
    }

    long ans = 2 * solve(n - 2);
    for (int i = 2; i <= n - 4; i += 2) {
      ans += solve(i) * solve(n - i - 2);
    }
    return memo[n] = ans;
  }
}