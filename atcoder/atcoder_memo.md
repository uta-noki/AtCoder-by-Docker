# AtCoderメモ
int型から英大文字への変換  
`(char)(num + 65)`

int型から英小文字への変換  
`(char)(num + 97)`

文字型からint数字への変換  
`(string)t-'0'`

# sortの比較関数
`vector<pair<int,int>>` 
上記データ構造にて，`first`にvalue,`second`にindexとして，valueの降順,valueが等しいものは，indexを昇順の`sort`は 
`sort(ans.begin(),ans.end(),`<br>
&emsp;`[](const pair<int,int> x,const pair<int,int> y)`<br>
&emsp;`{if (x.first!=y.first) return x.first>y.first;`<br>
&emsp;`return x.second<y.second;});` 
