#include "ALU.h"
#include <sstream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <cstdint>


int ALU::hexToInt(std::string hex) {
    int value;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> value;
    return value;
}

std::string ALU::intToHex(int value) {
    value &= 0xFFFF;
    std::stringstream ss;
    ss << std::uppercase << std::hex << std::setw(4) << std::setfill('0') << value;
    return ss.str();
}

std::string ALU::addTwosComplement(std::string a, std::string b) {
    int valA = hexToInt(a);
    int valB = hexToInt(b);
    int sum = valA + valB;
    return intToHex(sum);
}

std::string ALU::bitOr(std::string a, std::string b) {
    int valA = hexToInt(a);
    int valB = hexToInt(b);
    return intToHex(valA | valB);
}

std::string ALU::bitAnd(std::string a, std::string b) {
    int valA = hexToInt(a);
    int valB = hexToInt(b);
    return intToHex(valA & valB);
}

std::string ALU::bitXor(std::string a, std::string b) {
    int valA = hexToInt(a);
    int valB = hexToInt(b);
    return intToHex(valA ^ valB);
}

std::string ALU::rotateRight(std::string valueStr, int steps) {
    int val = hexToInt(valueStr);
    steps %= 16;
    int rotated = (val >> steps) | (val << (16 - steps));
    return intToHex(rotated);
}

std::string ALU::addFloatingPoint(std::string a, std::string b) {
    auto decodeFloat = [](unsigned short hexVal) -> double {
        int sign = (hexVal >> 7) & 0x1;
        int exp = (hexVal >> 4) & 0x7;
        int mantissa = hexVal & 0xF;
        double fraction = 1.0 + (double)mantissa / 16.0;
        double val = fraction * std::pow(2.0, exp - 4);
        return sign ? -val : val;
    };

    auto encodeFloat = [](double val) -> unsigned short {
        if (val == 0) return 0;
        int sign = val < 0 ? 1 : 0;
        val = std::abs(val);
        int exp = 0;
        while (val >= 2.0 && exp < 7) { val /= 2.0; exp++; }
        while (val < 1.0 && exp > 0) { val *= 2.0; exp--; }
        int mantissa = (int)std::round((val - 1.0) * 16.0);
        if (mantissa > 15) { mantissa = 15; exp++; }
        return (sign << 7) | ((exp & 0x7) << 4) | (mantissa & 0xF);
    };
    unsigned short valA = hexToInt(a) & 0xFF;
    unsigned short valB = hexToInt(b) & 0xFF;
    double decodedA = decodeFloat(valA);
    double decodedB = decodeFloat(valB);
    double result = decodedA + decodedB;
    unsigned short encodedRes = encodeFloat(result);
    return intToHex(encodedRes);
}