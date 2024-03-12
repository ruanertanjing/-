#include <iostream>
#include <vector>

using namespace std;

//94. 目标和
//https://leetcode.cn/problems/target-sum/

//可用回溯

/*法一：回溯*/
//每个数无非两种情况：+，-

/*以下超时*/
// class Solution {
// public:
//     // vector<int> path;
//     int count = 0;
//     int num = 0;
//     void backtracking(vector<int>& nums, int target, int sum, int startindex)
//     {
//         int i;

//         /*后面可以继续减，不可返回啊！！！！！*/
//         // if (sum > target)
//         //     return;

//         //终止条件
//         if (num == nums.size())
//         {
//             if (sum == target)
//             {
//                 count++;
//             }

//             return;
//         }

//         //单层逻辑
//         for (i = startindex/*不能是0啊！！！！！！*/; i < nums.size(); i++)
//         {
//             num++;
//             backtracking(nums, target, sum + nums[i], i + 1);
//             num--;

//             num++;
//             backtracking(nums, target, sum - nums[i], i + 1);
//             num--;
//         }
//         return;
//     }

//     int findTargetSumWays(vector<int>& nums, int target)
//     {
//         if (nums.size() == 0)
//             return 0;
//         if (nums.size() == 1 && (nums[0] == target || nums[0] == -target))
//             return 1;

//         backtracking(nums, target, 0, 0);
//         return count;
//     }
// };


class Solution {
public:
    int count = 0;
    void backtracking(vector<int>& nums, int target, int sum, int startindex)
    {
        int i;

        /*后面可以继续减，不可返回啊！！！！！*/
        // if (sum > target)
        //     return;

        //终止条件
        if (startindex == nums.size())
        {
            if (sum == target)
            {
                count++;
            }

            return;
        }

        //单层逻辑
        for (i = startindex/*不能是0啊！！！！！！*/; i < nums.size(); i++)
        {
            backtracking(nums, target, sum + nums[i], i + 1);

            backtracking(nums, target, sum - nums[i], i + 1);
        }
        return;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1 && (nums[0] == target || nums[0] == -target))
            return 1;

        backtracking(nums, target, 0, 0);
        return count;
    }
};

int main()
{
    int a[] = { 1,1,1,1,1 };
    vector<int>b(a, a + sizeof(a) / sizeof(a[0]));
    int target = 3;

    Solution A;
    cout << A.findTargetSumWays(b, target) << endl;

    return 0;
}