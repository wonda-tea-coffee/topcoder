import java.util.HashMap;
import java.util.Map;

public class InterestingParty {
  public int bestInvitation(String[] first, String[] second) {
    Map<String, Integer> map = new HashMap<>();

    for (int i = 0; i < first.length; i++) {
      String f = first[i];
      if (map.containsKey(f)) {
        int c = map.get(f);
        map.put(f, c + 1);
      } else {
        map.put(f, 1);
      }

      String s = second[i];
      if (map.containsKey(s)) {
        int c = map.get(s);
        map.put(s, c + 1);
      } else {
        map.put(s, 1);
      }
    }

    int ans = 0;
    for (String key : map.keySet()) {
      ans = Math.max(ans, map.get(key));
    }
    return ans;
  }
}