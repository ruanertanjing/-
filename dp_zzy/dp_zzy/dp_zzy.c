#define _CRT_SECURE_NO_WARNINGS 1
#define ll long long
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>/**/

//动态规划五部曲：dp数组，下标含义；公式；遍历顺序；初始化；打印数组

//斐波那契数列

//int fbnq(int a)
//{
//	if (a == 0 || a == 1)
//		return 1;
//	int dp[1000] = { 0 };
//	dp[0] = 1;
//	dp[1] = 1;
//
//	int i;
//	for (i = 2; i <= a - 1; i++)
//	{
//		dp[i] = dp[i - 1] + dp[i - 2];
//	}
//
//	return dp[a - 1];
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	while (n--)
//	{
//		int a;
//		scanf("%d", &a);
//
//		printf("%d\n", fbnq(a));
//	}
//	return 0;
//}


////数楼梯
////单纯写法只过了50%，要用到高精度，因为涉及到了两数相加，且阶梯范围大
////可用二维数组来模拟高精度
//// 题解：https://www.luogu.com.cn/article/mp47tiai
////dp[i] = dp[i-2] + dp[i-1]
//
//int board[5005][5005];
//int len = 1;
//
//void fun(int n)
//{
//	board[2][1] = 2;
//	board[1][1] = 1;
//
//	int i;
//	for (i = 1; i <= len; i++)
//	{
//		board[n][i] = board[n - 1][i] + board[n - 2][i];
//	}
//
//	for (i = 1; i <= len; i++)
//	{
//		if (board[n][i] >= 10)
//		{
//			board[n][i + 1] += board[n][i] / 10;
//			board[n][i] = board[n][i] % 10;
//			if (board[n][len + 1] != 0)
//			len++;
//		}
//	}
//
//	//int dp[5005] = { 0 };
//	//dp[1] = 1;
//	//dp[2] = 2;/*注意是2，不是1*/
//
//	//int i;
//	//for (i = 3; i <= n; i++)
//	//{
//	//	dp[i] = dp[i - 1] + dp[i - 2];
//	//}
//
//	////return dp[n];
//
//
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	if (n == 0 || n == 1 || n == 2)
//	{
//		printf("%d\n", n);
//		return 0;
//	}
//
//	int i;
//	for (i = 3; i <= n; i++)
//	{
//		fun(i);
//	}
//
//	for (i = len; i >= 1; i--)
//		printf("%d",board[n][i]);
//	return 0;
//}


////53. 最大子数组和
////https://leetcode.cn/problems/maximum-subarray/
//
////动态规划：dp, i的含义，遍历顺序，初始化，递推公式，打印数组
//
////想到了滑动窗口---->left, right--->没想出来解法
//
///*
//基本概念
//滑动窗口是一种基于双指针的一种思想，两个指针指向的元素之间形成一个窗口。
//
//分类：窗口有两类，一种是固定大小类的窗口，一类是大小动态变化的窗口。
//
//应用：
//
//利用滑动窗口获取平滑的数据，如一段连续时间的数据平均值，能够有更好的稳定性，如温度监测。
//
//什么情况可以用滑动窗口来解决实际问题呢？
//
//一般给出的数据结构是数组或者字符串
//求取某个子串或者子序列最长最短等最值问题或者求某个目标值时
//该问题本身可以通过暴力求解
//*/
//
///*
//https://blog.csdn.net/yjpeng125/article/details/120833365?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171007659016800226571331%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171007659016800226571331&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-120833365-null-null.142^v99^pc_search_result_base3&utm_term=%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3&spm=1018.2226.3001.4187
//*/
//
////dp[i]:以i为终点的最大子序列和
////dp[i] = max(dp[i-1] + nums[i], nums[i]);//取nums[i]的情况：dp[i-1]为负，nums[i]为正数
////因为与dp[i-1]有关，所以初始化的时候初始化dp[0]
//
//#include <limits.h>
//int maxSubArray(int* nums, int numsSize)
//{
//    int dp[100005] = { 0 };
//    int i;
//
//    dp[0] = nums[0];
//
//    for (i = 1; i < numsSize; i++)
//    {
//        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
//    }
//
//    int max = INT_MIN;
//
//    for (i = 0; i < numsSize; i++)
//    {
//        if (dp[i] > max)
//            max = dp[i];
//    }
//
//    return max;
//}
//
//
//int main()
//{
//    int a[] = {-1};
//
//    maxSubArray(a, sizeof(a) / sizeof(a[0]));
//    return 0;
//}


#include <limits.h>

int a[200005] = { 0 };
int maxSubArray(int* nums, int numsSize)
{
    int dp[100005] = { 0 };
    int i;

    dp[0] = nums[0];

    for (i = 1; i < numsSize; i++)
    {
        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
    }

    int max = INT_MIN;

    for (i = 0; i < numsSize; i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }

    return max;
}


int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%d\n", maxSubArray(a, n));
    return 0;
}


