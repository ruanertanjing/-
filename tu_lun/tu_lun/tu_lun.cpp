#define _CRT_SECURE_NO_WARNINGS 1
#include <queue>
#include <vector>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <iostream>

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


////P1038 [NOIP2003 �����] ������
////https://www.luogu.com.cn/problem/P1038
//
////�����޻�ͼ---->����ͼ----->������ͼ------>�����Ϊ0�ĵ�
////vector����㡿 = �յ�ļ���    edge//����ɾָ���յ�ļ�ͷ
////dge����:���
//
//
////��������û�м�ͷָ��ȥ�ĵ�
//
////��ֵ��
//// i,j,ijȨֵ��----->��Դ���·��
//// ��ǰ״̬����ʼ״̬
//
//#include <queue>
//#include <vector>
//#include <iostream>
//#include <map>
//#include <unordered_map>
//
//using namespace std;
//
//const int MAX = 105;
//
//vector <int>edge[MAX];//edge[i] = {j, Wij}
//unordered_map<int, int>mp;//i,��ֵ
//int dge[MAX] = { 0 };//���
//int n, p;
//int C0[101] = { 0 }, C[101] = { 0 };//���״̬��Ŀǰ״̬
//int head[MAX];
//
//struct  W
//{
//    int val;//��Ȩֵ
//    //int i;
//    int j;
//    int next;//��һ������
//    //int count;//ָ��õ�ļ�ͷ����
//}W[MAX];
//
//void add(int i, int j, int w)
//{
//    W[i].next= head[i];
//    head[i] = j;
//    W[i].j = j;
//    W[i].val = w;
//    dge[j]++;
//    edge[i].push_back(j);
//    //W[j].count++;
//}
//
//void init()//��ͼ
//{
//    cin >> n >> p;
//    int i, j;
//    int a, x, w;
//
//    for (a = 1; a <= n; a++)
//    {
//        cin >> C0[a] >> x;
//        mp[a] = x;
//        C[a] = C0[a];
//    }
//
//    for (a = 0; a < p; a++)
//    {
//        cin >> i >> j >> w;
//        add(i, j, w);
//    }
//}
//
//void calculate()
//{
//    int  a, b, sum = 0;
//    for (a = 1; a <= n; a++)//�൱�ڹ�ʽ��i
//    {
//        sum = 0;//��wc�ĺ�
//        for (b = 1; b <= n; b++)//�൱�ڹ�ʽ��j
//        {
//            if (a == b)
//                continue;
//
//            for (int x : head[b])
//            {
//                sum += C[b] * W[b].val;
//            }
//        }
//        C[a] = sum - mp[a];
//    }
//}
//
//int main()
//{
//    init();
//    calculate();
//    int a;
//    for (a = 1; a <= n; a++)
//    {
//        if ()
//    }
//    return 0;
//}

//P1038 [NOIP2003 �����] ������
//https://www.luogu.com.cn/problem/P1038

//��Ƶ���⣺https://www.bilibili.com/video/BV1EE411Y71U/?spm_id_from=333.337.search-card.all.click&vd_source=41fa3a36a9ab4fa3fc7b5ff1c034346c

#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

const int MAX = 105;
int n, p;
int cnt;
int c[MAX], u[MAX];
int in[MAX], out[MAX];
int head[MAX];
int vis[MAX];/**/
queue<int>que;

struct W
{
    int to;
    int val;
    int next;
}W[MAX];

void add(int u, int v, int w)
{
    cnt++;
    W[u].to = v;
    W[u].val = w;
    W[u].next = head[u];
    head[u] = cnt;
}

void init()
{
    cin >> n >> p;

    int i;
    for (i = 1; i <= n; i++)
    {
        cin >> c[i] >> u[i];
        if (c[i] == 0)
            c[i] -= u[i];
        else
        {
            que.push(i);
            //vis[i] = 1;
        }
    }

    int u, v, w;
    for (i = 1; i <= p; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        in[v]++;
        out[u]++;
    }
}

