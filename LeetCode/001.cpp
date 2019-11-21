/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include "timer.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <map>



class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        return twoSum_v3(nums, target);
    }
    
    std::vector<int> twoSum_v1(std::vector<int>& nums, int target)
    {
        std::vector<int> ret;
        for (size_t i = 0; i != nums.size(); ++i)
        {
            for (size_t j = i+1; j != nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
        
        return {-1, -1};
    }
    
    std::vector<int> twoSum_v2(std::vector<int>& nums, int target)
    {
        std::map<int, int> hash;
        for (size_t i = 0; i != nums.size(); ++i)
        {
            hash[nums[i]] = i;
        }
        
        std::vector<int> ret;
        for (size_t i = 0; i != nums.size(); ++i)
        {
            auto dif = target - nums[i];
            if (hash.find(dif) != hash.end())
            {
                if (hash[dif] == i)
                    continue;
                    
                return {static_cast<int>(i), static_cast<int>(hash[dif])};
            }
        }
        
        return {-1, -1};
    }

    std::vector<int> twoSum_v3(std::vector<int>& nums, int target)
    {
        std::map<int, int> hash;
        for (size_t i = 0; i != nums.size(); ++i)
        {
            auto dif = target - nums[i];
            if (hash.find(dif) != hash.end())
            {
                if (hash[dif] == i)
                    continue;
                    
                return {static_cast<int>(hash[dif]), static_cast<int>(i)};
            }
            
            hash[nums[i]] = i;
            
        }
        
        return {-1, -1};
    }


};


int main(int, char* [])
{
    Solution s;
    
    {
        Timer t;
        std::vector<int> test1 = {2, 7, 11, 15};
        std::vector<int> solution1 = {0,1};
        assert(s.twoSum(test1, 9) == solution1);
        
        std::vector<int> test2 = {99, 3, 7, 11, 15};
        std::vector<int> solution2 = {0,4};
        assert(s.twoSum(test2, 114) == solution2);
        
        std::vector<int> test3 = {3, 4, 2};
        std::vector<int> solution3 = {1,2};
        assert(s.twoSum(test3, 6) == solution3);
        
        std::vector<int> test4 = {3, 3};
        std::vector<int> solution4 = {0, 1};
        assert(s.twoSum(test4, 6) == solution4);
    }
    
    return 0;
}
