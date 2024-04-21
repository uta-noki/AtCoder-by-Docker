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
vector<int> di = {-1,0,0,1}, dj = {0,-1,1,0};
// vector<int> dj = {-1,0,1,-1,1,-1,0,1}, di = {-1,-1,-1,0,0,1,1,1};

// abc348d問題の関数群
// ------------------------------------
// スタートとゴールの座標を返す関数
// template<typename T>
pair<int,int> position(vector<string> mp, char posi) {
  pair<int,int> pos = {0,0};
  int h = mp.size(), w = mp[0].size();
  rep(i,0,h) rep(j,0,w) if (mp.at(i).at(j)==posi) {
    pos.first = i;
    pos.second = j;
  }
  // 返り値: 座標の pair型
  return pos;
}

// スタートとゴールの薬のインデックスを求める
int goal_and_start_medi_num(vector<string> mp, vector<int> r, vector<int> c, char ch) {
  int h = mp.size(), w = mp[0].size(), sz = r.size();
  int index = 0;
  rep(i,0,h) rep(j,0,w) {
      if (mp.at(i).at(j)==ch) {
        rep(k,0,sz) if (r.at(k)==i && c.at(k)==j) index = k;
      }
  }
  return index;
}

// 特定の座標に薬があるか判定する関数
bool is_exist_medi(pair<int,int> pa, vector<int> r, vector<int> c) {
  int sz = r.size();
  bool check = false;
  rep(i,0,sz) if (r.at(i)==pa.first && c.at(i)==pa.second) check = true;
  return check;
}
// ------------------------------------

int main() {

    int h, w, n;
    cin >> h >> w;
    // vector<vector<char>> a(h,vector<char>(w,0));

    // 入力
    // ------------------------------------
    vector<string> a(h);
    rep(i,0,h) cin >> a.at(i);

    cin >> n;
    vector<int> r(n,0), c(n,0), e(n,0);

    rep(i,0,n) {
      cin >> r.at(i) >> c.at(i) >> e.at(i);
      r.at(i)--, c.at(i)--;
    }
    // ------------------------------------
    // スタートとゴールの座標を取得
    auto s_ij = position(a, 'S');
    auto t_ij = position(a, 'T');

    // スタート地点に薬がなければ追加する
    if (!is_exist_medi(s_ij, r, c)) {
      r.push_back(s_ij.first);
      c.push_back(s_ij.second);
      e.push_back(0);
    }

    // ゴール地点に薬がなければ追加する．
    if (!is_exist_medi(t_ij, r, c)) {
      r.push_back(t_ij.first);
      c.push_back(t_ij.second);
      e.push_back(0);
    }

    n = e.size();


    // ある薬から他の薬へ到達できるかを判定するして有向グラフを作る関数
    auto bfs1 = [&](vector<string> mp, int medi_i, int medi_j) {
      vector<vector<int>> dist(h,vector<int>(w,-1));
      queue<pair<int,int>> que;
      que.push({medi_i, medi_j});
      dist.at(medi_i).at(medi_j) = 0;
      while(!que.empty()) {
        auto pa_i = que.front();
        que.pop();
        rep(i,0,4) {
          int next_i = pa_i.first+di.at(i), next_j = pa_i.second+dj.at(i);
          if (next_i<0 || next_j<0 || next_i>=h || next_j>=w || mp.at(next_i).at(next_j)=='#' || dist.at(next_i).at(next_j)!=-1) continue;
          que.push({next_i,next_j});
          dist.at(next_i).at(next_j) = dist.at(pa_i.first).at(pa_i.second) + 1;
        }
      }
      return dist;
    };

    auto bfs2 = [&](vector<vector<int>> graph, int medi_num, int n) {
      vector<bool> visit(n,false);
      queue<int> que;
      que.push(medi_num);
      visit.at(medi_num) = true;
      while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto i:graph.at(v)) {
          if (!visit.at(i)) {
            visit.at(i) = true;
            que.push(i);
          }
        }
      }
      return visit;
    };

    // ある薬から到達可能な薬を示す有向グラフ
    vector<vector<int>> graph(n);

    rep(i,0,n) {
      auto to_medicine = bfs1(a, r.at(i), c.at(i));
      rep(j,0,n) {
        if (i==j) continue;
        if (to_medicine.at(r.at(j)).at(c.at(j))!=-1 && to_medicine.at(r.at(j)).at(c.at(j))<=e.at(i)) graph.at(i).push_back(j);
      }    
    }

    int goal = goal_and_start_medi_num(a, r, c, 'T');
    int start = goal_and_start_medi_num(a, r, c, 'S');
    vector<bool> visit = bfs2(graph, start, n);

    cout << (visit.at(goal) ? "Yes":"No") << "\n";

    return 0;
}