void toposort()
{
    int i;

    while (!que.empty())
    {
        int h = que.front();
        que.pop();

        if (c[h] > 0)
        {
            int t;
            for (i = head[h]; i != 0; i = W[i].next)
            {
                t = W[i].to;

                c[t] += c[h] * W[i].val;
                in[t]--;

                if (/*vis[t] == 0 && */in[t] == 0)
                {
                    que.push(t);
                  /*  vis[t] = 1;*/
                }
            }
        }
    }
}

int main()
{
    init();
    toposort();

    int i;
    int flag = 0;
    for (i = 1; i <= n; i++)
    {
        if (out[i] == 0 && c[i] > 0)
        {
            cout << i << ' ' << c[i] << endl;
            flag = 1;
        }
    }

    if (flag == 0)
        cout << "NULL" << endl;
    return 0;
}


/*
�������⣺

#include<queue>
#include<cstdio>
#include<algorithm>
#define N 101

using namespace std;

struct edge{
    int to,
    val,
    nxt;
} e[N*N];

int h,i,m,n,t,u,v,w,U,c[N],hd[N],out[N],vis[N];
queue <int> q;
int cnt=0,flag=0;

 inline void build(int u,int v,int w)
 {
     cnt++;
     e[cnt].to=v;
     e[cnt].val=w;
     e[cnt].nxt=hd[u];
     hd[u]=cnt;
 }
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        vis[i]=out[i]=0;
        scanf("%d%d",&c[i],&U);

        if(c[i]>0)
         {q.push(i);vis[i]=1;}
        else c[i]-=U;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        build(u,v,w);
        out[u]=1;
    }
    while(!q.empty())
    {
        h=q.front();
        q.pop();
        if(c[h]<=0)
            continue;

        for(i=hd[h];i;i=e[i].nxt)
        {
            t=e[i].to;
            c[t]+=e[i].val*c[h];
            if(!vis[t])
            {
                q.push(t);
                vis[t]=1;
            }
        }
    }
    for(i=1;i<=n;i++)
     if(!out[i]&&c[i]>0)
      {printf("%d %d\n",i,c[i]);flag=1;}
    if(!flag) {puts("NULL");return 0;}

}
*/


/*�������*/
//vector <int>edge[MAX];
//int n, p;
//int C0[101] = { 0 }, U[MAX];//���״̬,��ֵ
//int head[MAX];
//int in[MAX], out[MAX];//���,����
//int cnt;
//queue<int>que;
//
//struct  W
//{
//    int val;//��Ȩֵ
//    int j;
//    int next;//��һ������
//}W[MAX];
//
//void add(int i, int j, int w)
//{
//    cnt++;
//    W[i].j = j;
//    W[i].val = w;
//    W[i].next = head[i];
//    head[i] = j;
//}
//
//void init()//��ͼ
//{
//    cin >> n >> p;
//    int i, j;
//    int a, x, w;
//
//    for (a = 1; a <= n; a++)
//    {
//        cin >> C0[a] >> U[a];
//        
//        if (C0[a] == 0)
//            C0[a] -= U[a];
//    }
//
//    for (a = 0; a < p; a++)
//    {
//        cin >> i >> j >> w;
//        add(i, j, w);
//        in[j]++;
//        out[i]++;
//    }
//}
//
//void toposort()
//{
//
//    int a;
//    for (a = 1; a <= n; a++)
//    {
//        if (C0[a])
//            que.push(a);
//    }
//
//    while (que.size() < n)
//    {
//        int ph = que.front();
//
//        for (int i : edge[ph])
//        {
//            //C0[i] += C0[ph] * W[i].val;
//            in[i]--;
//            if (in[i] == 0)
//                que.push(i);
//        }
//    }
//}
//
//int main()
//{
//    init();
//    toposort();
//
//    int i, b;
//
//    for (i = 1; i <= n; i++)
//    {
//        int h = que.front();
//        que.pop();
//
//        if (C0[h] > 0)//С��0Ҳ����
//        {
//            for (b = head[h]; b; b = W[b].next)
//            {
//                int t = W[b].j;
//                C0[t] += C0[h] * W[t].val;
//            }
//        }
//    }
//    for (i = 1; i <= n; i++)
//    {
//        if (out[i] == 0)
//        {
//            cout << i << ' '<< C0[i] << endl ;
//        }
//    }
//    return 0;
//}


