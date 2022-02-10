#include <filesystem>
#include <fstream>
#include <iostream>

std::string StrToLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char  c){return std::tolower(c);});

    return str;
}

int main()
{
    std::string dirName;

    std::cout << "Enter Problem Name: ";
    std::cin >> dirName;

    std::filesystem::create_directory("./"+dirName);

    std::string path = "./"+dirName+"/";
    std::fstream problemFile;
    std::fstream makeFile;

    std::cout << path+StrToLower(dirName)+".cpp";

    problemFile.open(path+StrToLower(dirName)+".cpp", std::ios_base::out | std::ios_base::trunc);
    problemFile.close();

    makeFile.open(path+"MakeFile", std::ios_base::out | std::ios_base::trunc);
    if(makeFile.is_open())
    {
        makeFile << "CXXFLAGS=-std=c++17\n";
        makeFile << "\n" << StrToLower(dirName) << ":\n";
        makeFile << "\tg++ $(CXXFLAGS) -o $@ $@.cpp";
        makeFile.close();
    }
    else{makeFile.close();}
};