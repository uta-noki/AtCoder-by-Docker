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

    vector<vector<int>> a(3,vector<int>(3,0));
    vector<vector<bool>> check(3,vector<bool>(3,false));
    rep(i,0,3) rep(j,0,3) cin >> a.at(i).at(j);
    int n;
    cin >> n;
    vector<int> b(n,0);
    rep(i,0,n) cin >> b.at(i);

    rep(i,0,3) {
        rep(j,0,3) {
            rep(k,0,n) {
                if (a.at(i).at(j)==b.at(k)) check.at(i).at(j) = true;
            }
        }
    }
    bool ans = false;

    rep(i,0,3) {
        bool check_i = true;
        rep(j,0,3) {
            if (!check.at(i).at(j)) check_i = false;
        }
        if (check_i) ans = true;
    }

    rep(j,0,3) {
        bool check_j = true;
        rep(i,0,3) {
            if (!check.at(i).at(j)) check_j = false;
        }
        if (check_j) ans = true;
    }

    bool cross = true;
    rep(i,0,3) {
        if (!check.at(i).at(i)) cross = false;
    }
    if (cross) ans = true;
    
    cross = true;
    rep(i,0,3) {
        if (!check.at(2-i).at(i)) cross = false;
    }

    if (cross) ans = true;

    cout << (ans ? "Yes":"No") << "\n";

    return 0;
}