#define _CRT_SECURE_NO_WARNINGS 1
#define ll long long
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>/**/

//��̬�滮�岿����dp���飬�±꺬�壻��ʽ������˳�򣻳�ʼ������ӡ����

//쳲���������

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


////��¥��
////����д��ֻ����50%��Ҫ�õ��߾��ȣ���Ϊ�漰����������ӣ��ҽ��ݷ�Χ��
////���ö�ά������ģ��߾���
//// ��⣺https://www.luogu.com.cn/article/mp47tiai
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
//	//dp[2] = 2;/*ע����2������1*/
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


////53. ����������
////https://leetcode.cn/problems/maximum-subarray/
//
////��̬�滮��dp, i�ĺ��壬����˳�򣬳�ʼ�������ƹ�ʽ����ӡ����
//
////�뵽�˻�������---->left, right--->û������ⷨ
//
///*
//��������
//����������һ�ֻ���˫ָ���һ��˼�룬����ָ��ָ���Ԫ��֮���γ�һ�����ڡ�
//
//���ࣺ���������࣬һ���ǹ̶���С��Ĵ��ڣ�һ���Ǵ�С��̬�仯�Ĵ��ڡ�
//
//Ӧ�ã�
//
//���û������ڻ�ȡƽ�������ݣ���һ������ʱ�������ƽ��ֵ���ܹ��и��õ��ȶ��ԣ����¶ȼ�⡣
//
//ʲô��������û������������ʵ�������أ�
//
//һ����������ݽṹ����������ַ���
//��ȡĳ���Ӵ��������������̵���ֵ���������ĳ��Ŀ��ֵʱ
//�����Ȿ�����ͨ���������
//*/
//
///*
//https://blog.csdn.net/yjpeng125/article/details/120833365?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171007659016800226571331%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171007659016800226571331&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-120833365-null-null.142^v99^pc_search_result_base3&utm_term=%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3&spm=1018.2226.3001.4187
//*/
//
////dp[i]:��iΪ�յ����������к�
////dp[i] = max(dp[i-1] + nums[i], nums[i]);//ȡnums[i]�������dp[i-1]Ϊ����nums[i]Ϊ����
////��Ϊ��dp[i-1]�йأ����Գ�ʼ����ʱ���ʼ��dp[0]
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


