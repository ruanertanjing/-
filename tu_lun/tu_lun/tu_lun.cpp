#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <set>
#include <stdio.h>

using namespace std;

////A - �������� / ������
////https://vjudge.net/contest/613618#problem/A
//
////���������ҵ����Ϊ0�ĵ㣬����д��𰸣���ɾȥ���ͷ���ټ��������Ϊ0�ĵ㣬ѭ������
///*��⣺https://blog.csdn.net/lq1990717/article/details/128322988?ops_request_misc=&request_id=&biz_id=102&utm_term=A%20-%20%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F%20/%20%E5%AE%B6%E8%B0%B1%E6%A0%91&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-128322988.142^v99^pc_search_result_base3&spm=1018.2226.3001.4187*/
//
//vector<int>edeg[101];
//int n, deg[101] = { 0 };//���
//void init()//��ͼ
//{
//	cin >> n;
//	int i, val;
//	for (i = 1; i <= n; i++)
//	{
//		while (cin >> val && val != 0)
//		{
//			edeg[i].push_back(val);
//			deg[val]++;
//		}
//	}
//}
//
//void toposort()//��������
//{
//	int i;
//	queue<int> que;
//	for (i = 1; i <= n; i++)
//	{
//		if (deg[i] == 0)
//		{
//			cout << i << ' ';
//			que.push(i);
//		}
//	}
//
//	while (!que.empty())
//	{
//		int t = que.front();
//		que.pop();
//
//		for (int i : edeg[t])
//		{
//			deg[i]--;
//			if (deg[i] == 0)
//			{
//				cout << i << ' ';
//				que.push(i);
//			}
//		}
//	}
//}
//
//int main()
//{
//	init();//��ͼ
//	toposort();//��������
//	return 0;
//}


//////P1347 ����
//////https://www.luogu.com.cn/problem/P1347
////
//
///*
//ע��:
//exit������
//���˿�����map�ļ�Ϊvector֮�⣬�������ýṹ��
//*/
///*
//˼·��
//����1��������Ϊn���ж���ȷ
//����2�������ܱ����������Ѵ��ڵ�Ԫ�أ������л�
//����3��
//*/
//
/////*
////������ǰx ����ϵ����ȷ����n ��Ԫ�ص�˳�� yyy..y���� ABC�������
////
////Sorted sequence determined after xxx relations: yyy...y.
////
////������ǰx ����ϵ�����ִ���ì�ܣ���A<B,B<C,C<A�������(�л���û��һ��Ԫ�ص����Ϊ0)
////
////Inconsistency found after x relations.
////
////��������m ����ϵ�޷�ȷ����n ��Ԫ�ص�˳�����
////
////Sorted sequence cannot be determined.
////*/
//
//int n, m;
//vector<char>edeg[27];
//int deg[27] = { 0 };
//char str[605][4] = { 0 };
//int have;//�Ѿ����ֹ����ַ�����
//set<int> s1;
//
//void init()
//{
//	int  i;
//	cin >> n;
//	cin >> m;
//
//	for (i = 1; i <= m; i++)
//	{
//		scanf("%s", str[i]);
//		edeg[str[i][0] - 'A'].push_back(str[i][2] - 'A');
//		deg[str[i][2] - 'A']++;
//        s1.insert(str[i][0] - 'A');
//        s1.insert(str[i][2] - 'A');
//        have = s1.size();
//
//	}
//}
//
//void toposort()
//{
//	int i;
//	for (i = 0; i < m; i++)
//	{
//        if (deg[str[i][0]]);
//	}
//}
//int main()
//{
//	init();
//	toposort();
//	
//	return 0;
//}

/*
�����룺
#include <bits/stdc++.h>
#define MAXN 50
using namespace std;
int n,m;
struct Node{
    int u;
    int val;
    Node(int u=0,int val=0):u(u),val(val){}
};
vector<int> vec[MAXN];
int ru[MAXN];//���
int sum;
int ans;
int k;
set<int> s1;//�ѳ��ֹ����ַ�
void make(){
    queue<int> q;
    int ru1[MAXN];
    memset(ru1,0,sizeof(ru1));
    for(int i=0; i<26; i++){
        for(int j=0; j<vec[i].size(); j++){
            ru1[vec[i][j]]++;
        }
    }
    for(int i=0; i<26; i++){
        if(ru1[i]==0&&s1.count(i)){
        //set::count()��C++ STL�е����ú�����������Ԫ���ڼ����г��ֵĴ���
            q.push(i);
            cout<<char(i+'A');
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<vec[u].size(); i++){
            int v=vec[u][i];
            ru1[v]--;
            if(ru1[v]==0){
                q.push(v);
                cout<<char(v+'A');
            }
        }
    }
}
int have;
void topo(){
    queue<Node> q;
    for(int i=0; i<26; i++){
        if(ru[i]==0&&s1.count(i)){
            q.push(Node(i,1));
            sum++;
        }
    }
    while(!q.empty()){
        int u=q.front().u;
        int val=q.front().val;
        q.pop();
        for(int i=0; i<vec[u].size(); i++){
            int v=vec[u][i];
            ru[v]--;
            if(ru[v]==0){
                sum++;
                q.push(Node(v,val+1));
                ans=max(ans,val+1);
            }
        }
    }
    if(ans==n){
        printf("Sorted sequence determined after %d relations: ",k);
        make();
        cout<<".";
        exit(0);
    }
    if(sum!=have){
        printf("Inconsistency found after %d relations.",k);
        exit(0);
    }
}
int ru2[MAXN];
int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        string s;
        cin>>s;
        k=i;
        vec[s[0]-'A'].push_back(s[2]-'A');
        s1.insert(s[0]-'A');
        s1.insert(s[2]-'A');
        have=s1.size();
        ru2[s[2]-'A']++;
        sum=0;
        ans=0;
        memcpy(ru,ru2,sizeof(ru2));
        topo();
    }
    printf("Sorted sequence cannot be determined.");
    return 0;
}

*/


//P4779 ��ģ�塿��Դ���·������׼�棩
//https://www.luogu.com.cn/problem/P4779

//�漰dijkstra�㷨
//��ؽ������ӣ�https://www.bilibili.com/video/BV1zz4y1m7Nq/?spm_id_from=333.337.search-card.all.click

//��Ҫһ������Ƿ�¼�����·������¼ǰһ���ڵ�
//

int pre[100010] = { 0 }, book[100010] = { 0 };//pre:ǰһ���ڵ㣬book���Ƿ񱻱��
int n, m, s;

void fresh(int u, int v, int w, int i)
{

}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    int i;
    int u, v, w;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        fresh(u, v, w, i);
    }

    return 0;
}


/*
const int MaxN = 100010, MaxM = 500010;

struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
int n, m, s;

inline void add_edge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

std::priority_queue<node> q;


inline void dijkstra()
{
    dis[s] = 0;
    q.push( ( node ){0, s} );
    while( !q.empty() )
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if( vis[x] )
            continue;
        vis[x] = 1;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( dis[y] > dis[x] + e[i].dis )
            {
                dis[y] = dis[x] + e[i].dis;
                if( !vis[y] )
                {
                    q.push( ( node ){dis[y], y} );
                }
            }
        }
    }
}


int main()
{
    scanf( "%d%d%d", &n, &m, &s );
    for(int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
    for( register int i = 0; i < m; ++i )
    {
        register int u, v, d;
        scanf( "%d%d%d", &u, &v, &d );
        add_edge( u, v, d );
    }
    dijkstra();
    for( int i = 1; i <= n; i++ )
        printf( "%d ", dis[i] );
    return 0;
}

*/