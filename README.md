## 環境構築方法(初期 setup)

<br>

### 0. 前提条件: BackEnd-API の環境を構築済み

まずは、こちらの
[industryJudgement-backend-api](https://github.com/yukimura-manase/industryJudgement-backend-api)
が立ち上がっていることが前提になります。
<br>

### 1. プロジェクトを Clone

```bash
git clone git@github.com:yukimura-manase/industryJudgement-front.git
```

### 2. パッケージを install する

frontend ディレクトリに移動して、パッケージを install する

```bash
cd industryJudgement-front/frontend/ && yarn install
```

### 3. docker-compose で Dockerfile から image をビルドする

docker-compose build コマンドは、Docker ファイルから image を作成してくれるコマンドです。

```bash
docker-compose build
```

このコマンドを実行すると、Dockerfile に従って各サービスの Docker イメージがビルドされ、
<br/>
イメージ名とタグ名が作成されます。

<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Copy Button Example</title>
</head>
<body>
    <pre id="code">git clone https://github.com/your-repository.git</pre>
    <button onclick="copyToClipboard()">Copy</button>

    <script>
        function copyToClipboard() {
            var copyText = document.getElementById("code").innerText;
            var textArea = document.createElement("textarea");
            textArea.value = copyText;
            document.body.appendChild(textArea);
            textArea.select();
            document.execCommand("copy");
            document.body.removeChild(textArea);
            alert("Copied to clipboard!");
        }
    </script>
</body>
</html>

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
    git clone git@github.com:uta-noki/AtCoder-by-Docker.git　
### 2. docker-compose で Dockerfile から image をビルドする
   　　```bash
      docker-compose up --build
      ```
