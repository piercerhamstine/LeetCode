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

int LengthLongestSubstring(std::string input)
{
        if(input.length() <= 0)
        {
            return 0;
        };
        
        int longestsslength = 0;

        const char* charArr = input.c_str();

        std::vector<std::string> subStrings;
        std::vector<char> uniqueChar;

        for(std::size_t i = 0; i < input.length(); ++i)
        {
            for(std::size_t j = i; j < input.length(); ++j)
            {

                if(isUnique(charArr[j], uniqueChar))
                {
                    uniqueChar.push_back(charArr[j]);
                }
                else
                {
                   break;
                };
            }
            subStrings.push_back(std::string(uniqueChar.begin(), uniqueChar.end()));
            uniqueChar.clear();
        };

        longestsslength = subStrings[0].length();
        for(std::size_t i = 0; i < subStrings.size(); ++i)
        {
            if(subStrings[i].length() > longestsslength)
            {
                longestsslength = subStrings[i].length();
            }
        };

        return longestsslength;
};

int main()
{
    std::cout << LengthLongestSubstring("") << std::endl;
};