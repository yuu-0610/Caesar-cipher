#include <iostream>
#include <string>
#include <cctype>
#include "input.h"

/*
 * 関数名 : InputText
 * 機能   : ユーザーから文字列を入力する
 *          A～Z以外の文字が入力された場合は再入力させる
 * 引数   : なし
 * 戻り値 : 入力された文字列
 */
std::string InputText() {
    std::string text{""};
    bool isValid{false};

    // 正しい入力まで繰り返す
    while(!isValid){
        isValid = true;
        std::cout << "A～Z または a～z の文字を入力してください: ";
        std::getline(std::cin, text);

        // 空文字チェック
        if(text.empty()){
            std::cout << "エラー: A～Z または a～z の文字を入力してください" << std::endl;
            isValid = false;
            continue;
        }

        // 1文字ずつ確認
        for(std::size_t i{0}; i < text.length(); i++){
            char c{text[i]};

            // 大文字へ変換
            c = std::toupper(c);

            // A～Z以外をチェック
            if((c < 'A') || (c > 'Z')){
                std::cout << "エラー: A～Z または a～z の文字のみ入力してください" << std::endl;
                isValid = false;
                break;
            }
        }
    }
    return text;
}

int32_t InputNumber() {
    int32_t shift{0};
    bool isValid{false};

    while(!isValid) {
        std::cout << "シフト数を入力してください: ";
        std::cin >> shift;

        // 入力失敗チェック
        if(std::cin.fail()) {
            std::cout << "エラー: 整数を入力してください" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // 余計な文字チェック
        } else if(std::cin.get() != '\n') {
            std::cout << "エラー: 整数のみ入力してください" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            isValid = true;
        }
    }
    return shift;
}