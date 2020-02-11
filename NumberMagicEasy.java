public class NumberMagicEasy {
  public int theNumber(String answer) {
    int[][] cards = new int[][] { { 1, 2, 3, 4, 5, 6, 7, 8 }, { 1, 2, 3, 4, 9, 10, 11, 12 },
        { 1, 2, 5, 6, 9, 10, 13, 14 }, { 1, 3, 5, 7, 9, 11, 13, 15 } };
    for (int i = 1; i <= 16; i++) {
      String ans = "";
      for (int j = 0; j < 4; j++) {
        if (isIn(cards[j], i)) {
          ans += "Y";
        } else {
          ans += "N";
        }
      }
      if (ans.equals(answer)) {
        return i;
      }
    }
    return -1;
  }

  public boolean isIn(int[] ary, int target) {
    for (int a : ary) {
      if (a == target)
        return true;
    }
    return false;
  }
}