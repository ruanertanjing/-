//#include <iostream>
//#include <queue>
//#include <climits>
//
//using namespace std;
//

//// ��Դ���·������׼�棩
//
//const int MAXM = 2e6;
//const int MAXN = 1e6;
//int n, m, s;
//int head[MAXN];//���ĸ���
//int cnt;
//int vis[MAXN];
//int ans[MAXN];
//
//struct EDGE
//{
//	int to;
//	int next;
//	int wei;
//}edge[MAXM];//
//
//void add(int u, int v, int w)
//{
//	cnt++;
//	edge[cnt].to = v;
//	edge[cnt].wei = w;
//	edge[cnt].next = head[u];
//	head[u] = cnt;
//}
//
//int main()
//{
//	cin >> n >> m >> s;
//	int i;
//	
//	for (i = 1; i <= n; i++)
//		ans[i] = INT_MAX;
//	ans[s] = 0;
//
//	int u, v, w;
//	for (i = 1; i <= m; i++)
//	{
//		cin >> u >> v >> w;
//		add(u, v, w);
//	}
//
//	priority_queue<pair<int, int> >que;
//	que.push({ 0, s });//���룬 ���
//
//	while (!que.empty())
//	{
//		int h = que.top().first;
//		int qh = que.top().second;
//		que.pop();
//
//		if (vis[qh] == 0)
//		{
//			vis[qh] = 1;
//
//			for (int i = head[qh]; i != 0; i = edge[i].next)
//			{
//				int t = edge[i].to;
//				if (ans[t] > ans[qh] + edge[i].wei)
//				{
//					ans[t] = ans[qh] + edge[i].wei;
//
//					if (vis[t] == 0)
//						que.push({ -ans[t], t });
//				}
//			}
//		}
//	}
//
//	for (i = 1; i <= n; i++)
//		cout << ans[i] << ' ';
//
//	cout << endl;
//
//	return 0;
//}


////����λ��
//ѡ����ǵڶ���·��
////������que���ж������ı�
//
//#include <climits>
//#include <iostream>
//
//using namespace std;
//
//const int MAXM = 1e4 + 5;
//const int MAXN = 205;
//int n, m;
//
//
//int main()
//{
//    cin >> n >> m;
//
//    return 0;
//}


////�ֺ��ؽ�
////Flody
//
//#include <climits>
//#include <iostream>
//
//using namespace std;
//
//const int MAXN = 205;
//const int MAXM = MAXN * (MAXN - 1) / 2;
//int board[MAXN][MAXN];
//
//int main()
//{
//    int m, n;
//    cin >> n >> m;
//
//
//    return 0;
//}


// D - ����
//��ʱ����֪����ô�Ż�
//��������

#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define quickio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);/*ע�⣬�зֺ�*/

using namespace std;

const int MAXN = 3e4 + 5;
const int MAXM = 1e5 + 5;
int edge[MAXN];//���
vector<int>EDGE[MAXN];
int vis[MAXN];

int main()
{
    quickio;
    int t;
    int n, m;
    cin >> t;

    while (t--)
    {
        memset(vis, 0, sizeof vis);/*cstringͷ�ļ���*/
        memset(edge, 0, sizeof edge);

        cin >> n >> m;
        int i;
        int a, b;

        for (i = 1; i <= m; i++)
        {
            cin >> a >> b;
            edge[b]++;
            EDGE[a].push_back(b);
        }

        queue<int> que;
        for (i = 1; i <= n; i++)
        {
            if (edge[i] == 0)
            {
                que.push(i);
                cout << i << ' ';
                vis[i] = 1;
            }
        }

        while (!que.empty())
        {
            i = que.front();
            que.pop();

            for (int j : EDGE[i])
            {
                if (vis[j] == 1)
                    continue;
                edge[j]--;

                if (edge[j] == 0)
                {
                    que.push(j);
                    cout << j << ' ';
                    vis[j] = 1;
                }
            }
            
        }
    }

    cout << endl;
    return 0;
}




