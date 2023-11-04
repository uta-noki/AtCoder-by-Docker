### Docker サンプル など

- 勉強会用の Docker イメージをまとめておく場所

### 筆者の実行環境
端末: MacBook Pro

チップ: Apple M1

OS: macOS Ventura 13.5.2

---
### 要注意!!!
開催中のコンテストでは，始めに</br>
```oj login https://atcoder.jp/ -u username -p password```</br>
でログインする必要あり！！！

### 記事

[**Docker ってなんぞやという話 ~ Docker, Docker Compose のチュートリアル ~ VSCode の Remote Development まで**](https://qiita.com/tf63/items/684fe4b818ecd715aed9)

- `docs/docker.md`

[**Ubuntu で Docker のインストール**](https://qiita.com/tf63/items/c21549ba44224722f301)

- `docs/docker_install.md`

**Docker + Python の環境を作りたい**

- `docs/python.md`

[**AtCoder の環境を Docker で作りたい**](https://qiita.com/tf63/items/c93c6f24d73599e637d8)

- `docs/atcoder.md`



int n;
string s;
cin >> n >> s;

rep(i,n-1) {
    if ((s.at(i)=='a' && s.at(i+1)=='b' || s.at(i)=='b' && s.at(i+1)=='a')) {cout << "Yes" << "\n"; return 0;}
}
cout << "No" << "\n";