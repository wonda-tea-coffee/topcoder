import java.util.*;

public class FriendScore {
  public int highestScore(String[] friends) {
    int n = friends.length;
    int[] scores = new int[n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;

        String f = friends[i];
        Set<Integer> count = new HashSet<>();

        for (int k = 0; k < n; k++) {
          if (f.charAt(k) == 'N')
            continue;

          count.add(k);

          for (int l = 0; l < n; l++) {
            if (i == l)
              continue;

            char c = friends[l].charAt(k);
            if (c == 'N')
              continue;

            count.add(l);
          }
        }

        scores[i] = count.size();
      }
    }

    int ans = 0;
    for (int score : scores) {
      ans = Math.max(ans, score);
    }

    return ans;
  }

  // public static void main(String[] args) {
  //   System.out.println(new FriendScore().highestScore(
  //       new String[] { "NNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNN", "NNNNNNNYNNNNNNY", "NNNNNNNNNNNNNNY",
  //           "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNN", "NNNNNYNNNNNYNNN", "NNNNNNNNNNNNNNY",
  //           "NNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNN", "NNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNN", "YNNYYNNNNYNNNNN" }));
  // }
}