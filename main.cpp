#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

std::string StrToLower(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char  c){return std::tolower(c);});

    return str;
}

const std::string defaultCPP = "#include <iostream>\n\nint main()\n{\n\n}";

void CreateCPP(std::fstream& problemFile, const std::string& path, const std::string& dirName)
{
    problemFile.open(path+StrToLower(dirName)+".cpp", std::ios_base::out | std::ios_base::trunc);
    if(problemFile.is_open())
    {
        problemFile << defaultCPP;
    }
    problemFile.close();
}

void CreateMake(std::fstream& makeFile, const std::string& path, const std::string& dirName)
{
    makeFile.open(path+"MakeFile", std::ios_base::out | std::ios_base::trunc);
    if(makeFile.is_open())
    {
        makeFile << "CXXFLAGS=-std=c++17\n";
        makeFile << "\n" << StrToLower(dirName) << ":\n";
        makeFile << "\tg++ -o $@ $@.cpp\n\t./$@";
        makeFile.close();
    }
    makeFile.close();
}

void CreateReadME(std::fstream& readmeFile, const std::string& path, const std::string& dirName, std::string& desc)
{
    readmeFile.open(path+"ReadMe", std::ios_base::out | std::ios_base::trunc);
    if(readmeFile.is_open())
    {
        readmeFile << desc;
    }
    readmeFile.close();
}

int main()
{
    // Folder name
    std::string dirName;
    // Folder Path
    std::string path;
    // Descrition of problem;
    std::string probDesc;
    // README File
    std::fstream readmeFile;
    // CPP File
    std::fstream problemFile;
    // MakeFile
    std::fstream makeFile;

    std::cout << "Enter Problem Name: ";
    std::cin >> dirName;
    std::cin.ignore();

    std::cout << "Enter Problem Description: ";
    std::getline(std::cin, probDesc, '\n');

    // Check if directory exists
    if(std::filesystem::is_directory("./"+dirName))
    {
        std::cout << "Directory already exists.";
    }
    else
    {
        std::filesystem::create_directory("./"+dirName);
        path = "./"+dirName+"/";

        CreateCPP(problemFile, path, dirName);

        CreateMake(makeFile, path, dirName);

        CreateReadME(readmeFile, path, dirName, probDesc);
    }
};