/*
��⣺https://www.luogu.com.cn/article/ss93j1hu
*/

/*
#include<queue>
#include<cstdio>
#include<algorithm>
#define N 101
using namespace std;
struct edge{
    int to,val,nxt;//
} e[N*N];
struct answer{
    int id,val;
} ans[N];
int h,i,m,n,t,u,v,w,U,c[N],hd[N],out[N],vis[N];
queue <int> q;
int cnt=0,flag=0;
 inline bool cmp(answer aa,answer bb)
  {return aa.id<bb.id;}
 inline void build(int u,int v,int w)
 {
    cnt++;
    e[cnt].to=v;
    e[cnt].val=w;
    e[cnt].nxt=hd[u];
    hd[u]=cnt;
 }
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        vis[i]=out[i]=0;
        scanf("%d%d",&c[i],&U);
        //���ﲻ����ֱ�Ӽ�����ʼ��Ҳ�п�������ֵ�������ܼ�ȥ.(��ĿҪ��)
        if(c[i]>0)
         {q.push(i);vis[i]=1;}//vis��ʾ�Ƿ��������
        else c[i]-=U;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        build(u,v,w);
        out[u]=1;//out��ʾ���޳��ߣ���������������
    }
    while(!q.empty())
    {
        h=q.front();q.pop();
        if(c[h]<=0) continue;
        for(i=hd[h];i;i=e[i].nxt)
        {
            t=e[i].to;
            c[t]+=e[i].val*c[h];
            if(!vis[t])
            {
                q.push(t);
                vis[t]=1;
            }
        }
    }
    for(i=1;i<=n;i++)
     if(!out[i]&&c[i]>0)
      {printf("%d %d\n",i,c[i]);flag=1;}
    if(!flag) {puts("NULL");return 0;}
    return 0;
}

���޸���һ�����磩
��������ʱ��continue���жϷŵ���ǰ���Ǳ���֮ǰ�������Ͻ�����������������ô���ģ�����ѧһ��
�ðɿ������Լ�һ��ǰ�Ĵ��뷭���Լ�����ǰ�Ŀռ�һ����Ȼ��ϲ���ϣ�������ǳɹ��������˲��٣�˼·Ҳ��������һ�㡣
���ԣ���Ȼ���ּ�ǿ��һ����⣬�β�
*/

////P4779 ��ģ�塿��Դ���·������׼�棩
////https://www.luogu.com.cn/problem/P4779
//
////�漰dijkstra�㷨
////��ؽ������ӣ�https://www.bilibili.com/video/BV1zz4y1m7Nq/?spm_id_from=333.337.search-card.all.click
//
////��Ҫһ������Ƿ�¼�����·������¼ǰһ���ڵ�
////
//
//int pre[100010] = { 0 }, book[100010] = { 0 };//pre:ǰһ���ڵ㣬book���Ƿ񱻱��
//int n, m, s;
//
//void fresh(int u, int v, int w, int i)
//{
//
//}
//
//int main()
//{
//    scanf("%d%d%d", &n, &m, &s);
//    int i;
//    int u, v, w;
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d%d%d", &u, &v, &w);
//        fresh(u, v, w, i);
//    }
//
//    return 0;
//}
//
//
///*
//const int MaxN = 100010, MaxM = 500010;
//
//struct edge
//{
//    int to, dis, next;
//};
//
//edge e[MaxM];
//int head[MaxN], dis[MaxN], cnt;
//bool vis[MaxN];
//int n, m, s;
//
//inline void add_edge( int u, int v, int d )
//{
//    cnt++;
//    e[cnt].dis = d;
//    e[cnt].to = v;
//    e[cnt].next = head[u];
//    head[u] = cnt;
//}
//
//struct node
//{
//    int dis;
//    int pos;
//    bool operator <( const node &x )const
//    {
//        return x.dis < dis;
//    }
//};
//
//std::priority_queue<node> q;
//
//
//inline void dijkstra()
//{
//    dis[s] = 0;
//    q.push( ( node ){0, s} );
//    while( !q.empty() )
//    {
//        node tmp = q.top();
//        q.pop();
//        int x = tmp.pos, d = tmp.dis;
//        if( vis[x] )
//            continue;
//        vis[x] = 1;
//        for( int i = head[x]; i; i = e[i].next )
//        {
//            int y = e[i].to;
//            if( dis[y] > dis[x] + e[i].dis )
//            {
//                dis[y] = dis[x] + e[i].dis;
//                if( !vis[y] )
//                {
//                    q.push( ( node ){dis[y], y} );
//                }
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    scanf( "%d%d%d", &n, &m, &s );
//    for(int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
//    for( register int i = 0; i < m; ++i )
//    {
//        register int u, v, d;
//        scanf( "%d%d%d", &u, &v, &d );
//        add_edge( u, v, d );
//    }
//    dijkstra();
//    for( int i = 1; i <= n; i++ )
//        printf( "%d ", dis[i] );
//    return 0;
//}
//
//*/


