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


////P1832 A+B Problem（再升级）
////https://www.luogu.com.cn/problem/P1832
//
////需要先把素数求出来（欧拉筛），再计算总数：一般计算总数都是两dp相加得到新的dp答案
//
////欧拉筛：要book[MAX]:记录哪些不是素数，要prime[MAX]:记录素数，h:记录素数的个数
//
///*完全背包：把每个素数看成物品，dp[i]的i看成背包，每个物品可以拿无限次*/
//int prime[1005], book[1005], h = 0;
//
//void isprime(int max)//max:最大记录到哪
//{
//	book[0] = 1;
//	book[1] = 1;
//
//	int i, j;
//	for (i = 2; i <= max; i++)//遍历数，所以从2开始
//	{
//		if (book[i] == 0)
//			prime[h++] = i;
//
//		for (j = 0; j < h; j++)
//		{
//			if (prime[j] * i <= max)
//				book[prime[j] * i] = 1;
//			else
//				break;
//
//			if (i % prime[j] == 0)
//				break;
//		}
//
//	}
//}
//
//int main()
//{
//	quickio;
//	int n;
//	cin >> n;
//
//	if (n == 0 || n == 1)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//
//	//求素数
//	isprime(n);
//
//	long long/*注意是long long，因为数据可能很大，它求的是总数量*/ dp[1005] = {0}, i, j;//dp:记录每个数的方案总数
//	dp[0] = 1;//dp[0]值为1：好像不好解释，就理解成，不然单个质数的方案数就不能等于1了；
//	什么也不取也是一种方案
// for (i = 0; i < h; i++)//遍历物品（素数）
//	{
//		for (j = prime[i]; j <= n; j++)//遍历背包，j:表示数
//		{
//			//if (book[j - prime[i]] == 0)：因为虽然不是素数，也可以用素数构成
//				dp[j] += dp[j - prime[i]];
//		}
//	}
//	cout << dp[n] << endl;
//	return 0;
//}


////G - 递推-天天AK的周大人
//
////无重叠区间问题：435（力扣），贪心
////线段覆盖
//
////#include <map>
////
////multimap<int, int>mymap;//因为unordered_map不可排序，multimap和map会排序，而multimap可以出现重复数据
//
//#include <vector>
//
////vector<vector<int> >vec;
////
////bool cmp(vector<int>& a, vector<int>& b)
////{
////	return a[0] < b[0];
////}
//
//const int MAX = 1e6 + 5;
//
//struct m
//{
//	int a;
//	int b;
//}x[MAX];
//
//bool cmp(struct m x, struct m y)
//{
//	return x.a < y.a;
//}
//
//int main()
//{
//	int n, i;
//	cin >> n;
//
//	if (n == 0 || n == 1)
//	{
//		cout << n << endl;
//		return 0;
//	}
//	int a, b;
//	for (i = 0; i < n; i++)
//	{
//		cin >> x[i].a >> x[i].b;
//
//		//vec.push_back({ a,b });
//		//mymap.insert(pair<int, int>(a, b));/*注意用法*/
//	}
//	//sort(vec.begin(), vec.end(), cmp);
//
//	sort(x, x + n, cmp);//根据起点排序
//	int count = 1;
//	for (i = 1; i < n; i++)
//	{
//		if (x[i - 1].b <= x[i].a)/*后面的起点大于等于前面的终点：符合条件*/
//			count++;
//		else
//		{
//			x[i].b = x[i - 1].b < x[i].b ? x[i - 1].b : x[i].b;/*更换该点的终点，有利于下一次的计算*/
//		}
//	}
//
//	cout << count << endl;
//	return 0;
//}

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

										/*模板*/

