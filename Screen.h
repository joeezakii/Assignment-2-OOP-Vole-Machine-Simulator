#pragma once
#include <string>
class Screen {
    private:
    std::string displayBuffer;
    public:
        void write(const std::string& value);
        std::string getOutput();
        void clear();
};