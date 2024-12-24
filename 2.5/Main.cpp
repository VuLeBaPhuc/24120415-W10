#include <iostream>
#include <string>
using namespace std;

// Hàm chuyển từ Decimal sang Binary
void decimalToBinary(unsigned int num) {
    if (num == 0) {
        cout << "0";
        return;
    }

    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    cout << binary;
}

// Hàm chuyển từ Decimal sang Hexadecimal
void decimalToHexadecimal(unsigned int num) {
    if (num == 0) {
        cout << "0";
        return;
    }

    string hex = "";
    const string hexDigits = "0123456789ABCDEF";
    while (num > 0) {
        hex = hexDigits[num % 16] + hex;
        num /= 16;
    }
    cout << hex;
}

// Hàm chuyển từ Binary sang Decimal
unsigned int binaryToDecimal(const string& binary) {
    unsigned int decimal = 0;
    unsigned int base = 1; // 2^0
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Hàm chuyển từ Hexadecimal sang Decimal
unsigned int hexadecimalToDecimal(const string& hex) {
    unsigned int decimal = 0;
    unsigned int base = 1; // 16^0
    const string hexDigits = "0123456789ABCDEF";
    for (int i = hex.size() - 1; i >= 0; --i) {
        int value = hexDigits.find(toupper(hex[i])); // Tìm giá trị của ký tự hex
        decimal += value * base;
        base *= 16;
    }
    return decimal;
}
