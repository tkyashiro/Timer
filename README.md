# Timer

## CMake関連
-  ビルド
    - `make all`
- テスト実行
    - `make test`

## ファイルの追加
1. ファイル(.cppまたは.hファイル)を作成
1. CMakeLists.txt の`PTimer_SOURCES` に作製したファイルを追加

## テストの追加
1. ファイル(.cpp)ファイルを作製
1. CMakeLists.txt の`testfiles` に作製したファイルを追加
1. .cpp ファイルには下記のもの(おまじない)を追加する。
    1. `QObject`継承したクラス
        1. `Q_OBEJCT` マクロが必要
    1. `QTEST_APPLESS_MAIN(testclassname)` をファイルの最後あたりに追加
    1. `#include "filename.moc"` をファイルの最後に追加

