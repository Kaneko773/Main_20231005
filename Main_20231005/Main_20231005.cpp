﻿// Main_20231005.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "janken.h"
#include "kazuate.h"
using namespace std;

enum MODE {
    janken = 1,
    kazuate = 2,
    End = 3,
};

int main()
{
    int mode = 0;

    do{
        printf("1:じゃんけん　2:数当て　3:終了\n\n　＞　");
        cin >> mode;

        system("cls");
        switch (mode) {
        case janken: Janken(); break;
        case kazuate: Kazuate(); break;
        case End: cout << "\n終了しました" << endl;
        default: break;
        }
    } while (mode != 3);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
