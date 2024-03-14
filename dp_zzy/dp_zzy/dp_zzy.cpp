#include <iostream>
#include <vector>
#include <algorithm>/*max函数所在头文件*/
#include <cstring>

#define quickio ios::sync_with_stdio,cin.tie(0),cout.tie(0);

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


//class Solution {
//public:
//    int count = 0;
//    void backtracking(vector<int>& nums, int target, int sum, int startindex)
//    {
//        int i;
//
//        /*后面可以继续减，不可返回啊！！！！！*/
//        // if (sum > target)
//        //     return;
//
//        //终止条件
//        if (startindex == nums.size())
//        {
//            if (sum == target)
//            {
//                count++;
//            }
//
//            return;
//        }
//
//        //单层逻辑
//        for (i = startindex/*不能是0啊！！！！！！*/; i < nums.size(); i++)
//        {
//            backtracking(nums, target, sum + nums[i], i + 1);
//
//            backtracking(nums, target, sum - nums[i], i + 1);
//        }
//        return;
//    }
//
//    int findTargetSumWays(vector<int>& nums, int target)
//    {
//        if (nums.size() == 0)
//            return 0;
//        if (nums.size() == 1 && (nums[0] == target || nums[0] == -target))
//            return 1;
//
//        backtracking(nums, target, 0, 0);
//        return count;
//    }
//};
//
//int main()
//{
//    int a[] = { 1,1,1,1,1 };
//    vector<int>b(a, a + sizeof(a) / sizeof(a[0]));
//    int target = 3;
//
//    Solution A;
//    cout << A.findTargetSumWays(b, target) << endl;
//
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
//        scanf("%d%d", &w[i], &v[i]);
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
//    printf("%d\n", dp[V]);
//    return 0;
//}


////01背包-人文传说
//const int vn = 1e4 + 5;
//const int wn = 1e4 + 5;
//
////确定dp数组含义
//int n, s, v[vn] = { 0 }, w[wn] = { 0 }, i, j, dp[wn] = { 0 };//dp[i]:当容量为i时可拿到的最大价值
//
//
//int main()
//{
//	quickio;
//
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		memset(dp, 0, sizeof dp);
//		cin >> n >> s;
//
//		for (i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		for (i = 0; i < n; i++)
//		{
//			cin >> w[i];
//		}
//
//		//初始化
//
//		for (i = 0; i < n; i++)//物品
//		{
//			for (j = s; j >= w[i]; j--)
//			{
//				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//			}
//		}	
//		printf("%d\n", dp[s]);
//	}
//
//
//	return 0;
//}


////P1802 5 倍经验日
////https://www.luogu.com.cn/problem/P1802
//
////两种情况：成功或者失败
////成功：max(dp[j - use[i]] + win[i], dp[j] + lose[i]);
////失败：dp[j] + lose[i]
//
///*一维*/
//
//const int MAX = 1005;
//
//int lose[MAX], win[MAX], use[MAX];
//
//int main()
//{
//	quickio;//快速输入
//
//	int n, x;
//	cin >> n >> x;
//
//	//dp[i]:最大可获得的经验
//	//经验：value
//	//数量：weight
//
//	long long dp[MAX] = { 0 };/*注意开long long*/
//	int i, j;
//
//	for (i = 0; i < n; i++)
//	{
//		cin >> lose[i] >> win[i] >> use[i];
//	}
//
//	for (i = 0; i < n; i++)//要打的人
//	{
//		for (j = x; j >= 0; j--)
//		{
//			if (j < use[i])
//				dp[j] = dp[j] + lose[i];
//			else
//				dp[j] = max(dp[j - use[i]] + win[i], dp[j] + lose[i]);
//		}
//	}
//
//	cout << 5 * dp[x] << endl;
//
//	return 0;
//}
//

////   完全   与01背包的区别：可以调换物品和背包的内外循环，j可正序可逆序
//
//
////P1776 宝物筛选
////https://www.luogu.com.cn/problem/P1776
//
////多重背包秒了~~~~~
////化为01背包就好
//
//const int MAX = 1e5 + 5;
//int v[MAX], w[MAX], m[MAX];
//int dp[MAX];
//
//int main()
//{
//	quickio;
//	int n, W;
//	cin >> n >> W;
//
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cin >> v[i] >> w[i] >> m[i];
//	}
//
//	int j, k;
//	for (i = 0; i < n; i++)//物品
//	{
//		for (j = W; j >= w[i]; j--)//背包容量
//		{
//			//超时
//			//for (k = 0; k < m[i]; k++)//物品的数量
//
//			//剪枝
//			for (k = 1; k <= m[i] && j - k * w[i] >= 0; k++)//物品的数量
//			{
//				dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
//			}
//		}
//	}
//
//	cout << dp[W] << endl;
//	return 0;
//}


////Cut Ribbon
////https://www.luogu.com.cn/problem/CF189A
//
//int main()
//{
//	quickio;
//
//	int n, a, b, c;
//	cin >> n >> a >> b >> c;
//
//
//	return 0;
//}


////01-背包周超人唯一的遗憾
//
////背包：距离天亮的时间
////物品：歌曲的时间
////因为最多只能放一遍----->01背包
//
////Runtime Error on test 2不是超时
//
//#include <climits>
//const int MAX = 20005;
//
//int main()
//{
//	quickio;
//
//	int V;
//	cin >> V;
//
//	int n, t[35] = { 0 }, dp[MAX] = { 0 };
//	cin >> n;
//
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cin >> t[i];
//	}
//
//
//	int j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = V; j >= t[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - t[i]] + t[i]);
//		}
//	}
//
//	cout << V - dp[V] << endl;
//	return 0;
//}



