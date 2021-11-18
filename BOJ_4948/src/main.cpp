#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int maxN = 123456 * 2 + 1;
    vb sieve(maxN + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    vi primes{};
    for (int i = 2; i <= maxN; ++i)
    {
        if (sieve[i]) {
            primes.push_back(i);

            int j{ i + i };
            while (j <= maxN) {
                sieve[j] = false;
                j += i;
            }
        }
    }

    int n;
    cin >> n;
    while (0 < n) {
        auto n2 = 2 * n;

        int count{ 0 };
        for (const auto& v : primes)
        {
            if (n < v && v <= n2) {
                count += 1;
            }

            if (n2 < v)
                break;
        }

        cout << count << '\n';
        cin >> n;
    }

    return 0;
}