public class Cryptography {
  public long encrypt(int[] numbers) {
    long ans = 1;
    long min = Long.MAX_VALUE;

    for (int n : numbers) {
      ans *= n;
      min = Math.min(min, n);
    }

    return ans / min * (min + 1);
  }
}
