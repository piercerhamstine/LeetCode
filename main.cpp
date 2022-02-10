#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
    std::string dirName;
    std::string path;

    std::cout << "Enter Problem Name: ";
    std::cin >> dirName;

    path = "./"+dirName;
    
    std::filesystem::create_directory(path);
};