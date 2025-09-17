#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

const int m = 1000000007;

void sol() {
     int n;
     cin >> n;
     vector<int> a(n);
     for (int i = 0; i < n; i++) cin >> a[i];
     
     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

     dp[0][0] = 1;

     int left{0};

     
     for (auto &v : a) {
         vector<vector<int>> ndp = dp; 
         
         for (int i = 0; i <= n; ++i) {
             for (int j = i; j <= n; ++j) {
                 int cur = dp[i][j];
                 if (!cur) continue;
                 
                 if (i == 0 || i <= v) {
                     int nx = v, ny = j;
                     if (nx > ny) swap(nx, ny);
                     
                     
                     ndp[nx][ny] = (ndp[nx][ny] + cur) % m;
                    }
                    
                    if (j == 0 || j <= v) {
                        int nx = i, ny = v;
                        if (nx > ny) swap(nx, ny);
                        
                        
                        ndp[nx][ny] = (ndp[nx][ny] + cur) % m;
                        
                    }
                }
                
            }
            //cout << ndp << "\n";
            
            
            dp.swap(ndp) ;
    }
        
     ll ans {0};
     for (int i= 0; i <= n; ++i) { for (int j = i; j <= n; ++j) {ans += dp[i][j]; if (ans >= m) ans -= m;} }
     cout << ans % m << "\n";
 
}
     
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t --> 0) {
        sol();
    }
       
}
