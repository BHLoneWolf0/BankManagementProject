#include "Headers/FileSystem.h"

void FileSystem::writeFileStr(std::string filename, const char* str) {
    std::ofstream file(filename);
    file << str;
    file.close();
}

void FileSystem::readFile(std::string filename, std::string& ReadBuffer) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        ReadBuffer += line + "\n";
    }
    file.close();
}