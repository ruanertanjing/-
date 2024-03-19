#include <iostream>
#include <vector>
#include <algorithm>/*max��������ͷ�ļ�*/
#include <cstring>

#define quickio ios::sync_with_stdio,cin.tie(0),cout.tie(0);

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


//class Solution {
//public:
//    int count = 0;
//    void backtracking(vector<int>& nums, int target, int sum, int startindex)
//    {
//        int i;
//
//        /*������Լ����������ɷ��ذ�����������*/
//        // if (sum > target)
//        //     return;
//
//        //��ֹ����
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
//        //�����߼�
//        for (i = startindex/*������0��������������*/; i < nums.size(); i++)
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



////52. Я���о����ϣ�������ģ����ԣ�
////https://kamacoder.com/problempage.php?pid=1052
//
////���ر���
////��01������������ǣ�������������Ʒ������ѭ�����ɽ������Ҵ�ǰ�������
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
//    for (i = 0; i < N; i++)//��Ʒ
//    {
//        for (j = w[i]; j <= V; j++)//����
//        {
//            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//        }
//    }
//
//    printf("%d\n", dp[V]);
//    return 0;
//}


////01����-���Ĵ�˵
//const int vn = 1e4 + 5;
//const int wn = 1e4 + 5;
//
////ȷ��dp���麬��
//int n, s, v[vn] = { 0 }, w[wn] = { 0 }, i, j, dp[wn] = { 0 };//dp[i]:������Ϊiʱ���õ�������ֵ
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
//		//��ʼ��
//
//		for (i = 0; i < n; i++)//��Ʒ
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


////P1802 5 ��������
////https://www.luogu.com.cn/problem/P1802
//
////����������ɹ�����ʧ��
////�ɹ���max(dp[j - use[i]] + win[i], dp[j] + lose[i]);
////ʧ�ܣ�dp[j] + lose[i]
//
///*һά*/
//
//const int MAX = 1005;
//
//int lose[MAX], win[MAX], use[MAX];
//
//int main()
//{
//	quickio;//��������
//
//	int n, x;
//	cin >> n >> x;
//
//	//dp[i]:���ɻ�õľ���
//	//���飺value
//	//������weight
//
//	long long dp[MAX] = { 0 };/*ע�⿪long long*/
//	int i, j;
//
//	for (i = 0; i < n; i++)
//	{
//		cin >> lose[i] >> win[i] >> use[i];
//	}
//
//	for (i = 0; i < n; i++)//Ҫ�����
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

////   ��ȫ   ��01���������𣺿��Ե�����Ʒ�ͱ���������ѭ����j�����������
//
//
////P1776 ����ɸѡ
////https://www.luogu.com.cn/problem/P1776
//
////���ر�������~~~~~
////��Ϊ01�����ͺ�
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
//	for (i = 0; i < n; i++)//��Ʒ
//	{
//		for (j = W; j >= w[i]; j--)//��������
//		{
//			//��ʱ
//			//for (k = 0; k < m[i]; k++)//��Ʒ������
//
//			//��֦
//			for (k = 1; k <= m[i] && j - k * w[i] >= 0; k++)//��Ʒ������
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


////01-�����ܳ���Ψһ���ź�
//
////����������������ʱ��
////��Ʒ��������ʱ��
////��Ϊ���ֻ�ܷ�һ��----->01����
//
////Runtime Error on test 2���ǳ�ʱ
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



////L-���ʴ�ӱ��ŷ�����
//
////t:����
////m����Ʒ
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

////H-�����������:��Ҫ����-----LCS
////������Ӵ���Ҫ����
//
////ģ����
////i:����s1����ĸ
////j:����s2����ĸ
//
////dp[i][j]:����λ��ʱ��Ĺ���������
//
//#include <cstring>
//
//const int R = 1005;//��
//const int C = 1005;//��
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