////���·����
////ע�����ظ���Ҫ�ظ���ֵ
//
////���·��
//
////������δ��Ȩ
//
//#include <climits>
//#include <iostream>
//#include <queue>
//#include <unordered_map>
//
//using namespace std;
//
//const int MAXM = 2e6;
//const int MAXN = 1e6;
//int n, m, s;
//int head[MAXN];//���ĸ���
//int cnt;
//int vis[MAXN];
//int ans[MAXN];
//int count[MAXN];//�ظ��߳��ֵĴ���
//unordered_map<pair<int, int>, int>map;
//
//struct EDGE
//{
//	int to;
//	int next;
//	int wei;
//}edge[MAXM];//
//
//void add(int u, int v, int w)
//{
//	cnt++;
//	edge[cnt].to = v;
//
//	//if (edge[head[u]].to == v)
//	//	edge[cnt].wei = edge[head[u]].to + 1;
//	//else
//	//	edge[cnt].wei = w;
//
//	//auto it = map.find({ u,v });
//	//if (it.second != 0)
//	if (map[{u, v}] != 1 || map[{u, v}] != 0)
//		edge[cnt].wei = map[{u, v}] + 1;
//	else
//		edge[cnt].wei = 1;
//	edge[cnt].next = head[u];
//	head[u] = cnt;
//}
//
//int main()
//{
//	cin >> n >> m;
//	int i;
//
//	for (i = 1; i <= n; i++)
//		ans[i] = INT_MAX;
//	ans[1] = 1;
//
//	int u, v;
//	for (i = 1; i <= m; i++)
//	{
//		cin >> u >> v;
//		map[{u, v}]++;
//		add(u, v, 1);
//	}
//
//	priority_queue<pair<int, int> >que;
//	que.push({ 1, 1 });//���룬 ���
//
//	while (!que.empty())
//	{
//		int h = que.top().first;
//		int qh = que.top().second;
//		que.pop();
//
//		if (vis[qh] == 0)
//		{
//			vis[qh] = 1;
//
//			for (int i = head[qh]; i != 0; i = edge[i].next)
//			{
//				int t = edge[i].to;
//				if (ans[t] > ans[qh] + edge[i].wei)
//				{
//					ans[t] = ans[qh] + edge[i].wei;
//
//					if (vis[t] == 0)
//						que.push({ -ans[t], t });
//				}
//			}
//		}
//	}
//
//	cout << 1 << endl;
//	for (i = 2; i <= n; i++)
//	{
//		if (ans[i] != INT_MAX)
//			cout << ans[i] % 100003 << endl;
//		else
//			cout << 0 << endl;
//	}
//
//	return 0;
//}


////P1359 ������ͧ
////https://www.luogu.com.cn/problem/P1359
//
////������ͧ
//// �����ص㣺�������
//// ��Ϊ�������r(i, j)��1 <= i, j <= n;
//// ����5һ�����ǣ�0��0����
////���·��
////Flody
//
///*
//
//6
//1 2 3 
//4 5		  6 
//7		8 9
//
//
//10
//1 2 3 4
//4 5	6		7
//8 9			10 11
//12			13 14 15
//
//
//*/
//
//#define quickio ios::sync_with_stdio,cin.tie(0),cout.tie(0);
//#include <climits>
//#include <iostream>
//
//using namespace std;
//
//const int MAXN = 205;
//int board[MAXN][MAXN];
//
//int main()
//{
//	quickio;
//	int n;
//	cin >> n;
//	int i, x, j;
//
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n; j++)
//		{
//			board[i][j] = INT_MAX;
//		}
//	}
//
//	//getchar();//�����з�
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; ; j++)
//		{
//			cin >> x;
//			//if (x == '\n')
//			//	break;
//			//getchar();//���ո�
//
//			//board[i][j] = x - '0';
//		}
//	}
//
//	int min = INT_MAX, k;
//
//	for (k = 1; k <= n; k++)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			if (i == k)
//				continue;
//			for (j = 1; j <= n; j++)
//			{
//				if (board[i][j] == INT_MAX)
//					break;
//
//				if (j == k)
//					continue;
//				if (i == j)
//					continue;
//
//				if (board[i][k] != INT_MAX && board[k][j] != INT_MAX)
//				{
//					//if (board[i][j] > board[i][k] + board[k][j])
//					//	board[i][j] = board[i][k] + board[k][j];
//
//					if (board[1][n] > board[1][k] + board[k][n])
//						board[1][n] = board[1][k] + board[k][n];
//				}
//			}
//		}
//	}
//
//	cout << board[1][n]<< endl;
//	
//	return 0;
//}


//int main()
//{
//
//	return 0;
//}