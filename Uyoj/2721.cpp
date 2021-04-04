#include <iostream>
#include <cmath>

using namespace std;

int n, k;
unsigned long long ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        ans = 0;
        while (k) {
            int p = int(log2(k));
            k -= int(pow(2, p));
            ans += (unsigned long long) pow(3, p);
        }
        cout << ans << endl;
    }
    return 0;
}