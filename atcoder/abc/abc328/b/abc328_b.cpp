#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, start, n) for (int i = start; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 1次元，２次元ベクトルの簡略化
#define vi1 vector<int>
#define vll1 vector<ll>
#define vi2 vector<vector<int>>
#define vll2 vector<vector<ll>>
// 大きい値
const ll mod1 = 1000000007;
const double PI = 3.14159265358979;
const int INF = 2000000000;
// 10進数の格桁の和
int sum_digit(int n) {int ans = 0; while(n>0) { ans += n%10; n /= 10;} return ans;}
//　行列の 90 度回転
vi2 rotate(vi2 a) {vi2 na; int sz = a.size(); rep(i,0,sz) {rep(j,0,sz) na.at(i).at(j) = a.at(sz-1-j).at(i);} return na;}
// サイズNの文字列Sの回文のvectorを出力　o(N^2)
vector<string> Palindrome(string s) {
    vector<string> palindrome_vector; int n = s.size();
    rep(i,0,n) rep(j,i+1,n+1) {
            string s_i = s.substr(i,j-i); bool check = true;
            rep(k,0,(int)s_i.size()) if (s_i.at(k)!=s_i.at((int)s_i.size()-1-k)) check = false;
            if (check) palindrome_vector.push_back(s_i);
        }
    return palindrome_vector;
}

//　グリッド探索変数
vector<int> dj = {-1,0,1,-1,1,-1,0,1}, di = {-1,-1,-1,0,0,1,1,1};

int main() {

    int n, ans = 0;
    cin >> n;
    vector<int> d(n);
    rep(i,0,n) cin >> d.at(i);

    rep(i,0,n) {
        if (i+1==1 || i+1==11 || i+1==2 || i+1==22 || i+1==3 || i+1==33 || i+1==4 || i+1==44 || i+1==5 || i+1==55 || i+1==6 || i+1==66 || i+1==7 || i+1==77 || i+1==8 || i+1==88 || i+1==9 || i+1==99) {
            int md = (i+1)%10;
            rep(j,1,d.at(i)+1) {
                int d_j = j;
                bool check = true;
                while(d_j>0) {
                    if (md!=(d_j%10)) check = false;
                    d_j/=10;
                }
                if (check) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}