////P1095 [NOIP2007 �ռ���] �����ߵ�����
////https://www.luogu.com.cn/problem/P1095
//
////�ӳ���������ʣ��ʱ�����ߵľ��� > S
//
////�ָ�Ҫ3�룬���ü���3����51���ü���������34+60
////����������ͬʱ�Ƚ�����ԭ�ٶ��ĸ���----->>̰�ĵ�˼·
//
///*
//��⣺https://blog.csdn.net/qq_35855297/article/details/52331942?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171033739316800215075491%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171033739316800215075491&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-52331942-null-null.142^v99^pc_search_result_base3&utm_term=%E5%AE%88%E6%9C%9B%E8%80%85%E7%9A%84%E9%80%83%E7%A6%BB&spm=1018.2226.3001.4187
//*/
//
////��һ����̬�滮
////��ȫ�����ٽ���һ��ѭ�����Ƚ�ͬһʱ��ʱs+=17��dp[i]�Ĵ�С
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
//	for (i = 1; i <= T; i++)//ʱ��
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


//������̰��

//int main()
//{
//	int M, S, T;
//	cin >> M >> S >> T;
//
//	int i, a = 0, b = 0;
//	for (i = 1; i <= T; i++)//ʱ��
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


////P1832 A+B Problem����������
////https://www.luogu.com.cn/problem/P1832
//
////��Ҫ�Ȱ������������ŷ��ɸ�����ټ���������һ���������������dp��ӵõ��µ�dp��
//
////ŷ��ɸ��Ҫbook[MAX]:��¼��Щ����������Ҫprime[MAX]:��¼������h:��¼�����ĸ���
//
///*��ȫ��������ÿ������������Ʒ��dp[i]��i���ɱ�����ÿ����Ʒ���������޴�*/
//int prime[1005], book[1005], h = 0;
//
//void isprime(int max)//max:����¼����
//{
//	book[0] = 1;
//	book[1] = 1;
//
//	int i, j;
//	for (i = 2; i <= max; i++)//�����������Դ�2��ʼ
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
//	//������
//	isprime(n);
//
//	long long/*ע����long long����Ϊ���ݿ��ܴܺ��������������*/ dp[1005] = {0}, i, j;//dp:��¼ÿ�����ķ�������
//	dp[0] = 1;//dp[0]ֵΪ1�����񲻺ý��ͣ������ɣ���Ȼ���������ķ������Ͳ��ܵ���1�ˣ�
//	ʲôҲ��ȡҲ��һ�ַ���
// for (i = 0; i < h; i++)//������Ʒ��������
//	{
//		for (j = prime[i]; j <= n; j++)//����������j:��ʾ��
//		{
//			//if (book[j - prime[i]] == 0)����Ϊ��Ȼ����������Ҳ��������������
//				dp[j] += dp[j - prime[i]];
//		}
//	}
//	cout << dp[n] << endl;
//	return 0;
//}


////G - ����-����AK���ܴ���
//
////���ص��������⣺435�����ۣ���̰��
////�߶θ���
//
////#include <map>
////
////multimap<int, int>mymap;//��Ϊunordered_map��������multimap��map�����򣬶�multimap���Գ����ظ�����
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
//		//mymap.insert(pair<int, int>(a, b));/*ע���÷�*/
//	}
//	//sort(vec.begin(), vec.end(), cmp);
//
//	sort(x, x + n, cmp);//�����������
//	int count = 1;
//	for (i = 1; i < n; i++)
//	{
//		if (x[i - 1].b <= x[i].a)/*����������ڵ���ǰ����յ㣺��������*/
//			count++;
//		else
//		{
//			x[i].b = x[i - 1].b < x[i].b ? x[i - 1].b : x[i].b;/*�����õ���յ㣬��������һ�εļ���*/
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
////��ȫ  ��������
////һ����Ϊn�Ķд���Ҫ����������ɳ���Ϊa,b,c�Ķд����Ҷд����������ܶࡣ
////һ����Ϊn�ı����������Ϊa, b, c���������壬������ô��ʹ�ü�ֵ���
//
////��ȫ���������01������������ȫ����������Ʒʱ����˳��Ҳ��������
//
//#include <cstring>
//
//int main()
//{
//	int n, v[3];
//	cin >> n >> v[0] >> v[1] >> v[2];//a, b, c
//	int i, j;
//
//	int dp[4005] = { 0 };//����Ϊiʱ��ɷŵ��������
//	memset(dp, -1, sizeof(dp));//cstringͷ�ļ�
//
//	dp[0] = 0;//����Ϊ1�ı�������0��
//	/**/
//
//	for (i = 0; i < 3; i++)//��Ʒ��a, b, c
//	{
//		for (j = v[i]; j <= n; j++)//����
//		{
//			if (dp[j - v[i]] != -1)/**/
//				dp[j] = max(dp[j], dp[j - v[i]] + 1);
//		}
//	}
//
//	cout << dp[n] << endl;
//	return 0;
//}

										/*ģ��*/

