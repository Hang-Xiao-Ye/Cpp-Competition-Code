#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1005;

int n, ans;
bool a[MAX][MAX], vis[MAX];
vector<int> from[MAX], to[MAX];

inline void spread(int i) {
    if (vis[i])
        return;
    vis[i] = true;

    for (auto k : to[i])
        spread(k);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];

            if (a[i][j]) {
                to[i].push_back(j);
                from[j].push_back(i);
            }
        }

    for (int i = 1; i <= n; i++)
        if (from[i].empty()) {
            ans++;
            spread(i);
        }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            ans++;
            spread(i);
        }

    cout << ans << endl;
    return 0;
}