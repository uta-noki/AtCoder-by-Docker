### Docker サンプル など

- 勉強会用の Docker イメージをまとめておく場所

### 筆者の実行環境
端末: MacBook Pro

チップ: Apple M1

OS: macOS Ventura 13.5.2

---
### 要注意!!!
始めに</br>
```oj login https://atcoder.jp/ -u username -p password```</br>
でログインするのをわすれ

### 記事

[**Docker ってなんぞやという話 ~ Docker, Docker Compose のチュートリアル ~ VSCode の Remote Development まで**](https://qiita.com/tf63/items/684fe4b818ecd715aed9)

- `docs/docker.md`

[**Ubuntu で Docker のインストール**](https://qiita.com/tf63/items/c21549ba44224722f301)

- `docs/docker_install.md`

**Docker + Python の環境を作りたい**

- `docs/python.md`

[**AtCoder の環境を Docker で作りたい**](https://qiita.com/tf63/items/c93c6f24d73599e637d8)

- `docs/atcoder.md`
---
### 環境構築手順
### 0. 前提条件
   まずはdocker Desktopをインストールします．
### 1. プロジェクトをcloneする．
    ```git clone git@github.com:uta-noki/AtCoder-by-Docker.git```
### 2. docker-compose で Dockerfile から image をビルドする
   </br> ```docker-compose build```</br>
