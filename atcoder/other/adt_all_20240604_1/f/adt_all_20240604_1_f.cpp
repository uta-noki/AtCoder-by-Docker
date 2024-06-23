#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, start, n) for (int i = start; i < (int)(n); i++)
// お役立ち関数いろいろ
// 文字列を大文字に変換
string toUpper(string s) { transform(s.cbegin(), s.cend(), s.begin(), ::toupper); return s;}
// 文字列を小文字に変換
string toLower(string s) {transform(s.cbegin(), s.cend(), s.begin(), ::tolower); return s;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}
//　素数判定 返り値:bool
template<typename T>
bool isPrime(T n) {
  for (T i = 2; i*i <= n; i++) {
    if (n%i == 0) return false;
  }
  return n != 1;
}             
/**約数を列挙
 * Return array of divisors.
 *
 * eg. arrangeDivisor(12) -> [1, 12, 2, 6, 3, 4]
 */
// template<typename T>
// vector<T> arrangeDivisor(T n) {
//   vector<T> ret;
//   for (T i = 1; i*i <= n; i++) {
//     if (n%i == 0) {
//       ret. (i);
//       if (i != n/i) ret. (n/i);
//     }
//   }
//   return ret;
// }
// 素因数分解　返り値は約数のmap. eg. primeFactorize(30) -> [{2,2},{3,1},{5,1}] @return map<T, int> prime, count
template<typename T>
map<T, int> primeFactorize(T n) {
  map<T, int> ret;
  for (T i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}
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
            // if (check) palindrome_vector(s_i);
        }
    return palindrome_vector;
}
ll div_ceil(ll a, ll b) {
  return (b >= 0 ? (a+b-1):a)/b;
}
//　グリッド探索変数
vector<int> dj = {-1,0,1,-1,1,-1,0,1}, di = {-1,-1,-1,0,0,1,1,1};

int main() {

    int cnt = 0, not_disapointed = 0;
    vector<vector<int>> ci(3,vector<int>(3,0));
    vector<int> C(9,0), order(9,0);
    iota(order.begin(),order.end(),0);

    rep(i,0,3) rep(j,0,3) cin >> ci.at(i).at(j);
    rep(i,0,9) C.at(i) = ci.at(i/3).at(i%3);

    vector<vector<int>> ord = {
      {0,1,2},
      {3,4,5},
      {6,7,8},
      {0,3,6},
      {1,4,7},
      {2,5,8},
      {0,4,8},
      {2,4,6}
    };


    do {
      cnt++;
      bool disapoint = false;
      for (auto v:ord) {
        if (C.at(v.at(0))==C.at(v.at(1)) && C.at(v.at(0))!=C.at(v.at(2)) && order.at(v.at(0))<order.at(v.at(2)) && order.at(v.at(1))<order.at(v.at(2))) disapoint = true;
        if (C.at(v.at(0))==C.at(v.at(2)) && C.at(v.at(0))!=C.at(v.at(1)) && order.at(v.at(0))<order.at(v.at(1)) && order.at(v.at(2))<order.at(v.at(1))) disapoint = true;
        if (C.at(v.at(1))==C.at(v.at(2)) && C.at(v.at(0))!=C.at(v.at(2)) && order.at(v.at(1))<order.at(v.at(0)) && order.at(v.at(2))<order.at(v.at(0))) disapoint = true;
      }
      if (!disapoint) not_disapointed++;


    } while (next_permutation(order.begin(),order.end()));

    cout << setprecision(20) << (double)not_disapointed/cnt << "\n"; 

    
    return 0;
}