////01背包
////二维写法：比较的时j和元素谁大，
////元素大：说明物品放不下，因此dp[i][j] = dp[i - 1][j]
////物品大或者相等：比较dp[i-1][j]和dp[i-1][j-w[i]]+v[i]
//
//const int N;
//const int S;
//int dp[N][S];//N:物品的数量，S：背包的大小
////dp[i][j]:从1~i个物品中取，当容量为j时，能放入的最多物品数量
//int w[N], v[N];//w:每个物品的重量，v：每个物品的价值
//
//int main()
//{
//	int n;//物品的数量
//	cin >> n;
//	
//	int i, j;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i];//注意题目要求的输入顺序
//
//	//初始化:初始化第一行
//	for (j = w[0]; j <= S; j++)
//		dp[0][j] = v[0];
//
//	for (i = 1/**/; i < n; i++)//物品
//	{
//		for (j = 1/**/; j <= S; j++)//容量
//		{
//			if (j < w[i])
//				dp[i][j] = dp[i - 1][j];
//			else
//				dp[j] = max(dp[i-1][j], dp[i][j - w[i]] + v[i]);
//		}
//	}
//
//	cout << dp[n - 1][S] << endl;
//	return 0;
//}
//
////一维数组
//
//const int N;//N:物品的数量
//const int S;
//int dp[[S];//S：背包的大小
////dp[j]:当容量为j时，能放入的最多物品数量
//int w[N], v[N];//w:每个物品的重量，v：每个物品的价值
//
//int main()
//{
//	int n;//物品的数量
//	cin >> n;
//
//	int i, j;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i];//注意题目要求的输入顺序
//
//	for (i = 0; i < n; i++)//物品
//	{
//		for (j = S; j >= w[i]; j--)//容量，要注意其遍历顺序为倒序，防止一个物品选多次
//		{
//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
//
//	cout << dp[S] << endl;
//	return 0;
//}
//
//
////完全背包
////概念与01背包的区别：物品有	无限多个
////代码与01背包的区别：j可顺序可逆序
//
////一维数组
//
//const int N;//N:物品的数量
//const int S;
//int dp [[S];//S：背包的大小
////dp[j]:当容量为j时，能放入的最多物品数量
//int w[N], v[N];//w:每个物品的重量，v：每个物品的价值
//
//int main()
//{
//	int n;//物品的数量
//	cin >> n;
//
//	int i, j;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i];//注意题目要求的输入顺序
//
//	for (i = 0; i < n; i++)//物品
//	{
//		for (j = w[i]; j <= S; j++)//容量，要注意其遍历顺序为倒序，防止一个物品选多次
//		{
//			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
//
//	cout << dp[S] << endl;
//	return 0;
//}
//
//
////多重背包
////概念与01背包的区别：第i种物品		最多	有M[i]个
////代码与01背包的区别：多了一层循环：每次循环M[i]次
//
//const int N;//N:物品的数量
//const int S;
//int dp [[S];//S：背包的大小
////dp[j]:当容量为j时，能放入的最多物品数量
//int w[N], v[N], m[N];//w:每个物品的重量，v：每个物品的价值
//
//int main()
//{
//	int n;//物品的数量
//	cin >> n;
//
//	int i, j, k/**/;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i] >> m[i];//注意题目要求的输入顺序
//
//	for (i = 0; i < n; i++)//物品
//	{
//		for (j = w[i]; j <= S; j++)//容量，要注意其遍历顺序为倒序，防止一个物品选多次
//		{
//			for (k = 1/*必须从1开始*/; k <= m[i] && j - k * w[i] >= 0/**/; k++)
//			{
//				dp[j] = max(dp[j], dp[j - k * w[i]/**/] +/**/ k * v[i]);
//			}
//		}
//	}
//
//	cout << dp[S] << endl;
//	return 0;
//}
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>/*max,sort函数所在头文件*/
//#include <cstring>
//
//#define quickio ios::sync_with_stdio,cin.tie(0),cout.tie(0);
//
//using namespace std;
////最长公共子序列:不要连续-----LCS
////最长公共子串：要连续
//
////模板题
////i:遍历s1的字母
////j:遍历s2的字母
////dp[i][j]到i,j这个位置时的最长公共子序列：
////若s1[i-1] = s2[j-1]:dp[i][j] = dp[i-1][j-1]+1------>i,j要从1开始
////else:max(dp[i-1][j], dp[i][j-1])
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
//		for (i = 1/**/; i <= len1; i++)
//		{
//			for (j = 1/**/; j <= len2; j++)
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

