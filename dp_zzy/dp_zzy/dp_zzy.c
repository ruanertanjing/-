//#define _CRT_SECURE_NO_WARNINGS 1
//#define ll long long
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdbool.h>/**/

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


////6. Я���о����ϣ�������ģ����ԣ�
////https://kamacoder.com/problempage.php?pid=1046
//
///*01��������*/
//
///*��һ����ά����*/
//��Ʒ������˳��ɵ���������˳��Ҳ����ǰ��������ɺ�ǰ
//����һ�㶼��˳����ƷΪ��ѭ��(i),����Ϊ��ѭ��(j)
///*dp[i][j]:��0��i����Ʒ��������ȡ������ʣ�ռ��СΪj������Я��������ֵ*/
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - room[i]] + value[i]);
//
///*
//3 4 
//1 3 4
//15 20 30
//*/
//
//int value[5005];//��ֵ
//int room[5005];//��ռ�ռ�
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
//    //��ʼ��
//     ע���ֵΪ�������
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
//    //����
//    for (i = 1; i < m; i++)//������Ʒ
//    {
//        for (j = 1; j <= n; j++)//��������
//        {
//            if (j < room[i])/*�����٣�����������������������*/
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
//    /*���ִ𰸲��Ծʹ�ӡ����*/
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
///*������һά����*/
////��Ʒ����˳�򲻿ɵ������ұ���Ҫ�����������ֹ�ظ�����
//
////dp[j] = max(dp[j/*ע����j������j-1*/], dp[j - room[i]] + value[i])
//
////dp[j]:����Ϊjʱ�ɷŵ�����ֵ
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
//    //��ʼ��
//    for (j = 0; j <= n; j++)
//    {
//        if (j < room[0])
//            dp[j] = 0;
//        else
//            dp[j] = value[0];
//    }
//
//    for (i = 1; i < m; i++)//��Ʒ
//    {
//        for (j = n; j >= 1; j--/*��-����+�������ϰ����д��+��Խ�����*/)//����
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



//16. �ָ�Ⱥ��Ӽ�
//https://leetcode.cn/problems/partition-equal-subset-sum/

/*��һ�����ݣ���ʱ��������������*/

/*������01������
��Ʒ��ÿ����
��ֵ��ÿ����
������sum/2
*/

/*��ά*/

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

///*һά*/
//// /*dp[j]:��j��λ���ܹ��ɵ�����
//// dp[j] == j :��
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
//        scanf("%d", &w[i]);
//    }
//    for (i = 0; i < N; i++)
//    {
//        scanf("%d", &v[i]);
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
//    printf("%d\n", dp[N]);
//    return 0;
//}



////P1216 [USACO1.5] [IOI1994]���������� Number Triangles
////https://www.luogu.com.cn/problem/P1216
//
////�����Ǳ��ѣ��ܿ��ܳ�ʱ
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
////ȷ��dp[i][j]�ĺ���
//int dp[1000][1005] = { 0 };//�浽�õ�����·����
//
//int main()
//{
//	int r;
//	scanf("%d", &r);
//	int i, j;
//
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < i + 1; j++)//��I����i��Ԫ��
//		{
//			scanf("%d", &v[i][j]);
//		}
//	}
//
//
//	////ȷ��dp[i][j]�ĺ���
//	//int dp[1000][1005] = { 0 };//�浽�õ�����·����
//
//	//���ƹ�ʽ��dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])
//	//ע���һ�к͵�һ��Ҫ��ʼ��
//
//	//��ʼ��
//	dp[0][0] = v[0][0];
//	for (i = 1; i < r; i++)
//		dp[i][0] = dp[i - 1][0] + v[i][0];
//
//	//����˳��:���ϵ��£�������
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