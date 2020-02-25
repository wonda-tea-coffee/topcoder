#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Cryptography
{
public:
  long long encrypt(vector<int> numbers)
  {
    sort(numbers.begin(), numbers.end());
    numbers.at(0)++;

    long long ans = 1;
    for (int n : numbers)
    {
      ans *= n;
    }
    return ans;
  }
};

int main()
{
  Cryptography *c = new Cryptography;
  vector<int> vec = {1, 3, 2, 1, 1, 3};
  cout << c->encrypt(vec) << endl;
}