////01����
////��άд�����Ƚϵ�ʱj��Ԫ��˭��
////Ԫ�ش�˵����Ʒ�Ų��£����dp[i][j] = dp[i - 1][j]
////��Ʒ�������ȣ��Ƚ�dp[i-1][j]��dp[i-1][j-w[i]]+v[i]
//
//const int N;
//const int S;
//int dp[N][S];//N:��Ʒ��������S�������Ĵ�С
////dp[i][j]:��1~i����Ʒ��ȡ��������Ϊjʱ���ܷ���������Ʒ����
//int w[N], v[N];//w:ÿ����Ʒ��������v��ÿ����Ʒ�ļ�ֵ
//
//int main()
//{
//	int n;//��Ʒ������
//	cin >> n;
//	
//	int i, j;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i];//ע����ĿҪ�������˳��
//
//	//��ʼ��:��ʼ����һ��
//	for (j = w[0]; j <= S; j++)
//		dp[0][j] = v[0];
//
//	for (i = 1/**/; i < n; i++)//��Ʒ
//	{
//		for (j = 1/**/; j <= S; j++)//����
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
////һά����
//
//const int N;//N:��Ʒ������
//const int S;
//int dp[[S];//S�������Ĵ�С
////dp[j]:������Ϊjʱ���ܷ���������Ʒ����
//int w[N], v[N];//w:ÿ����Ʒ��������v��ÿ����Ʒ�ļ�ֵ
//
//int main()
//{
//	int n;//��Ʒ������
//	cin >> n;
//
//	int i, j;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i];//ע����ĿҪ�������˳��
//
//	for (i = 0; i < n; i++)//��Ʒ
//	{
//		for (j = S; j >= w[i]; j--)//������Ҫע�������˳��Ϊ���򣬷�ֹһ����Ʒѡ���
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
////��ȫ����
////������01������������Ʒ��	���޶��
////������01����������j��˳�������
//
////һά����
//
//const int N;//N:��Ʒ������
//const int S;
//int dp [[S];//S�������Ĵ�С
////dp[j]:������Ϊjʱ���ܷ���������Ʒ����
//int w[N], v[N];//w:ÿ����Ʒ��������v��ÿ����Ʒ�ļ�ֵ
//
//int main()
//{
//	int n;//��Ʒ������
//	cin >> n;
//
//	int i, j;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i];//ע����ĿҪ�������˳��
//
//	for (i = 0; i < n; i++)//��Ʒ
//	{
//		for (j = w[i]; j <= S; j++)//������Ҫע�������˳��Ϊ���򣬷�ֹһ����Ʒѡ���
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
////���ر���
////������01���������𣺵�i����Ʒ		���	��M[i]��
////������01���������𣺶���һ��ѭ����ÿ��ѭ��M[i]��
//
//const int N;//N:��Ʒ������
//const int S;
//int dp [[S];//S�������Ĵ�С
////dp[j]:������Ϊjʱ���ܷ���������Ʒ����
//int w[N], v[N], m[N];//w:ÿ����Ʒ��������v��ÿ����Ʒ�ļ�ֵ
//
//int main()
//{
//	int n;//��Ʒ������
//	cin >> n;
//
//	int i, j, k/**/;
//	for (i = 0; i < n; i++)
//		cin >> w[i] >> v[i] >> m[i];//ע����ĿҪ�������˳��
//
//	for (i = 0; i < n; i++)//��Ʒ
//	{
//		for (j = w[i]; j <= S; j++)//������Ҫע�������˳��Ϊ���򣬷�ֹһ����Ʒѡ���
//		{
//			for (k = 1/*�����1��ʼ*/; k <= m[i] && j - k * w[i] >= 0/**/; k++)
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
//#include <algorithm>/*max,sort��������ͷ�ļ�*/
//#include <cstring>
//
//#define quickio ios::sync_with_stdio,cin.tie(0),cout.tie(0);
//
//using namespace std;
////�����������:��Ҫ����-----LCS
////������Ӵ���Ҫ����
//
////ģ����
////i:����s1����ĸ
////j:����s2����ĸ
////dp[i][j]��i,j���λ��ʱ������������У�
////��s1[i-1] = s2[j-1]:dp[i][j] = dp[i-1][j-1]+1------>i,jҪ��1��ʼ
////else:max(dp[i-1][j], dp[i][j-1])
//
////dp[i][j]:����λ��ʱ��Ĺ���������
//
//#include <cstring>
//
//const int R = 1005;//��
//const int C = 1005;//��
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
////���鱳��������N����Ʒ��Ȼ��ÿһ��������ѡ��һ����Ʒ(Ҳ���Բ�ѡ),
////ÿ����Ʒ�����Լ�������ͼ�ֵ�����ڸ���һ������ΪM�ı������������������װ��Ʒ��ʹ����Ʒ��ֵ�ܺ����.
//
////ʵ�����ǰ�ÿ�鿴��һ��01����
///*
//���⣺https://www.bilibili.com/video/BV1eT41157xt/?spm_id_from=333.337.search-card.all.click&vd_source=41fa3a36a9ab4fa3fc7b5ff1c034346c
//*/
///*
//���ͣ�https://blog.csdn.net/TheWayForDream/article/details/116567088?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171056305416800182147113%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171056305416800182147113&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-116567088-null-null.142^v99^pc_search_result_base3&utm_term=%E5%88%86%E7%BB%84%E8%83%8C%E5%8C%85&spm=1018.2226.3001.4187
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
//	while (cin >> n >> m)//�����ж�n, m�Ƿ�Ϊ0��ֻ���ж��Ƿ��ļ�β��
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
//		for (i = 1; i <= n; i++)//��Ʒ
//		{
//			for (j = m; j >= 0; j--)//��������
//			{
//				for (k = 1; k <= m && k <= j; k++)//��i��ĵ�k����Ʒ
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