////ACboy needs your help
////https://acm.hdu.edu.cn/showproblem.php?pid=1712
////分组背包：给你N组物品，然后每一组你至多选择一个物品(也可以不选),
////每个物品都有自己的体积和价值，现在给你一个容量为M的背包，让你用这个背包装物品，使得物品价值总和最大.
//
////实际上是把每组看成一个01背包
///*
//讲解：https://www.bilibili.com/video/BV1eT41157xt/?spm_id_from=333.337.search-card.all.click&vd_source=41fa3a36a9ab4fa3fc7b5ff1c034346c
//*/
///*
//博客：https://blog.csdn.net/TheWayForDream/article/details/116567088?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171056305416800182147113%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171056305416800182147113&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-116567088-null-null.142^v99^pc_search_result_base3&utm_term=%E5%88%86%E7%BB%84%E8%83%8C%E5%8C%85&spm=1018.2226.3001.4187
//*/
//
//const int N = 105;
//const int M = 105;
//int A[N][M];
//
//int main()
//{
//	quickio;
//	int n, m;
//	while (cin >> n >> m)//不可判断n, m是否为0，只可判断是否到文件尾了
//	{
//		if (n == 0 && m == 0)
//			break;
//		int i, j, k;
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= m; j++)
//			{
//				cin >> A[i][j];
//			}
//		}
//
//		int dp[105] = { 0 };
//		for (i = 1; i <= n; i++)//物品
//		{
//			for (j = m; j >= 0; j--)//背包容量
//			{
//				for (k = 1; k <= m && k <= j; k++)//第i组的第k个物品
//				{
//					dp[j] = max(dp[j], dp[j - k] + A[i][k]);
//				}
//			}
//		}
//
//		cout << dp[m] << endl;
//	}
//	return 0;
//}


////P1441 砝码称重
////https://www.luogu.com.cn/problem/P1441
////多重背包
//
//
//int w[6] = { 1, 2, 3, 5, 10, 20 };
//int a[6];//砝码个数
//
//int main()
//{
//	quickio;
//	int i, j, k;
//
//	for (i = 0; i < 6; i++)
//	{
//		cin >> a[i];
//	}
//
//	int book[1005] = { 0 }, count = 0;
//	book[0] = 1;/*注意！！！！！！！11*/
//	for (i = 0; i < 6; i++)//物品
//	{
//		for (j = 1000; j >= 0; j--)//注意是逆序，防止前面的数据改变后面的数据
//		{
//			for (k = 1; k <= a[i]; k++)
//			{
//				if (book[j] == 1)
//				{
//					book[j + k * w[i]] = 1;
//				}
//			}
//		}
//	}
//
//	for (j = 1/*注意从1开始*/; j <= 1000; j++)
//	{
//		if (book[j] == 1)
//			count++;
//	}
//	cout << "Total=" << count << endl;
//	return 0;
//}


////最少拦截系统
////https://acm.hdu.edu.cn/showproblem.php?pid=1257
//
////最长递减子序列
////注意：dp数组最开始都初始化为1
//
//int main()
//{
//	int num, h[100000] = { 0 }, i;
//
//	while (cin >> num)
//	{
//		int count = 0;
//		for (i = 0; i < num; i++)
//		{
//			cin >> h[i];
//		}
//
//		int dp[10000] = { 0 };//最长递减子序列
//		for (i = 0; i < num; i++)
//			dp[i] = 1;
//		int i, j;
//
//		for (i = 1; i < num; i++)
//		{
//			for (j = 0; j < i; j++)
//			{
//				if (h[j] > h[i])
//					dp[i] = max(dp[j] + 1, dp[i]);/**/
//			}
//
//		}
//
//		for (i = 0; i < num; i++)
//		{
//			if (dp[i] == 1)
//				count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


//class相当于结构体

//