//P3371 ��ģ�塿��Դ���·���������棩
//https://www.luogu.com.cn/problem/P3371

//��⣺https://www.luogu.com.cn/article/oswxjzrl


///*��һ���ڽӾ���*/
////ռ�Ŀռ�϶࣬ʱ�临�ӶȽϴ󣬲��ʺ�
//int jz[10010][10010] = { 0 };//�ڽӾ���
//int st[10010] = { 0 };//�Ƿ��ѱ����
//int dist[10010] = { 0 };//������ʼ�����̾���
//int n, m, s;
//
//void dijkstra()
//{
//    int i, j;
//
//    //for (i = 0; i < n; i++)
//    //    dist[i] = INT_MAX;
//    memset(dist, 0x3f, sizeof(dist));
//    dist[s] = 0;
//
//
//    //����̾��룬���,�������·��
//    for (i = 0; i < n; i++)/*ע����i < n������m*/
//    {
//        int t = -1;
//        for (j = 0; j < n; j++)
//        {
//            if (st[j] == 0 && (t == -1 || dist[j] < dist[t]))
//                t = j;
//        }
//
//        st[t] = 1;
//
//        for (j = 0; j < n; j++)
//        {
//            dist[j] = min(dist[j], dist[t] + jz[t][j]);
//        }
//    }
//}
//
//int main()
//{
//    cin >> n >> m >> s;
//    int u, v, w, i;
//    memset(jz, 0x3f, sizeof(jz));
//
//    for (i = 0; i < m; i++)
//    {
//        cin >> u >> v >> s;
//        jz[u][v] = min(jz[u][v], s);
//    }
//
//    dijkstra();
//    for (i = 0; i < n; i++)
//    {
//        if (dist[i] == 0x3f3f3f3f)
//            dist[i] = INT_MAX;
//        cout << dist[i] << ' ';
//    }
//    cout << endl;
//    return 0;
//}


/*�������ṹ�壬���Ż�*/
//Ҫһ���ṹ�壬��һ������صĶ�����to, wei, next��(�յ㣬 Ȩֵ�� ��һ������)
//cnt:�ṹ���±�
//head[MAX]:head[i]:����i��ĵ�һ������
//pos:������ǵ�ֵ
//ans[MAX]:��̾���
//visit[MAX]:�Ƿ񱻱�ǹ�

//const int MAX = 1e6;
//int n, m, s;
//int cnt;
//int head[MAX];
//int visit[MAX];
//int ans[MAX];
//
//struct EDGE
//{
//    int to;
//    int next;
//    int wei;
//}edge[MAX];
//
//void add(int u, int v, int w)
//{
//    cnt++;
//    edge[cnt].wei = w;
//    edge[cnt].to = v;
//    edge[cnt].next = head[u];
//    head[u] = cnt;
//}
//
//int main()
//{
//    cin >> n >> m >> s;
//    int u, v, w;
//    int i;
//
//    //��ʼ��ans
//    for (i = 1; i <= n; i++)
//        ans[i] = INT_MAX;
//
//    ans[s] = 0;
//
//    //�γ�����ͼ
//    for (i = 1; i <= m; i++)//ע��i�����Դ�0��ʼ������������������������
//    {
//        cin >> u >> v >> w;
//        add(u, v, w);
//    }
//
//    int pos = s;
//    while (visit[pos] == 0)
//    {
//        visit[pos] = 1;//���
//        int minn = INT_MAX;
//
//        //�������·��
//        for (i = head[pos]; i != 0; i = edge[i].next)//i != 0  :û�е����һ������
//        {
//            if (visit[edge[i].to] == 0 && ans[edge[i].to] > ans[pos] + edge[i].wei)//��һ�����ӵ����ľ��� > ���·�� + ��һ�����ӵ�Ȩֵ
//                ans[edge[i].to] = ans[pos] + edge[i].wei;
//        }
//
//        //����С��
//        for (i = 1; i <= n; i++)
//        {
//            if (visit[i] == 0 && ans[i] < minn)
//            {
//                minn = ans[i];
//                pos = i;
//            }
//        }
//    }
//
//    for (i = 1; i <= n; i++)
//        cout << ans[i] << ' ';
//    cout << endl;
//    return 0;
//}


