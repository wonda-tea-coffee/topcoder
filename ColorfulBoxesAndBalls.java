public class ColorfulBoxesAndBalls {
  public int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
    int ans = Integer.MIN_VALUE;

    for (int x = Math.max(0, numRed - numBlue); x <= numRed; x++) {
      int y = numBlue - (numRed - x);
      int z = numRed + numBlue - x - y;
      int score = onlyRed * x + onlyBlue * y + bothColors * z;

      ans = Math.max(ans, score);
    }

    return ans;
  }
}