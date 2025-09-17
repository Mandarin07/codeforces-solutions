#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll sol() {
    int n , k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(k);

    for (auto &aa:a) cin >> aa;
    for (auto &bb:b) cin >> bb;

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    vector<long long> pref(n+1, 0);
    for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];

    
    ll ans = 0;
    ll u = 0;
    
    for (auto &bb: b) {
        if (u + bb > n) continue;
        ans += pref[u+bb-1] - pref[u];
        u += bb;
    }
    if (u <n) ans += pref[n] - pref[u];
        
    return ans;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t --> 0)
    {
        cout << sol() << "\n";
    }
    
    
    
}
