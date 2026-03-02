#include <iostream>
#include <string>
#include <cctype>
#include <clocale>

using namespace std;
    
    

string encrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + shift - 65) % 26 + 65);
        }
        else if (islower(text[i])) {
            result += char(int(text[i] + shift - 97) % 26 + 97);
        }
        else {
            result += text[i];
        }
    }
    return result;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - (shift % 26));
}

int main() {
    setlocale(LC_ALL, "Russian");
    string password;
    int shift_key = 5;

    cout << "=== Программа шифрования пароля (Шифр Цезаря) ===" << endl;
    cout << "Введите пароль для шифрования: ";
    cin >> password;

    string encrypted_password = encrypt(password, shift_key);
    cout << "Зашифрованный пароль: " << encrypted_password << endl;

    string decrypted_password = decrypt(encrypted_password, shift_key);
    cout << "Расшифрованный пароль: " << decrypted_password << endl;

    return 0;
}
