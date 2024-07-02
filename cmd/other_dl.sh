#! /bin/bash

### 引数はarc172みたいにに指定する

# example
# ----------------------------------------------------------------
# ./cmd/arc_dl arc172
# >>>> arcディレクトリ配下にarc172のworkspaceが作成される
# ----------------------------------------------------------------

if [ $# -ne 1 ]; then
    echo "number of argments should be 1"
    return 1
fi


WORKDIR="/app"
CONTEST_DIR="${WORKDIR}/atcoder/other"
PROBLEM_DIR="${CONTEST_DIR}/$1"
TEMPLATE="${WORKDIR}/templates/template.cpp"
# コンテストディレクトリが存在しなければ全てダウンロードする
if [ ! -d "$PROBLEM_DIR" ]; then
    mkdir -p $CONTEST_DIR
    cd $CONTEST_DIR
    acc new $1 -c all
    PROBLEMS="${PROBLEM_DIR}/*"
    for DIRPATH in $PROBLEMS; do
        if [ ! -d $DIRPATH ]; then
            continue
        fi

        cp -n $TEMPLATE "${DIRPATH}/$1_${DIRPATH##*/}.cpp"
    done
else
# テストディレクトリだけが存在しなければ，ダウンロードする
    mkdir -p "atcoder/other/$1/temp/"
    cd "atcoder/other/$1/temp/"
    acc new $1 -c all

    problems_list=("a" "b" "c" "d" "e" "f" "g" "h")
    for (( i=0; i<${#problems_list[@]}; i++ )); do
        if [ -d "$1/${problems_list[$i]}/tests" ]; then
            cp -r "$1/${problems_list[$i]}/tests" "../../$1/${problems_list[$i]}"
        fi
    done

    rm -r "../temp/"
fi
# ### arc172のフォルダを作成し，テストデータをダウンロードする
# mkdir -p $CONTEST_DIR
# cd $CONTEST_DIR
# acc new $1 -c all

# ### ダウンロードしたテストデータに対して，cppファイルを作成する
# PROBLEMS="${PROBLEM_DIR}/*"
# for DIRPATH in $PROBLEMS; do
#     if [ ! -d $DIRPATH ]; then
#         continue
#     fi

#     cp -n $TEMPLATE "${DIRPATH}/$1_${DIRPATH##*/}.cpp"
# done