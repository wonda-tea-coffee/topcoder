public class ThePalindrome {
  public int find(String s) {
    String tail = "";
    int i = 0;

    while (!isReversible(s + tail)) {
      tail = (s.charAt(i) + "") + tail;
      i++;
    }

    return (s + tail).length();
  }

  public boolean isReversible(String s) {
    StringBuilder sb = new StringBuilder(s);
    return sb.reverse().toString().equals(s);
  }
}