//class Solution {//Solution
//public:
//    void test(vector<int>& nums)
//    {
//        lengthOfLIS(nums);
//    }
//private:
//    //protect
//    int lengthOfLIS(vector<int>& nums)
//    {
//        if (nums.size() == 0)
//            return 0;
//
//        vector<int>dp(nums.size(), 1);
//
//        int i, j;
//        int maxn = 1;
//        for (i = 0; i < nums.size(); i++)
//        {
//            for (j = 0; j < i; j++)
//            {
//                if (nums[j] < nums[i])
//                    dp[i] = max(dp[j] + 1, dp[i]);
//            }
//            if (dp[i] > maxn)
//                maxn = dp[i];
//        }
//        return maxn;
//    }
//};
//
//class Solution2 {//Solution
//    //public:
//public:
//    //protect
//    int lengthOfLIS(vector<int>& nums)
//    {
//        if (nums.size() == 0)
//            return 0;
//
//        vector<int>dp(nums.size(), 1);
//
//        int i, j;
//        int maxn = 1;
//        for (i = 0; i < nums.size(); i++)
//        {
//            for (j = 0; j < i; j++)
//            {
//                if (nums[j] < nums[i])
//                    dp[i] = max(dp[j] + 1, dp[i]);
//            }
//            if (dp[i] > maxn)
//                maxn = dp[i];
//        }
//        return maxn;
//    }
//};
//
//int main()
//{
//    Solution a;//soulution:类，a就是类创建的对象
//    Solution2 g;
//    vector<int> b;//相当于c中的数组，int类型的一维数组
//    //vector<vector<int>>c//相当于c中的数组，int类型的二维维数组
//    a.lengthOfLIS(b);
//    g.lengthOfLIS(b);
////    lengthOfLIS(b);
//    return 0;
//}

//你只能写，不能读
//class STU
//{
//public:
//	void test(int age, int tele)
//	{
//		fun(age, tele);
//	}
//private:
//	int m_age;//m_age
//	int m_tele;
//	void fun(int age, int tele)
//	{
//		m_age = age;
//		m_tele = tele;
//		/*
//		cout << m_age << endl;
//		cout << m_tele << endl;
//		*/
//	}
//};
//
//int main()
//{
//	STU stu1;
//	stu1.test(18, 10086);
//	cout << stu1.m_age << endl;
//	return 0;
//}


							/*dp第二周周作业*/

////P1880 [NOI1995] 石子合并
////https://www.luogu.com.cn/problem/P1880
//
//////线性的解法，该题为环状！！！！！四周:若少了圆形四周
//////线性题解：董晓算法：https://www.bilibili.com/video/BV1gz4y1y7Rv?spm_id_from=333.880.my_history.page.click
////
//////要用到前缀和
//////前缀和：s[i] = s[i - 1] + a[i]
//////区间和 = s[r] - s[l - 1]
////
////#include <climits>
////const int N = 105;
////int a[N];//存石子个数
////int s[N];//存区间和
////int fin[N][N];//存从l到r的最小得分,i,i上初始化为0，其他为INT_MAX
////int fax[N][N];//存从l到r的最大得分, i,i上初始化为INT_MAX，其他初始化为0
////
////int main()
////{
////	quickio;
////	int n;
////	cin >> n;
////	
////	if (n == 1)
////		cout << 0 << endl << 0 << endl;
////	int i, len, k, l, j;//len:区间长度,k:分割点,l:区间左边界
////
////	for (i = 1/*好理解*/; i <= n; i++)
////	{
////		cin >> a[i];
////		s[i] = s[i - 1] + a[i];//求前缀和
////	}
////
////	for (i = 1; i <= n; i++)
////	{
////		for (j = 1; j <= n; j++)
////		{
////			if (i == j)
////			{
////				fin[i][j] = 0;
////				fax[i][j] = INT_MAX;
////			}
////			else
////			{
////				fin[i][j] = INT_MAX;
////				fax[i][j] = 0;
////			}
////		}
////	}
////
////	for (len = 2; len <= n; len++)//区间长度
////	{
////		for (l = 1; l + len - 1 <= n/*右区间*/; l++)//区间
////		{
////			int r = l + len - 1;//区间右边界
////			for (k = l; k < r/*<的原因：因为下面有k+1*/; k++)//分割点
////			{
////				fin[l][r] = min(fin[l][r], fin[l][k] + fin[k + 1][r] + s[r] - s[l - 1]);
////				fax[l][r] = max(fax[l][r], fax[l][k] + fax[k + 1][r] + s[r] - s[l - 1]);
////			}
////		}
////	}
////
////	cout << fin[1][n] << endl;
////	cout << fax[1][n] << endl;
////	return 0;
////}
//
//
////线性的解法，该题为环状！！！！！四周------>线性数组两个拼在一起
////线性题解：董晓算法：https://www.bilibili.com/video/BV1gz4y1y7Rv?spm_id_from=333.880.my_history.page.click
//
////要用到前缀和
////前缀和：s[i] = s[i - 1] + a[i]
////区间和 = s[r] - s[l - 1]
//
//#include <climits>
//const int N = 105 + 105;
//int a[N];//存石子个数
//int s[N];//存区间和
//int fin[N][N];//存从l到r的最小得分,i,i上初始化为0，其他为INT_MAX
//int fax[N][N];//存从l到r的最大得分, i,i上初始化为INT_MAX，其他初始化为0
//
//int main()
//{
//	quickio;
//	int n;
//	cin >> n;
//
//	if (n == 1)
//		cout << 0 << endl << 0 << endl;
//	int i, len, k, l, j;//len:区间长度,k:分割点,l:区间左边界
//
//	memset(fin, 0x3f3f3f, sizeof(fin));
//	for (i = 1/*好理解*/; i <= n; i++)
//	{
//		cin >> a[i];
//
//		/*与线性的区别*/
//		a[i + n] = a[i];
//	}
//
//	for (i = 1; i <= 2*n; i++)
//	{
//		s[i] = s[i - 1] + a[i];//求前缀和
//		fin[i][i] = 0;/**/
//	}
//
//
//	for (len = 2; len <= n; len++)//区间长度
//	{
//		for (l = 1; l + len - 1 < n * 2/*注意是 < *//*右区间*/; l++)//区间
//		{
//			int r = l + len - 1;//区间右边界
//			for (k = l; k < r && k < 2 * n/*<的原因：因为下面有k+1*/; k++)//分割点
//			{
//				fin[l][r] = min(fin[l][r], fin[l][k] + fin[k + 1][r] + s[r] - s[l - 1]);
//				fax[l][r] = max(fax[l][r], fax[l][k] + fax[k + 1][r] + s[r] - s[l - 1]);
//			}
//		}
//	}
//
//	/*与线性的区别*/
//	int resmax = -1;
//	int resmin = INT_MAX;
//	for (i = 1; i <= n; i++)
//	{
//		resmax = max(resmax, fax[i][i + n - 1]);
//		resmin = min(resmin, fin[i][i + n - 1]);
//	}
//	cout << resmin << endl;
//	cout << resmax << endl;
//	return 0;
//}

