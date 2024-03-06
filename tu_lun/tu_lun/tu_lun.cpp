#define _CRT_SECURE_NO_WARNINGS 1
#include <queue>
#include <vector>
#include <unordered_map>
#include <set>
#include <stdio.h>
#include <iostream>

using namespace std;

////A - 拓扑排序 / 家谱树
////https://vjudge.net/contest/613618#problem/A
//
////拓扑排序：找到入度为0的点，将其写入答案，再删去其箭头，再继续找入度为0的点，循环往复
///*题解：https://blog.csdn.net/lq1990717/article/details/128322988?ops_request_misc=&request_id=&biz_id=102&utm_term=A%20-%20%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F%20/%20%E5%AE%B6%E8%B0%B1%E6%A0%91&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-128322988.142^v99^pc_search_result_base3&spm=1018.2226.3001.4187*/
//
//vector<int>edeg[101];
//int n, deg[101] = { 0 };//入度
//void init()//建图
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
//void toposort()//拓扑排序
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
//	init();//建图
//	toposort();//拓扑排序
//	return 0;
//}


//////P1347 排序
//////https://www.luogu.com.cn/problem/P1347
////
//
///*
//注意:
//exit的运用
//除了可以用map的键为vector之外，还可以用结构体
//*/
///*
//思路：
//问题1：若最深为n就判断正确
//问题2：若不能遍历完所有已存在的元素，就是有环
//问题3：
//*/
//
/////*
////若根据前x 个关系即可确定这n 个元素的顺序 yyy..y（如 ABC），输出
////
////Sorted sequence determined after xxx relations: yyy...y.
////
////若根据前x 个关系即发现存在矛盾（如A<B,B<C,C<A），输出(有环，没有一个元素的入度为0)
////
////Inconsistency found after x relations.
////
////若根据这m 个关系无法确定这n 个元素的顺序，输出
////
////Sorted sequence cannot be determined.
////*/
//
//int n, m;
//vector<char>edeg[27];
//int deg[27] = { 0 };
//char str[605][4] = { 0 };
//int have;//已经出现过的字符数量
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
题解代码：
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
int ru[MAXN];//入度
int sum;
int ans;
int k;
set<int> s1;//已出现过的字符
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
        //set::count()是C++ STL中的内置函数，它返回元素在集合中出现的次数
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


////P1038 [NOIP2003 提高组] 神经网络
////https://www.luogu.com.cn/problem/P1038
//
////有向无环图---->拓扑图----->建拓扑图------>找入度为0的点
////vector【起点】 = 终点的集合    edge//便于删指向终点的箭头
////dge数组:入度
//
//
////输出层就是没有箭头指出去的点
//
////阈值，
//// i,j,ij权值，----->像单源最短路径
//// 当前状态，初始状态
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
//unordered_map<int, int>mp;//i,阈值
//int dge[MAX] = { 0 };//入度
//int n, p;
//int C0[101] = { 0 }, C[101] = { 0 };//最初状态，目前状态
//int head[MAX];
//
//struct  W
//{
//    int val;//边权值
//    //int i;
//    int j;
//    int next;//下一个儿子
//    //int count;//指向该点的箭头数量
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
//void init()//建图
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
//    for (a = 1; a <= n; a++)//相当于公式的i
//    {
//        sum = 0;//求wc的和
//        for (b = 1; b <= n; b++)//相当于公式的j
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

//P1038 [NOIP2003 提高组] 神经网络
//https://www.luogu.com.cn/problem/P1038

//视频讲解：https://www.bilibili.com/video/BV1EE411Y71U/?spm_id_from=333.337.search-card.all.click&vd_source=41fa3a36a9ab4fa3fc7b5ff1c034346c

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
戴宇豪题解：

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


/*错误代码*/
//vector <int>edge[MAX];
//int n, p;
//int C0[101] = { 0 }, U[MAX];//最初状态,阈值
//int head[MAX];
//int in[MAX], out[MAX];//入度,出度
//int cnt;
//queue<int>que;
//
//struct  W
//{
//    int val;//边权值
//    int j;
//    int next;//下一个儿子
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
//void init()//建图
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
//        if (C0[h] > 0)//小于0也不可
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
题解：https://www.luogu.com.cn/article/ss93j1hu
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
        //这里不可以直接减，初始层也有可能有阈值，但不能减去.(题目要求)
        if(c[i]>0)
         {q.push(i);vis[i]=1;}//vis表示是否已入过队
        else c[i]-=U;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        build(u,v,w);
        out[u]=1;//out表示有无出边，用于最后找输出层
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