////P1441 �������
////https://www.luogu.com.cn/problem/P1441
////���ر���
//
//
//int w[6] = { 1, 2, 3, 5, 10, 20 };
//int a[6];//�������
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
//	book[0] = 1;/*ע�⣡������������11*/
//	for (i = 0; i < 6; i++)//��Ʒ
//	{
//		for (j = 1000; j >= 0; j--)//ע�������򣬷�ֹǰ������ݸı���������
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
//	for (j = 1/*ע���1��ʼ*/; j <= 1000; j++)
//	{
//		if (book[j] == 1)
//			count++;
//	}
//	cout << "Total=" << count << endl;
//	return 0;
//}


////��������ϵͳ
////https://acm.hdu.edu.cn/showproblem.php?pid=1257
//
////��ݼ�������
////ע�⣺dp�����ʼ����ʼ��Ϊ1
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
//		int dp[10000] = { 0 };//��ݼ�������
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


//class�൱�ڽṹ��

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
//    Solution a;//soulution:�࣬a�����ഴ���Ķ���
//    Solution2 g;
//    vector<int> b;//�൱��c�е����飬int���͵�һά����
//    //vector<vector<int>>c//�൱��c�е����飬int���͵Ķ�άά����
//    a.lengthOfLIS(b);
//    g.lengthOfLIS(b);
////    lengthOfLIS(b);
//    return 0;
//}

//��ֻ��д�����ܶ�
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


							/*dp�ڶ�������ҵ*/

