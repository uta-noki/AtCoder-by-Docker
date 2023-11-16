### Docker サンプル など

- 勉強会用の Docker イメージをまとめておく場所

### 筆者の実行環境
端末: MacBook Pro

チップ: Apple M1

OS: macOS Ventura 13.5.2

## 1. 簡単に環境構築🎶
### 1.1 githubからpullする．
```
git clone https://github.com/entry-dotcom/docker_for_mac.git
```

### 1.2. 作業ディレクトリ```workdir```に移動する．
```
cd workdir
```
ディレクトリ構成は以下の通り

```
 workdir
    .
    ├── .devcontainer
    │   └── devcontainer.json
    ├── .vscode
    │   ├── c_cpp_properties.json
    │   └── tasks.json
    ├── .cmd
    │   ├── abc_dl.sh
    │   └── arc_dl.sh
    ├── .docker
    │   └── atcoder
    │       └── Dockerfile
    ├── .docker-compose.yml
    ├── .src
    │   └── abc
    │       └── abc001
    │       arc
    │       └── arc001
    │     
    └── .templates
        ├── atcoder.cpp
        ├── template.cpp
        └── input.txt
```

### 1.3. docker imageをbuildしてcontainerを起動する．</br>
```
docker run -it --name {container_name} {image_name}
```

### 1.4. docker containerにattach
```
docker attach {container_name}
```

### 1.5. vscodeの拡張機能であるtask runnerをインストールする．

## 2. AtCoderのプログラミングから回答提出まで
### 2.1
### 2.2


---

### 参考リンク
dockerのあれこれについて参考にしました．
```https://qiita.com/kooohei/items/0e788a2ce8c30f9dba53```

### 記事

[**Docker ってなんぞやという話 ~ Docker, Docker Compose のチュートリアル ~ VSCode の Remote Development まで**](https://qiita.com/tf63/items/684fe4b818ecd715aed9)

- `docs/docker.md`

**Docker + Python の環境を作りたい**

- `docs/python.md`

[**AtCoder の環境を Docker で作りたい**](https://qiita.com/tf63/items/c93c6f24d73599e637d8)

- `docs/atcoder.md`

[**コマンドでDockerコンテナを停止・削除、イメージの削除をする**](https://qiita.com/shisama/items/48e2eaf1dc356568b0d7)