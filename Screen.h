#pragma once
#include <string>
class Screen {
    private:
    std::string displayBuffer;
    public:
        void write(std:: string& value);
        std::string getOutput();
        void clear();
};