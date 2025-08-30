#include <iostream>
#include <vector>

using namespace std;

vector<int> solution() {
    int n, k;
    int cntr_one = 0;
    int itr = 0; 
    cin >> n >> k;

    string bstr;
    cin >> bstr;
    vector<bool> s(n);

    for (auto &a : bstr) {
        s[itr] = (a == '1'); 
        if (s[itr] == 1) {
            ++cntr_one; 
           } 
        else {
            cntr_one = 0;
        }
        ++itr;
        if (cntr_one >= k) {vector<int> n(1, -1); return n;}
    }
 
    
    itr = 1;
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {if (s[i] == 1) {res[i] = itr; ++itr;}}
    for (int i = 0; i < n; ++i) {if (s[i] == 0) {res[i] = itr; ++itr;}}
    
    return res;
    
    
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t -- > 0) {
        vector<int> v;
        v = solution();
        if (v[0] == -1) cout << "no" << "\n";
        else { cout << "yes" << "\n"; for (auto &a : v) cout << a << " "; cout << "\n";}
    }
}