//�Լ���AC���룺
////��⣺https://www.luogu.com.cn/article/oswxjzrl
//
//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//const int MAX = 1e6;
//int cnt;//�ṹ���±�
//int visit[MAX];//���
//int n, m, s;
//int head[MAX];//��Ŷ���
//int ans[MAX];//�ŵ�������̾���
//
//struct EDGE
//{
//    int wei;//Ȩֵ
//    int to;//Ŀ�ĵ�
//    int next;//��һ������
//}edge[MAX];
//
//void add(int u, int v, int w)
//{
//    cnt++;
//    edge[cnt].wei = w;
//    edge[cnt].to = v;
//    edge[cnt].next = head[u];//����һ�����Ӽ�¼
//    head[u] = cnt;//���µ�һ������
//}
//
//int main()
//{
//    cin >> n >> m >> s;
//    int i;
//
//    //��ʼ��ans
//    for (i = 1; i <= n; i++)
//        ans[i] = INT_MAX;
//
//    ans[s] = 0;
//
//    int u, v, w;
//    for (i = 1; i <= m; i++)
//    {
//        cin >> u >> v >> w;
//        add(u, v, w);
//    }
//
//    int pos = s;//��ʼ��posΪs
//    while (visit[pos] == 0)
//    {
//        int minn = INT_MAX;//ע�����
//        visit[pos] = 1;//���
//
//        //���¶��ӵ����·��
//        for (i = head[pos]; i != 0; i = edge[i].next)
//        {
//            if (visit[edge[i].to] == 0 && ans[edge[i].to] > ans[pos] + edge[i].wei)
//                ans[edge[i].to] = ans[pos] + edge[i].wei;
//        }
//
//        //�����·��
//        for (i = 1; i <= n; i++)
//        {
//            if (visit[i] == 0 && ans[i] < minn)
//            {
//                minn = ans[i];
//                pos = i;
//            }
//        }
//    }
//
//    for (i = 1; i <= n; i++)
//        cout << ans[i] << ' ';
//    cout << endl;
//    return 0;
//}
/*���*/
/*
#include<iostream>
using namespace std;
int head[100000],cnt;//head[i]:����ӣ�cnt:�ṹ���±�
long long ans[1000000];//���·��
bool vis[1000000];//���
int m,n,s;
struct edge
{
    int to;//�ص�
    int nextt;//��һ������
    int wei;//Ȩֵ
}edge[1000000];
void addedge(int x,int y,int z)
{
    edge[++cnt].to=y;//�յ�
    edge[cnt].wei=z;//Ȩֵ
    edge[cnt].nextt=head[x];//��Ƕ���
    head[x]=cnt;//���¶���
}
int main()
{
    cin>>m>>n>>s;
    for(int i=1;i<=n;i++)
    {
        ans[i]=2147483647;
    }
    ans[s]=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
    }
    int pos=s;
    while(vis[pos]==0)
    {
        long long minn=2147483647;
        vis[pos]=1;
        for(int i=head[pos];i!=0;i=edge[i].nextt)
        {
            if(!vis[edge[i].to]&&ans[edge[i].to]>ans[pos]+edge[i].wei)
            {
                ans[edge[i].to]=ans[pos]+edge[i].wei;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(ans[i]<minn&&vis[i]==0)
            {
                minn=ans[i];
                pos=i;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
}
*/


