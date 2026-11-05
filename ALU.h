#ifndef ALU_H
#define ALU_H

#include <string>

class ALU {
public:
    std::string addTwosComplement(std::string a, std::string b);
    std::string addFloatingPoint(std::string a, std::string b);
    std::string bitOr(std::string a, std::string b);
    std::string bitAnd(std::string a, std::string b);
    std::string bitXor(std::string a, std::string b);
    std::string rotateRight(std::string value, int steps);
    int hexToInt(std::string hex);
    std::string intToHex(int value);
};

#endif