////P1880 [NOI1995] ʯ�Ӻϲ�
////https://www.luogu.com.cn/problem/P1880
//
//////���ԵĽⷨ������Ϊ��״��������������:������Բ������
//////������⣺�����㷨��https://www.bilibili.com/video/BV1gz4y1y7Rv?spm_id_from=333.880.my_history.page.click
////
//////Ҫ�õ�ǰ׺��
//////ǰ׺�ͣ�s[i] = s[i - 1] + a[i]
//////����� = s[r] - s[l - 1]
////
////#include <climits>
////const int N = 105;
////int a[N];//��ʯ�Ӹ���
////int s[N];//�������
////int fin[N][N];//���l��r����С�÷�,i,i�ϳ�ʼ��Ϊ0������ΪINT_MAX
////int fax[N][N];//���l��r�����÷�, i,i�ϳ�ʼ��ΪINT_MAX��������ʼ��Ϊ0
////
////int main()
////{
////	quickio;
////	int n;
////	cin >> n;
////	
////	if (n == 1)
////		cout << 0 << endl << 0 << endl;
////	int i, len, k, l, j;//len:���䳤��,k:�ָ��,l:������߽�
////
////	for (i = 1/*�����*/; i <= n; i++)
////	{
////		cin >> a[i];
////		s[i] = s[i - 1] + a[i];//��ǰ׺��
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
////	for (len = 2; len <= n; len++)//���䳤��
////	{
////		for (l = 1; l + len - 1 <= n/*������*/; l++)//����
////		{
////			int r = l + len - 1;//�����ұ߽�
////			for (k = l; k < r/*<��ԭ����Ϊ������k+1*/; k++)//�ָ��
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
////���ԵĽⷨ������Ϊ��״��������������------>������������ƴ��һ��
////������⣺�����㷨��https://www.bilibili.com/video/BV1gz4y1y7Rv?spm_id_from=333.880.my_history.page.click
//
////Ҫ�õ�ǰ׺��
////ǰ׺�ͣ�s[i] = s[i - 1] + a[i]
////����� = s[r] - s[l - 1]
//
//#include <climits>
//const int N = 105 + 105;
//int a[N];//��ʯ�Ӹ���
//int s[N];//�������
//int fin[N][N];//���l��r����С�÷�,i,i�ϳ�ʼ��Ϊ0������ΪINT_MAX
//int fax[N][N];//���l��r�����÷�, i,i�ϳ�ʼ��ΪINT_MAX��������ʼ��Ϊ0
//
//int main()
//{
//	quickio;
//	int n;
//	cin >> n;
//
//	if (n == 1)
//		cout << 0 << endl << 0 << endl;
//	int i, len, k, l, j;//len:���䳤��,k:�ָ��,l:������߽�
//
//	memset(fin, 0x3f3f3f, sizeof(fin));
//	for (i = 1/*�����*/; i <= n; i++)
//	{
//		cin >> a[i];
//
//		/*�����Ե�����*/
//		a[i + n] = a[i];
//	}
//
//	for (i = 1; i <= 2*n; i++)
//	{
//		s[i] = s[i - 1] + a[i];//��ǰ׺��
//		fin[i][i] = 0;/**/
//	}
//
//
//	for (len = 2; len <= n; len++)//���䳤��
//	{
//		for (l = 1; l + len - 1 < n * 2/*ע���� < *//*������*/; l++)//����
//		{
//			int r = l + len - 1;//�����ұ߽�
//			for (k = l; k < r && k < 2 * n/*<��ԭ����Ϊ������k+1*/; k++)//�ָ��
//			{
//				fin[l][r] = min(fin[l][r], fin[l][k] + fin[k + 1][r] + s[r] - s[l - 1]);
//				fax[l][r] = max(fax[l][r], fax[l][k] + fax[k + 1][r] + s[r] - s[l - 1]);
//			}
//		}
//	}
//
//	/*�����Ե�����*/
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
////P1880 [NOI1995] ʯ�Ӻϲ�
////https://www.luogu.com.cn/problem/P1880
//
//#include <iostream>
//#include <vector>
//#include <algorithm>/*max��������ͷ�ļ�*/
//#include <cstring>
//#include <climits>
//
//#define quickio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//
//using namespace std;
//
////ע���ǻ�״�ģ����������Ե�
//const int N = 105 + 105;/**/
//int fin[N][N];//��i��j����С�����
//int fax[N][N];//��i��j����������
//int a[2 * N];
//int s[2 * N];//ǰ׺��
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
//        s[i] = s[i - 1] + a[i];//ǰ׺��
//        fin[i][i] = 0;/*����2 * n�������������n*/
//    }
//
//    int len, l, r, k;//���䳤�ȣ���߽磬�ұ߽磬�ָ��
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


