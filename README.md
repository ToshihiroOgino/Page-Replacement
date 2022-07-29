# Page Replacement

## コンパイル

すべてのソースファイルを一括で指定してg++でコンパイルする。

```
g++ *.cpp -o page-replacement
```

## 実行

コンパイルで生成されたものをターミナル上で実行する。
このとき、コマンドライン引数を何でもいいので、1つ以上つけるとデバッグモードが有効になる。

```
# デバッグモード 無効
page-replacement
# デバッグモード 有効
page-replacement arg
```

## デバッグログ

```
# 形式
クロック:参照ページ ページフォルト発生(O or X) page_table[0](page_info[0]), page_table[1](page_info[1]), page_table[2](page_info[2]), page_table[3](page_info[3]), page_table[4](page_info[4]), page_table[5](page_info[5]), page_table[6](page_info[6]), page_table[7](page_info[7]), page_table[8](page_info[8])
```
```
# 例
   1:Z O Z(1), NULL, NULL, NULL, NULL, NULL, NULL, NULL
```