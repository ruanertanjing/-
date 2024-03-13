//#define _CRT_SECURE_NO_WARNINGS 1
//#define ll long long
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdbool.h>/**/

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

//
//#include <limits.h>
//
//int a[200005] = { 0 };
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
//    int n;
//    scanf("%d", &n);
//    int i;
//    for (i = 0; i < n; i++)
//        scanf("%d", &a[i]);
//
//    printf("%d\n", maxSubArray(a, n));
//    return 0;
//}


////6. 携带研究材料（第六期模拟笔试）
////https://kamacoder.com/problempage.php?pid=1046
//
///*01背包做法*/
//
///*法一：二维数组*/
//物品，背包顺序可调换，遍历顺序也可由前到后或者由后到前
//但是一般都是顺序，物品为外循环(i),背包为内循环(j)
///*dp[i][j]:在0到i的物品里面任意取，且所剩空间大小为j，则能携带的最大价值*/
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - room[i]] + value[i]);
//
///*
//3 4 
//1 3 4
//15 20 30
//*/
//
//int value[5005];//价值
//int room[5005];//所占空间
//
//int dp[5005][5005] = { 0 };
//
//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//int main()
//{
//    int m, n, i, j;
//    scanf("%d%d", &m, &n);
//
//    for (i = 0; i < m; i++)
//        scanf("%d", &room[i]);
//
//    for (i = 0; i < m; i++)
//        scanf("%d", &value[i]);
//
//
//    //初始化
//     注意价值为负的情况
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j <= n; j++)
//        {
//            dp[i][0] = 0;
//
//            if (i == 0)
//            {
//                if (j < room[0])
//                    dp[i][j] = 0;
//                else
//                    dp[i][j] = value[0];
//            }
//        }
//    }
//
//    //遍历
//    for (i = 1; i < m; i++)//遍历物品
//    {
//        for (j = 1; j <= n; j++)//遍历背包
//        {
//            if (j < room[i])/*不能少！！！！！！！！！！！！*/
//                dp[i][j] = dp[i - 1][j];
//            else
//                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - room[i]] + value[i]);
//        }
//    }
//
//    printf("%d\n", dp[m - 1][n]);
//
//    //printf("\n");
//
//    /*发现答案不对就打印数组*/
//    //for (i = 0; i < m; i++)
//    //{
//    //    for (j = 0; j <= n; j++)
//    //    {
//    //        printf("%d ", dp[i][j]);
//    //    }
//
//    //    printf("\n");
//    //}
//
//    return 0;
//}
//
//
///*法二：一维数组*/
////物品背包顺序不可调换，且背包要倒序遍历，防止重复放入
//
////dp[j] = max(dp[j/*注意是j，不是j-1*/], dp[j - room[i]] + value[i])
//
////dp[j]:容量为j时可放的最大价值
//
//int dp[5005] = { 0 };
//int room[5005] = { 0 };
//int value[5005] = { 0 };
//
//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//int main()
//{
//    int m, n, i, j;
//    scanf("%d%d", &m, &n);
//
//    for (i = 0; i < m; i++)
//        scanf("%d", &room[i]);
//
//    for (i = 0; i < m; i++)
//        scanf("%d", &value[i]);
//
//
//    //初始化
//    for (j = 0; j <= n; j++)
//    {
//        if (j < room[0])
//            dp[j] = 0;
//        else
//            dp[j] = value[0];
//    }
//
//    for (i = 1; i < m; i++)//物品
//    {
//        for (j = n; j >= 1; j--/*是-不是+，别根据习惯又写成+，越界访问*/)//背包
//        {
//            if (j < room[i])
//                dp[j] = dp[j];
//            else
//                dp[j] = max(dp[j], dp[j - room[i]] + value[i]);
//        }
//    }
//
//    printf("%d\n", dp[n]);
//    
//	return 0;
//}



//16. 分割等和子集
//https://leetcode.cn/problems/partition-equal-subset-sum/

/*法一：回溯：超时，但可以做出来*/

/*法二：01背包：
物品：每个数
价值：每个数
容量：sum/2
*/

/*二维*/

