public class BadNeighbors {
  public int maxDonations(int[] donations) {
    int n = donations.length;
    if (n == 2) {
      return Math.max(donations[0], donations[1]);
    }

    int[] dp1 = new int[n];
    int[] dp2 = new int[n];

    dp1[1] = donations[1];
    dp2[0] = donations[0];
    dp2[1] = donations[0];

    for (int i = 2; i < n - 1; i++) {
      dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + donations[i]);
      dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + donations[i]);
    }
    dp1[n - 1] = Math.max(dp1[n - 2], dp1[n - 3] + donations[n - 1]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = Math.max(ans, Math.max(dp1[i], dp2[i]));
    }

    return ans;
  }
}