//P4779 ��ģ�塿��Դ���·������׼�棩
//https://www.luogu.com.cn/problem/P4779

//��⣺https://www.luogu.com.cn/article/s581e0wm

//������ʾ:��Ȩͼ  ��  ʹ��dijkstra�㷨,   ��Ȩͼ  ��  ʹ��SPFA�㷨

//������Ĵ��볬ʱ---->Ҫ�ö��Ż�
/*
���ģ�priority_queue< pair<int,int> > �����ȶ�����ȡ����ĵ㣬�Ͳ��ñ����ҵ���

��pq�У��ǰ�pair�ĵ�һ��Ԫ�أ�first���ɴ�С����ģ�����pair<���룬���>��ע����ΪҪ������Сֵ�����Ծ���Ҫ�渺ֵ
��ʵ�����Ǵ����Ĺ����ˣ�����ֻ����Ҫ����ά�ֵ������

ÿ��ȡ����h��ȡ���ľ���dis��̵ĵ�
��Ҫע�⣺
���������dis������h��dis��˵������������֮�󱻸����ˣ���ô���ǾͲ���������ˣ�ֱ��continue��
��Ϊ������и�h2���h1��dis��С����h1���¾�û��������
*/

/*
https://blog.csdn.net/m0_60544208/article/details/124807279?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170954983416800192212261%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=170954983416800192212261&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-124807279-null-null.142^v99^pc_search_result_base3&utm_term=dijkstra%E5%A0%86%E4%BC%98%E5%8C%96&spm=1018.2226.3001.4187
*/

//ʹ�����ȶ��У�ע�⣺���ȶ����ǴӴ�С���У����Դ��ȥӦ�ô渺��
//#include <queue>
//#include <climits>
//
//const int MAX = 1e6;
//int n, m, s;
//int ans[MAX];
//int cnt;
//int head[MAX];
//
//struct EDGE
//{
//    int next;
//    int wei;
//    int to;
//}edge[MAX];
//
//void add(int u, int v, int w)
//{
//    cnt++;
//    edge[cnt].to = v;
//    edge[cnt].wei = w;
//    edge[cnt].next = head[u];
//    head[u] = cnt;
//}
//
//int main()
//{
//    cin >> n >> m >> s;
//
//    int u, v, w;
//    int i;
//    
//    for (i = 1; i <= m; i++)
//    {
//        cin >> u >> v >> w;
//        add(u, v, w);
//    }
//
//    for (i = 1; i <= n; i++)
//        ans[i] = INT_MAX;
//    ans[s] = 0;
//
//    priority_queue<pair<int, int> >que;//���룬���
//    que.push({ 0, s });
//
//    while (!que.empty())
//    {
//        int qh = que.top().first;//����
//        int h = que.top().second;//���----->�൱��û���Ż���pos
//        que.pop();
//
//        if (qh + ans[h] != 0)/*˵�����·���Ѿ����£�������Ч*/
//            /*ע�⣺
//            ���������dis������h��dis��˵������������֮�󱻸����ˣ���ô���ǾͲ���������ˣ�ֱ��continue��
//            ��Ϊ������и�h2���h1��dis��С����h1���¾�û��������
//            */
//            continue;
//
//        for (i = head[h]; i != 0; i = edge[i].next)
//        {
//            if (ans[edge[i].to] > ans[h] + edge[i].wei)
//            {
//                ans[edge[i].to] = ans[h] + edge[i].wei;
//                que.push({ - ans[edge[i].to], edge[i].to });
//            }
//        }
//    }
//
//    for (i = 1; i <= n; i++)
//        cout << ans[i] << ' ';
//
//    cout << endl;
//
//    return 0;
//}