（修改了一点点码风）
拓扑排序时把continue的判断放到了前向星遍历之前，理论上讲（至少我现在是这么理解的）更科学一点
好吧看来看自己一年前的代码翻看自己三年前的空间一样果然惊喜不断，最后我们成功又缩短了不少，思路也更清晰了一点。
所以，既然我又加强了一下题解，何不
*/

////P4779 【模板】单源最短路径（标准版）
////https://www.luogu.com.cn/problem/P4779
//
////涉及dijkstra算法
////相关讲解链接：https://www.bilibili.com/video/BV1zz4y1m7Nq/?spm_id_from=333.337.search-card.all.click
//
////需要一个标记是否录入最短路径，记录前一个节点
////
//
//int pre[100010] = { 0 }, book[100010] = { 0 };//pre:前一个节点，book：是否被标记
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


//P3371 【模板】单源最短路径（弱化版）
//https://www.luogu.com.cn/problem/P3371

//题解：https://www.luogu.com.cn/article/oswxjzrl


///*法一：邻接矩阵*/
////占的空间较多，时间复杂度较大，不适合
//int jz[10010][10010] = { 0 };//邻接矩阵
//int st[10010] = { 0 };//是否已被标记
//int dist[10010] = { 0 };//距离起始点的最短距离
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
//    //找最短距离，标记,加入最短路径
//    for (i = 0; i < n; i++)/*注意是i < n，不是m*/
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


/*法二：结构体，堆优化*/
//要一个结构体，存一个点相关的东西（to, wei, next）(终点， 权值， 下一个儿子)
//cnt:结构体下标
//head[MAX]:head[i]:查找i点的第一个儿子
//pos:将被标记的值
//ans[MAX]:最短距离
//visit[MAX]:是否被标记过

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
//    //初始化ans
//    for (i = 1; i <= n; i++)
//        ans[i] = INT_MAX;
//
//    ans[s] = 0;
//
//    //形成有向图
//    for (i = 1; i <= m; i++)//注意i不可以从0开始啊！！！！！！！！！！！
//    {
//        cin >> u >> v >> w;
//        add(u, v, w);
//    }
//
//    int pos = s;
//    while (visit[pos] == 0)
//    {
//        visit[pos] = 1;//标记
//        int minn = INT_MAX;
//
//        //更新最短路径
//        for (i = head[pos]; i != 0; i = edge[i].next)//i != 0  :没有到最后一个儿子
//        {
//            if (visit[edge[i].to] == 0 && ans[edge[i].to] > ans[pos] + edge[i].wei)//下一个儿子到起点的距离 > 最短路径 + 下一个儿子的权值
//                ans[edge[i].to] = ans[pos] + edge[i].wei;
//        }
//
//        //找最小的
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


//自己的AC代码：
////题解：https://www.luogu.com.cn/article/oswxjzrl
//
//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//const int MAX = 1e6;
//int cnt;//结构体下标
//int visit[MAX];//标记
//int n, m, s;
//int head[MAX];//存放儿子
//int ans[MAX];//放到起点的最短距离
//
//struct EDGE
//{
//    int wei;//权值
//    int to;//目的地
//    int next;//下一个儿子
//}edge[MAX];
//
//void add(int u, int v, int w)
//{
//    cnt++;
//    edge[cnt].wei = w;
//    edge[cnt].to = v;
//    edge[cnt].next = head[u];//将下一个儿子记录
//    head[u] = cnt;//更新第一个儿子
//}
//
//int main()
//{
//    cin >> n >> m >> s;
//    int i;
//
//    //初始化ans
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
//    int pos = s;//初始化pos为s
//    while (visit[pos] == 0)
//    {
//        int minn = INT_MAX;//注意更新
//        visit[pos] = 1;//标记
//
//        //更新儿子的最短路径
//        for (i = head[pos]; i != 0; i = edge[i].next)
//        {
//            if (visit[edge[i].to] == 0 && ans[edge[i].to] > ans[pos] + edge[i].wei)
//                ans[edge[i].to] = ans[pos] + edge[i].wei;
//        }
//
//        //找最短路径
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
/*题解*/
/*
#include<iostream>
using namespace std;
int head[100000],cnt;//head[i]:存儿子，cnt:结构体下标
long long ans[1000000];//最短路径
bool vis[1000000];//标记
int m,n,s;
struct edge
{
    int to;//重点
    int nextt;//下一个儿子
    int wei;//权值
}edge[1000000];
void addedge(int x,int y,int z)
{
    edge[++cnt].to=y;//终点
    edge[cnt].wei=z;//权值
    edge[cnt].nextt=head[x];//标记儿子
    head[x]=cnt;//更新儿子
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


//P4779 【模板】单源最短路径（标准版）
//https://www.luogu.com.cn/problem/P4779

//题解：https://www.luogu.com.cn/article/s581e0wm

//友情提示:正权图  请  使用dijkstra算法,   负权图  请  使用SPFA算法

//弱化版的代码超时---->要用堆优化
/*
核心：priority_queue< pair<int,int> > 用优先队列来取最近的点，就不用遍历找点了

在pq中，是按pair的第一个元素（first）由大到小排序的，所以pair<距离，点号>，注意因为要的是最小值，所以距离要存负值
其实距离是纯纯的工具人，我们只是需要它来维持点的排序

每次取队首h，取出的就是dis最短的点
还要注意：
如果这个点的dis不等于h的dis，说明这个点在入队之后被更新了，那么我们就不用这个点了，直接continue；
因为后面会有个h2点比h1的dis更小，用h1更新就没有意义了
*/

