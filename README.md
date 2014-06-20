# ConoHaコマンド
===========

## このプログラムは？

実行するとConoHaがターミナル上に表示されます。

        _==:#####:==,
       -+#############,
      /######A########A
     |######V##########|
     |#   `.   .--''###|
     |# -ZB     -ABq|##|
     |E  `'      `' |##A     あなたの作業を見守るよ！
     |#`-__` -'   _/####|
      VaV##HhVVHhq/#=V|/'
       []'_/H||HHH'Hh,
        'HHVH||HHHHhVE
            H`'AHHA[] `A,
           /#########A  #A
            /_'  |  |   ##
           /#|   |##| _//'
            []  []/'

## 何のために作ったの？

https://twitter.com/MikumoConoHa/status/479824332743393280

## コンパイルはどうするの？必要な環境は？

LinuxとGCCがあればコンパイルできるはず。

CentOS6(64bit)のgcc(gcc version 4.4.7 20120313 (Red Hat 4.4.7-4) (GCC))にてコンパイルを確認しました。

``` Terminal
$ make
# make install
```

## どうやって実行するの？

``` Terminal
$ ConoHa
```

## 今後の予定は？

* Ctrl+Cなどに対する抵抗力をつける。
* configureとか用意する。
* ConoHaにセリフを喋らせる。
* ConoHaのAAを可愛くする。

## AAは誰が描いたの？

このプログラムの作者、Hirokiです。

イラストは http://www.conoha.jp/conoha の最下部にいるデフォルメConoHaを参考に頑張りました。
条件は以下の通りです。

* 半角英数字のみ
* プログラムに悪影響を及ぼす文字列は使わない。
    * " や \

Hiroki処女作のAAが気に入らないAAのプロを自称する方は、ぜひConoHaAA.txtへのプルリクをお願いします。
