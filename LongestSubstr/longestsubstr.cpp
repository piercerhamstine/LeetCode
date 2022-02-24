#include <iostream>
#include <string>
#include <vector>

bool isUnique(char c, std::vector<char>& chars)
{
    for(int i = 0; i < chars.size(); ++i)
    {
        if(chars[i] == c)
        {
            return false;
        }
    }

    return true;
}

int lengthOfLongestSubstring(std::string s)
{
    int longestsslength = 0;

    const char* charArr = s.c_str();

    std::vector<std::string> subStrings;
    std::vector<char> uniqueChar;

    for(int i = 0; i < s.length(); ++i)
    {

    };

    return longestsslength;
}

int main()
{
    lengthOfLongestSubstring("Fart");
}