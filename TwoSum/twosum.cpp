
#include <iostream>
#include <vector>

std::vector<int> twosum(std::vector<int>& nums, int target)
{
    std::vector<int> indices;

    // Naive Solution
    for(int i = 0; i < nums.size(); ++i)
    {
        int num1 = nums[i];
        
        if(num1 > target)
            continue;


        for(int j = 0; j < nums.size(); ++j)
        {
            if(j != i)
            {
                int num2 = nums[j];

                if(num2 > target)
                    continue;
                
                int sum = num1+num2;
                if(sum == target)
                {
                    indices.push_back(i);
                    indices.push_back(j);

                    return indices;
                }
            }
        };
    };

    return indices;
};

int main()
{
    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    std::vector<int> result = twosum(nums, target);

    for(int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << " ";
    }
};
