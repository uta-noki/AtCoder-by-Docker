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

// ソート中の交換回数と交換された値を記録する関数
// int bubbleSortWithCount(vector<int>& arr) {
//     int n = arr.size();
//     int swapCount = 0;
    
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 // 値の交換
//                 swap(arr[j], arr[j + 1]);
//                 swapCount++;
//                 // 交換された値を表示
//                 cout << "Swapped: " << arr[j] << " and " << arr[j + 1] << endl;
//             }
//         }
//     }

//     return swapCount;
// }

int main() {

    int n, swaps=0;
    cin >> n;
    vector<int> a(n,0), pos(n,0);
    vector<pair<int,int>> ans;

    rep(i,0,n) {
      cin >> a.at(i);
      a.at(i)--;
      pos.at(a.at(i)) = i;
    }
    // rep(i,0,n) cout << pos.at(i) << " ";
    // cout << endl;

    // rep(i,0,n) cout << pos.at(i) << " ";
    rep(i,0,n) {
      if (a.at(i)!=i) {
        ans.push_back({i,pos.at(i)});
        pos.at(a.at(i)) = pos.at(i);
        a.at(pos.at(i)) = a.at(i);
        pos.at(i) = i;
        a.at(i) = i;
        // swap(pos.at(i),a.at(pos.at(i)));
        
        swaps++;
      }
    }

    // rep(i,0,n) {
    //   if (a.at(i)==i) continue;
    //   rep(j,i+1,n) {
        
    //     if (i==a.at(j)) {
    //       ans.push_back({j,a.at(i)});
    //       swap(a.at(i),a.at(j));
    //       swaps++;
    //     }
    //   }
    // }

    // rep(i,0,(int)ans.size()) if (ans.at(i).first==ans.at(i).second) swaps--;

    cout << swaps << "\n";
    rep(i,0,(int)ans.size()) {
      // if (ans.at(i).first==ans.at(i).second) continue;
      cout << ans.at(i).first+1 << " " << ans.at(i).second+1 << "\n";
    }

    

    return 0;
}