/*
https://blog.csdn.net/m0_60544208/article/details/124807279?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170954983416800192212261%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=170954983416800192212261&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-124807279-null-null.142^v99^pc_search_result_base3&utm_term=dijkstra%E5%A0%86%E4%BC%98%E5%8C%96&spm=1018.2226.3001.4187
*/

//使用优先队列，注意：优先队列是从大到小排列，所以存进去应该存负数
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
//    priority_queue<pair<int, int> >que;//距离，点号
//    que.push({ 0, s });
//
//    while (!que.empty())
//    {
//        int qh = que.top().first;//距离
//        int h = que.top().second;//点号----->相当于没有优化的pos
//        que.pop();
//
//        if (qh + ans[h] != 0)/*说明最短路径已经更新，该数无效*/
//            /*注意：
//            如果这个点的dis不等于h的dis，说明这个点在入队之后被更新了，那么我们就不用这个点了，直接continue；
//            因为后面会有个h2点比h1的dis更小，用h1更新就没有意义了
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


////自己的AC代码：
//#include <queue>
///*堆优化：利用优先队列，降低复杂度，直接排序，注意优先队列是由大到小排列的,因此距离是负数 */
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
//    priority_queue<pair<int, int> >que;//距离，点
//    que.push({0, s});
//
//    while (!que.empty())
//    {
//        int qh = que.top().first;
//        int h = que.top().second;
//        que.pop();/*记得pop()!!!!!!!!!*/
//
//        if (visit[h] == 0)
//        {
//            visit[h] = 1;
//            for (i = head[h]; i != 0; i = edge[i].next)//不断找下一个儿子，直到找完
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
////A - 拓扑排序 / 家谱树
////https://vjudge.net/contest/613618#problem/A
//
////拓扑排序：找到入度为0的点，将其写入答案，再删去其箭头，再继续找入度为0的点，循环往复
///*题解：https://blog.csdn.net/lq1990717/article/details/128322988?ops_request_misc=&request_id=&biz_id=102&utm_term=A%20-%20%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F%20/%20%E5%AE%B6%E8%B0%B1%E6%A0%91&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-128322988.142^v99^pc_search_result_base3&spm=1018.2226.3001.4187*/
//
//vector<int>edeg[101];
//int n, deg[101] = { 0 };//入度
//void init()//建图
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
//void toposort()//拓扑排序
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
//        //相当于i表示edeg[t]的第一个元素，进行一次循环后就是第二个元素，循环往复
//        {
//            deg[i]--;
//            if (deg[i] == 0)
//            {
//                cout << i << ' ';
//                que.push(i);
//                //push的原因：可能i（也就是edeg[t]）还有箭头指向其他的数，也就是后面辈分比它小的，要通过i来找比它辈分小的
//            }
//        }
//    }
//}
//
//int main()
//{
//    init();//建图
//    toposort();//拓扑排序
//    return 0;
//}


////P1629 邮递员送信
////https://www.luogu.com.cn/problem/P1629
//
////邮局在节点 1
//
////建图：dijkstra算法，只要把返回的路线也建好就可以，
//// 
//// 法一：建两个图
//// 
//// 法二：
//// 但是要建反图，需要每个节点 + n----->原图
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