//int dp[205][20005] = { 0 };
//
//int maxm(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//bool canPartition(int* nums, int numsSize)
//{
//    int i, sum = 0, j, maxn = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        if (nums[i] > maxn)
//            maxn = nums[i];
//    }
//
//    if (sum % 2 == 1)
//        return false;
//
//    int target = sum / 2;
//
//    if (maxn > target)
//        return false;
//
//
//
//    for (j = 0; j <= numsSize; j++)
//    {
//        if (j < nums[0])
//            dp[0][j] = 0;
//        else
//            dp[0][j] = nums[0];
//    }
//
//    for (i = 1; i < numsSize; i++)
//    {
//        for (j = 1; j <= target; j++)
//        {
//            if (j < nums[i])
//                dp[i][j] = dp[i - 1][j];
//            else
//                dp[i][j] = maxm(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
//        }
//    }
//
//    //for (i = 0; i < numsSize; i++)
//    //{
//    //    for (j = 0; j <= target; j++)
//    //    {
//    //        printf("%d ", dp[i][j]);
//    //    }
//    //    printf("\n");
//    //}
//
//    if (dp[numsSize - 1][target] == target)
//        return true;
//
//    return false;
//}

///*一维*/
//// /*dp[j]:第j个位置能构成的最大和
//// dp[j] == j :第
//// */
////2,2,3,5
//
//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//bool canPartition(int* nums, int numsSize)
//{
//    int i, sum = 0, maxn = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        sum += nums[i];
//        if (nums[i] > maxn)
//        {
//            maxn = nums[i];
//        }
//    }
//
//    if (sum % 2 == 1)
//        return false;
//
//    int target = sum / 2;
//
//    if (maxn > target)
//        return false;
//
//    int dp[20005] = { 0 };
//
//    int j;
//    for (j = 0; j <= target; j++)
//    {
//        if (j < nums[0])
//            dp[j] = 0;
//        else
//            dp[j] = nums[0];
//    }
//
//    for (i = 1; i < numsSize; i++)
//    {
//        for (j = target; j >= 1; j--)
//        {
//            if (j < nums[i])
//                dp[j] = dp[j];
//            else
//                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//        }
//    }
//
//    if (dp[target] == target)
//        return true;
//
//    return false;
//
//}
//
//int main()
//{
//    int nums[] = { 2,2,3,5 };
//    int numssize = sizeof(nums) / sizeof(nums[0]);
//
//    if (canPartition(nums, numssize))
//        printf("true\n");
//    else
//        printf("false\n");
//    return 0;
//}


////52. 携带研究材料（第七期模拟笔试）
////https://kamacoder.com/problempage.php?pid=1052
//
////多重背包
////与01背包的区别就是：遍历背包和物品的内外循环都可交换，且从前往后遍历
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#define ll long long
//
//
//int w[10005] = { 0 };
//int v[10005] = { 0 };
//
//int max(int a, int b)
//{
//    return a > b ? a : b;
//}
//
//int main()
//{
//    int N, V;
//    scanf("%d%d", &N, &V);
//
//    int i, j;
//    for (i = 0; i < N; i++)
//    {
//        scanf("%d", &w[i]);
//    }
//    for (i = 0; i < N; i++)
//    {
//        scanf("%d", &v[i]);
//    }
//
//    int dp[10005] = { 0 };
//    for (i = 0; i < N; i++)//物品
//    {
//        for (j = w[i]; j <= V; j++)//背包
//        {
//            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//        }
//    }
//
//    printf("%d\n", dp[N]);
//    return 0;
//}



////P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles
////https://www.luogu.com.cn/problem/P1216
//
////回溯是暴搜，很可能超时
//
//#include <limits.h>
//
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int v[1000][1005] = { 0 };
//
////确定dp[i][j]的含义
//int dp[1000][1005] = { 0 };//存到该点的最大路径和
//
//int main()
//{
//	int r;
//	scanf("%d", &r);
//	int i, j;
//
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < i + 1; j++)//第I行有i个元素
//		{
//			scanf("%d", &v[i][j]);
//		}
//	}
//
//
//	////确定dp[i][j]的含义
//	//int dp[1000][1005] = { 0 };//存到该点的最大路径和
//
//	//递推公式：dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])
//	//注意第一行和第一列要初始化
//
//	//初始化
//	dp[0][0] = v[0][0];
//	for (i = 1; i < r; i++)
//		dp[i][0] = dp[i - 1][0] + v[i][0];
//
//	//遍历顺序:从上到下，从左到右
//	for (i = 1; i < r; i++)
//	{
//		for (j = 1; j < i + 1; j++)
//		{
//			dp[i][j] = max(dp[i - 1][j] + v[i][j], dp[i - 1][j - 1] + v[i][j]);
//		}
//	}
//
//	int maxn = INT_MIN;
//	for (j = 0; j < r; j++)
//	{
//		if (dp[r - 1][j] > maxn)
//			maxn = dp[r - 1][j];
//	}
//	printf("%d\n", maxn);
//	return 0;
//}