//
////P1880 [NOI1995] 石子合并
////https://www.luogu.com.cn/problem/P1880
//
//#include <iostream>
//#include <vector>
//#include <algorithm>/*max函数所在头文件*/
//#include <cstring>
//#include <climits>
//
//#define quickio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//
//using namespace std;
//
////注意是环状的，而不是线性的
//const int N = 105 + 105;/**/
//int fin[N][N];//从i到j的最小区间和
//int fax[N][N];//从i到j的最大区间和
//int a[2 * N];
//int s[2 * N];//前缀和
//
//int main()
//{
//    quickio;
//    int n;
//    cin >> n;
//
//    int i;
//    memset(fin, 0x3f3f3f, sizeof(fin));
//    for (i = 1; i <= n; i++)
//    {
//        cin >> a[i];
//        a[i + n] = a[i];
//    }
//
//    for (i = 1; i <= 2 * n; i++)
//    {
//        s[i] = s[i - 1] + a[i];//前缀和
//        fin[i][i] = 0;/*是在2 * n的区间李，而不是n*/
//    }
//
//    int len, l, r, k;//区间长度，左边界，右边界，分割点
//    for (len = 2/**/; len <= n; len++)
//    {
//        for (l = 1; l + len - 1 <= 2 * n; l++)
//        {
//            r = l + len - 1;
//            for (k = l/*l*/; k </*<*/ r; k++)
//            {
//                fin[l][r] = min(fin[l][r], fin[l][k] + fin[k + 1][r] + s[r] - s[l - 1]);
//                fax[l][r] = max(fax[l][r], fax[l][k] + fax[k + 1][r] + s[r] - s[l - 1]);
//            }
//        }
//    }
//
//    int resmax = -1, resmin = INT_MAX;
//    for (i = 1; i </*<*/ n; i++)
//    {
//        resmax = max(resmax, fax[i][i + n - 1/**/]);
//        resmin = min(resmin, fin[i][i + n - 1/**/]);
//    }
//
//    cout << resmin << endl;
//    cout << resmax << endl;
//    return 0;
//}


