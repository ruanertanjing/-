//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#define ll long long
//
////A - ÍØÆËÅÅÐò / ¼ÒÆ×Ê÷
////https://vjudge.net/contest/613618#problem/A
//
////²»ÐÐ
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int family[101] = { 0 }, i, n1 = n;
//	while (n1--)
//	{
//		int peo, num = 0;
//		while (1)
//		{
//			scanf("%d", &peo);
//			if (peo == 0)
//				break;
//			else
//				num++;
//		}
//
//		family[n - num - 1] = n - n1 + 2;
//	}
//	for (i = 0; i < n; i++)
//		printf("%d ", family[i]);
//	printf("\n");
//	return 0;
//}