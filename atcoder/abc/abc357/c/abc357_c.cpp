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
template<typename T>
vector<T> arrangeDivisor(T n) {
  vector<T> ret;
  for (T i = 1; i*i <= n; i++) {
    if (n%i == 0) {
      ret.push_back(i);
      if (i != n/i) ret.push_back(n/i);
    }
  }
  return ret;
}
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
            if (check) palindrome_vector.push_back(s_i);
        }
    return palindrome_vector;
}
ll div_ceil(ll a, ll b) {
  return (b >= 0 ? (a+b-1):a)/b;
}
//　グリッド探索変数
vector<int> dj = {-1,0,1,-1,1,-1,0,1}, di = {-1,-1,-1,0,0,1,1,1};

int main() {

    int n;
    cin >> n;
    // vector<vector<char>> n1 = {{'#','#','#'},{'#','.','#'},{'#','#','#'}};
    vector<vector<char>> n1 = {{'#','#','#'},{'#','.','#'},{'#','#','#'}};
    if (n==0) {cout << '#' << "\n"; return 0;}
    // if (n==1) {cout << n1 << "\n"; return 0;}

    map<int,vector<vector<char>>> mp;

    mp[0] = {{'.'}};
    mp[1] = n1;
    // rep(j,0,mp[1].size()) {
    //     rep(k,0,mp[1].size()) cout << mp[1].at(j).at(k);
    //     cout << endl;
    //   }
    int r_mx = 3, c_mx = 3;

    rep(i,2,7) {
      r_mx *= 3, c_mx *= 3;
      vector<vector<char>> ni(r_mx,vector<char>(c_mx));
      vector<vector<char>> sample = mp[i-1];
      rep(r,0,r_mx) {
        rep(c,0,c_mx) {
          // if (r/(r_mx/3)<=1 && r<=(int)pow(3,i-1)*2-1 && (int)pow(3,i-1)<=c && c<=(int)pow(3,i-1)*2-1) ni.at(r).at(c) = '.';
          if (r/(r_mx/3)==1 && c/(c_mx/3)==1) ni.at(r).at(c) = '.';
          else ni.at(r).at(c) = sample[r%((r_mx)/3)][c%(c_mx/3)];
        }
      }
      // rep(j,0,ni.at(0).size()) {
      //   rep(k,0,ni.at(0).size()) cout << ni.at(j).at(k);
      //   cout << endl;
      // }
      // cout << ni << "\n";
      mp[i] = ni;
    }

    vector<vector<char>> ans = mp[n];

    rep(i,0,ans.at(0).size()) {
      rep(j,0,ans.at(0).size()) cout << ans.at(i).at(j);
      cout << endl;
    }

    return 0;
}