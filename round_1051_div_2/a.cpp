#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define easycheck for (auto&a:v) cout << a; 

string sol() {
    int n;
    cin >> n;
    vector<int> v(n);       
    vector<int> pos(n+1); 

    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        v[i] = t;
        pos[t] = i;
    }

   
    int left = pos[n], right = pos[n];
    for (int val = n - 1; val >= 1; --val) {
        left = min(left, pos[val]);
        right = max(right, pos[val]);
        if (right - left + 1 != (n - val + 1)) return "no";
    }
    return "yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t-- > 0) {
        cout << sol() << "\n";
    }
}