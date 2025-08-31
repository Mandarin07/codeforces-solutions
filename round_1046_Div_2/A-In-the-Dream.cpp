#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int x, y;
        cin >> x >> y;
        // 1 к / 2 -  2 k > 3
        int z, w;
        cin >> z >> w;
        z -= x;
        w -= y;

        if (max(x,y) <= 2*(min(x,y) + 1) && max(z, w) <= 2*(min(z, w) + 1)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}