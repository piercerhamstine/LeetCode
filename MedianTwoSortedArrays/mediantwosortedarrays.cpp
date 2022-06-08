#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/* 
Median of even set:
m = (x((n/2) - 1) + x(n/2) / 2)

Median of odd set:
m = x(n/2 - 1)
*/

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // Make sure the two vectors are not empty.
    if(nums1.size() <= 0 && nums2.size() <= 0)
        return -1;

    // Create a new vector, resize it to the length of n1+n2.
    std::vector<int> merged;
    merged.resize(nums1.size() + nums2.size());

    // Merge the two sorted array together, place result into the new merged vector.
    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

    // Handle the case of the vector only having one input.
    if(merged.size() == 1)
        return merged[0];

    int size = merged.size();
    // Determine the parity of the new vector's size.
    // Even
    if(size % 2 == 0)
    {
        int ndx1 = ((size)/2) - 1;
        int ndx2 = (size)/2;
    
        double median = (merged[ndx1] + merged[ndx2])/2.0f;

        return median;
    }
    // Odd
    else
    {
        int ndx = ((size+1)/2) - 1;

        double median = merged[ndx];

        return median;
    };

    return 0;
};

int main()
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    std::cout << "Median: " << findMedianSortedArrays(v1,v2) << std::endl;
}   