////�Լ���AC���룺
//#include <queue>
///*���Ż����������ȶ��У����͸��Ӷȣ�ֱ������ע�����ȶ������ɴ�С���е�,��˾����Ǹ��� */
//#include <climits>
//#include <iostream>
//
//using namespace std;
//
//const int MAX = 1e6;
//int n, m, s;
//int ans[MAX];
//int cnt;
//int head[MAX];
//int visit[MAX];
//
//struct EDGE
//{
//    int to;
//    int next;
//    int wei;
//}edge[MAX];
//
//void add(int u, int v, int w)
//{
//    cnt++;
//    edge[cnt].wei = w;
//    edge[cnt].to = v;
//    edge[cnt].next = head[u];
//    head[u] = cnt;
//}
//
//int main()
//{
//    int i;
//    int u, v, w;
//    cin >> n >> m >> s;
//
//    for (i = 1; i <= n; i++)
//        ans[i] = INT_MAX;
//    ans[s] = 0;
//
//    for (i = 1; i <= m; i++)
//    {
//        cin >> u >> v >> w;
//        add(u, v, w);
//    }
//
//    priority_queue<pair<int, int> >que;//���룬��
//    que.push({0, s});
//
//    while (!que.empty())
//    {
//        int qh = que.top().first;
//        int h = que.top().second;
//        que.pop();/*�ǵ�pop()!!!!!!!!!*/
//
//        if (visit[h] == 0)
//        {
//            visit[h] = 1;
//            for (i = head[h]; i != 0; i = edge[i].next)//��������һ�����ӣ�ֱ������
//            {
//                if (ans[edge[i].to] > ans[h] + edge[i].wei)
//                {
//                    ans[edge[i].to] = ans[h] + edge[i].wei;
//                    if (visit[edge[i].to] == 0)
//                        que.push({ -ans[edge[i].to], edge[i].to });
//
//                }
//            }
//        }
//    }
//
//    for (i = 1; i <= n; i++)
//        cout << ans[i] << ' ';
//    cout << endl;
//    return 0;
//}


//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
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
//    cin >> n;
//    int i, val;
//    for (i = 1; i <= n; i++)
//    {
//        while (cin >> val && val != 0)
//        {
//            edeg[i].push_back(val);
//            deg[val]++;
//        }
//    }
//}
//
//void toposort()//��������
//{
//    int i;
//    queue<int> que;
//    for (i = 1; i <= n; i++)
//    {
//        if (deg[i] == 0)
//        {
//            cout << i << ' ';
//            que.push(i);
//        }
//    }
//
//    while (!que.empty())
//    {
//        int t = que.front();
//        que.pop();
//
//        for (int i : edeg[t])
//        //�൱��i��ʾedeg[t]�ĵ�һ��Ԫ�أ�����һ��ѭ������ǵڶ���Ԫ�أ�ѭ������
//        {
//            deg[i]--;
//            if (deg[i] == 0)
//            {
//                cout << i << ' ';
//                que.push(i);
//                //push��ԭ�򣺿���i��Ҳ����edeg[t]�����м�ͷָ������������Ҳ���Ǻ��汲�ֱ���С�ģ�Ҫͨ��i���ұ�������С��
//            }
//        }
//    }
//}
//
//int main()
//{
//    init();//��ͼ
//    toposort();//��������
//    return 0;
//}


////P1629 �ʵ�Ա����
////https://www.luogu.com.cn/problem/P1629
//
////�ʾ��ڽڵ� 1
//
////��ͼ��dijkstra�㷨��ֻҪ�ѷ��ص�·��Ҳ���þͿ��ԣ�
//// 
//// ��һ��������ͼ
//// 
//// ������
//// ����Ҫ����ͼ����Ҫÿ���ڵ� + n----->ԭͼ
//
//#include <iostream>
//#include <climits>
//#include <queue>
//#include <string.h>
//
//using namespace std;
//
//const int MAX = 1e4;
//int visit[MAX];
//int cnt;
//int ans[MAX];
//int head[MAX];
//
//struct EDGE
//{
//    int to;
//    int next;
//    int wei;
//}edge[MAX];
//
//void add(int u, int v, int w)
//{
//    cnt++;
//    edge[cnt].to = v;
//    edge[cnt].wei = w;
//    edge[cnt].next = head[u];
//    head[u] = cnt;
//}
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    memset(ans, 0x3f, sizeof(ans));
//    int i;
//    int u, v, w;
//    for (i = 1; i <= m; i++)
//    {
//        cin >> u >> v >> w;
//        add(u, v, w);
//
//    }
//    return 0;
//}