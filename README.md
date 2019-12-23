# 低レイヤを知りたい人のための C コンパイラ作成入門

https://www.sigbus.info/compilerbook#
を参考にしています

# Docker のシェル立ち上げ

docker run --rm -it -v /Users/"ユーザー名"/Documents/C/9cc:/9cc -w /9cc compilerbook

## ビルド

make

## テスト

make test

# VScode でデバッグ

`gcc -g 9cc.c`でビルド
launch.json 　で入力引数設定してから、デバッグする