////L-天资聪颖的欧方哥哥
//
////t:背包
////m：物品
//
//int main()
//{
//	quickio;
//
//	int T, m;
//	cin >> T >> m;
//
//	int i, t[105] = { 0 }, v[105] = { 0 };
//	int dp[1005] = { 0 };
//	for (i = 0; i < m; i++)
//	{
//		cin >> t[i] >> v[i];
//	}
//
//	int j;
//	for (i = 0; i < m; i++)
//	{
//		for (j = T; j >= t[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
//		}
//	}
//
//	cout << dp[T] << endl;
//	return 0;
//}

////H-最长公共子序列:不要连续-----LCS
////最长公共子串：要连续
//
////模板题
////i:遍历s1的字母
////j:遍历s2的字母
//
////dp[i][j]:到该位置时最长的公共子序列
//
//#include <cstring>
//
//const int R = 1005;//行
//const int C = 1005;//列
//int dp[R][C];
//
//int main()
//{
//	quickio;
//
//	string s1;
//	string s2;
//	int i, j, len1, len2;
//	while (cin >> s1 >> s2)
//	{
//		len1 = s1.size();
//		len2 = s2.size();
//
//		for (i = 1; i <= len1; i++)
//		{
//			for (j = 1; j <= len2; j++)
//			{
//				if (s1[i - 1] == s2[j - 1])
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				else
//					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//
//		cout << dp[len1][len2] << endl;
//	}
//
//	return 0;
//}


////P1095 [NOIP2007 普及组] 守望者的逃离
////https://www.luogu.com.cn/problem/P1095
//
////逃出的条件：剩余时间内走的距离 > S
//
////恢复要3秒，不用技能3秒走51，用技能三秒走34+60
////能闪就闪，同时比较闪和原速度哪个快----->>贪心的思路
//
///*
//题解：https://blog.csdn.net/qq_35855297/article/details/52331942?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171033739316800215075491%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171033739316800215075491&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-52331942-null-null.142^v99^pc_search_result_base3&utm_term=%E5%AE%88%E6%9C%9B%E8%80%85%E7%9A%84%E9%80%83%E7%A6%BB&spm=1018.2226.3001.4187
//*/
//
////法一：动态规划
////先全闪，再进行一次循环，比较同一时间时s+=17和dp[i]的大小
//
//const int MAX = 3e5 + 5;
//int dp[MAX];
//
//int main()
//{
//	int M, S, T;
//	cin >> M >> S >> T;
//
//	int i, sum;
//	for (i = 1; i <= T; i++)//时间
//	{
//		if (M >= 10)
//		{
//			dp[i] = dp[i - 1] + 60;
//			M -= 10;
//		}
//		else
//		{
//			M += 4;
//			dp[i] = dp[i - 1];
//		}
//	}
//
//	for (i = 1; i <= T; i++)
//	{
//		dp[i] = max(dp[i], dp[i-1] + 17);
//		if (dp[i] >= S)
//		{
//			cout << "Yes" << endl;
//			cout << i << endl;
//			return 0;
//		}
//	}
//	cout << "No" << endl;
//	cout << dp[T] << endl;
//	
//	return 0;
//}


//法二：贪心

//int main()
//{
//	int M, S, T;
//	cin >> M >> S >> T;
//
//	int i, a = 0, b = 0;
//	for (i = 1; i <= T; i++)//时间
//	{
//		a += 17;
//		if (M >= 10)
//		{
//			b += 60;
//			M -= 10;
//		}
//		else
//		{
//			M += 4;
//		}
//
//		a = max(a, b);
//
//		if (a >= S)
//		{
//			cout << "Yes" << endl << i << endl;
//			return 0;
//		}
//	}
//	cout << "No" << endl << a << endl;
//	return 0;
//}

//
////F - 递推-A+B Problem
//
//int main()
//{
//
//	return 0;
//}


//G - 递推-天天AK的周大人

//const int MAX = 1e6 + 5;
//int a[MAX] = { 0 }, b[MAX];
//
//int main()
//{
//	int n;
//	cin >> n;
//	int i;
//
//	for (i = 0; i < n; i++)
//	{
//		cin >> a[i] >> b[i];
//	}
//
//
//	return 0;
//}


////Cut Ribbon
////https://www.luogu.com.cn/problem/CF189A
//
////完全  背包问题
////一长度为n的缎带，要求将其剪成若干长度为a,b,c的缎带，且缎带数量尽可能多。
////一容量为n的背包，有体积为a, b, c的三个物体，请问怎么放使得价值最大
//
////完全背包问题和01背包的区别：完全背包遍历物品时可以顺序也可以逆序
//
//#include <cstring>
//
//int main()
//{
//	int n, v[3];
//	cin >> n >> v[0] >> v[1] >> v[2];//a, b, c
//	int i, j;
//
//	int dp[4005] = { 0 };//容量为i时存可放的最大数量
//	memset(dp, -1, sizeof(dp));//cstring头文件
//
//	dp[0] = 0;//容量为1的背包最多放0个
//	/**/
//
//	for (i = 0; i < 3; i++)//物品：a, b, c
//	{
//		for (j = v[i]; j <= n; j++)//背包
//		{
//			if (dp[j - v[i]] != -1)/**/
//				dp[j] = max(dp[j], dp[j - v[i]] + 1);
//		}
//	}
//
//	cout << dp[n] << endl;
//	return 0;
//}