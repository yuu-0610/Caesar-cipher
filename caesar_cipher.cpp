#include <iostream>
#include "caesar_cipher.h"

/*
 * 関数名 : Encrypt
 * 機能   : 文字列をCaesar暗号でシフトし暗号化する
 * 引数   : text  - 入力文字列
 *          shift - シフト量
 * 戻り値 : なし（結果は標準出力に表示）
 */
void Encrypt(const std::string& text, int shift){
    //入力文字列をコピー
    std::string result{text};
    //文字列を1文字ずつ暗号化
    for(std::size_t i = 0; i < result.size(); ++i) {

        //大文字を暗号化
        if(result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = (result[i] - 'A' + shift) % 26 + 'A';
        //小文字を暗号化
        }else if(result[i] >= 'a' && result[i] <= 'z') {
        result[i] = (result[i] - 'a' + shift) % 26 + 'a';
        }
    }

    //暗号化された文字列を表示
    std::cout << "暗号化済み: = " << result << std::endl;
}