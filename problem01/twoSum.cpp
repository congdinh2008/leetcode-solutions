#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> newMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (newMap.count(target - nums[i]) && i != newMap[target - nums[i]])
            {
                result.push_back(newMap[target - nums[i]]);
                result.push_back(i);
                break;
            }
            else
            {
                newMap[nums[i]] = i;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(7);
    nums.push_back(19);
    nums.push_back(15);
    int target = 9;
    Solution s;
    vector<int> result = s.twoSum(nums, target);
    cout << "Index 1: " << result[0] << endl;
    cout << "Index 2: " << result[1] << endl;
    return 0;
}
