#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



int solution() {
    int n;
    cin >> n;

    if (n == 0) return 0;
    if (n == 1) {int a; cin >> a; if (a == 1) {return 1;} else {return 0;}}

    vector<int> v(n);
    int max_value{0};
    int value{0};
    int last_digit;
    int rest_of{0};
    int left{0};

    cin >> v[0];
    if (v[0] == 1) ++max_value;

    for (int i = 1; i < n; ++i) {
        cin >> v[i];

        max_value = max(value, max_value);

        if (last_digit != v[i-1] || rest_of <= 0) {rest_of = v[i-1];}
        last_digit = v[i-1];
        if (last_digit == v[i] ) {--rest_of; ++value;}
        else {rest_of = 0; value = 0; left = i;}
    }

    return max_value;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        cout << solution() << "\n";
    }
}