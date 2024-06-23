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
vector<int> dj = {0,-1,1,0}, di = {-1,0,0,1};

int main() {

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    
    vector<vector<int>> score(h,vector<int>(w,1));
    vector<vector<int>> graph(h*w);
    // vector<bool> visit_ij(h*w,false);
    vector<vector<bool>> visit_ij(h,vector<bool>(w,false));

    rep(i,0,h) cin >> s.at(i);

    // グラフを構築
    rep(i,0,h) {
      rep(j,0,w) {
        if (s.at(i).at(j)=='#') {
          // visit_ij.at(i).at(j) = true;
          continue;
        }
        bool is_not = true;
        rep(k,0,4) {
          int d_i, d_j;
          d_i = i+di.at(k), d_j = j+dj.at(k);
          if (d_i<0 || d_j<0 || d_i>=h || d_j>=w) continue;
          if (s.at(d_i).at(d_j)=='#') is_not = false;
          // visit_ij.at(i).at(j) = true;
        }
        if (!is_not) continue;
        rep(k,0,4) {
          int d_i, d_j;
          d_i = i+di.at(k), d_j = j+dj.at(k);
          if (d_i<0 || d_j<0 || d_i>=h || d_j>=w) continue;
          graph.at(i*w+j).push_back(d_i*w+d_j);
        }
      }
    }

    // rep(i,0,w*h) {
    //   cout << i << ": ";
    //   for (auto v:graph.at(i)) cout << v << " ";
    //   cout << endl;
    // }

    // rep(i,0,h*w) {
    //   // if (visit_ij.at(i).at(j)==true) continue;
    //   // vector<bool> visit(h*w,false);
    //   queue<int> que;
    //   // visit_ij.at(i) = true;
    //   que.push(i);
    //   // visit_ij.at(i) = true;
    //   set<int> cnt;
    //   vector<bool> visit(h*w,false);
    //   if (visit_ij.at(i)) continue;
    //   visit_ij.at(i) = true;
    //   // cnt.insert(i);
    //   // if (visit_ij.at(v/w).at(v%w)) continue;
    //   // if (visit_ij.at(v/w).at(v%w)) continue;
    //   while(!que.empty()) {
    //     int vi = que.front();
    //     que.pop();
    //     // if (visit_ij.at(vi)) continue;
    //     visit.at(vi) = true;
    //     if (visit_ij.at(visit.at(vi))) continue;
    //     cnt.insert(vi);
    //     for (auto hen:graph.at(vi)) {
    //       if (!visit.at(hen)) {
    //         visit.at(hen) = true;
    //         // if (visit_ij.at(hen)) break;
    //         visit_ij.at(hen) = true;
    //         que.push(hen);
    //         cnt.insert(hen);
    //       }
    //     }
    //   }
    //   // cout << i+1 << " :" << cnt.size() << "\n";
    //   score.at(i/w).at(i%w) = max(score.at(i/w).at(i%w),(int)cnt.size());
    //   // cout << score.at(i).at(j) << " ";
    // } 
    

    int ans = 0;
    // vector<int> visit(h*w,-1);
    rep(i,0,h) {
      rep(j,0,w) {
        if (visit_ij.at(i).at(j)) continue;
        // bool is_not = true;
        // rep(k,0,4) {
        //   int d_i, d_j;
        //   d_i = i+di.at(k), d_j = j+dj.at(k);
        //   if (d_i<0 || d_j<0 || d_i>=h || d_j>=w) continue;
        //   if (s.at(d_i).at(d_j)=='#') is_not = false;
        //   // visit_ij.at(i).at(j) = true;
        // }
        // if (!is_not) continue;
        // vector<bool> visit(h*w,false);
        queue<int> que;
        int v = i*w+j;
        // rep(ij,0,h*w) visit.at(ij) = false;
        // iota(visit.begin(),visit.end(),-1);
        // visit.at(v) = 1;
        que.push(v);
        visit_ij.at(i).at(j) = true;
        set<int> cnt;
        // int cnt = 1;
        // if (visit_ij.at(v/w).at(v%w)) continue;
        // if (visit_ij.at(v/w).at(v%w)) continue;
        while(!que.empty()) {
          int vi = que.front();
          que.pop();
          // visit_ij.at(vi/w).at(vi%w) = true;
          // cnt++;
          cnt.insert(vi);
          for (auto hen:graph.at(vi)) {
            bool is_not = true;
            rep(k,0,4) {
              int d_i, d_j;
              d_i = hen/w+di.at(k), d_j = hen%w+dj.at(k);
              if (d_i<0 || d_j<0 || d_i>=h || d_j>=w) continue;
              if (s.at(d_i).at(d_j)=='#') is_not = false;
              // visit_ij.at(i).at(j) = true;
            }
            if (!visit_ij.at(hen/w).at(hen%w) || !is_not) {
              // cnt++;
              // visit.at(hen) = 1;
              que.push(hen);
              cnt.insert(hen);
              visit_ij.at(hen/w).at(hen%w) = true;
            }
          }
        }
        // cout << cnt << " ";
        score.at(i).at(j) = max(score.at(i).at(j),(int)cnt.size());
        chmax(ans,score.at(i).at(j));
        // cout << score.at(i).at(j) << " ";
      } 
    }

    
    // rep(i,0,h) {
    //   rep(j,0,w) cout << score.at(i).at(j) << " ";
    //   cout << endl;
    // }

    // rep(i,0,h) rep(j,0,w) chmax(ans,score.at(i).at(j));

    cout << ans << "\n";

    return 0;
}