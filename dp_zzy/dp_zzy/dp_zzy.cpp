#include <iostream>
#include <vector>

using namespace std;

//94. Ŀ���
//https://leetcode.cn/problems/target-sum/

//���û���

/*��һ������*/
//ÿ�����޷����������+��-

/*���³�ʱ*/
// class Solution {
// public:
//     // vector<int> path;
//     int count = 0;
//     int num = 0;
//     void backtracking(vector<int>& nums, int target, int sum, int startindex)
//     {
//         int i;

//         /*������Լ����������ɷ��ذ�����������*/
//         // if (sum > target)
//         //     return;

//         //��ֹ����
//         if (num == nums.size())
//         {
//             if (sum == target)
//             {
//                 count++;
//             }

//             return;
//         }

//         //�����߼�
//         for (i = startindex/*������0��������������*/; i < nums.size(); i++)
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

        /*������Լ����������ɷ��ذ�����������*/
        // if (sum > target)
        //     return;

        //��ֹ����
        if (startindex == nums.size())
        {
            if (sum == target)
            {
                count++;
            }

            return;
        }

        //�����߼�
        for (i = startindex/*������0��������������*/; i < nums.size(); i++)
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