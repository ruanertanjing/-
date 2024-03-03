#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <set>
#include <stdio.h>

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


//P4779 【模板】单源最短路径（标准版）
//https://www.luogu.com.cn/problem/P4779

//涉及dijkstra算法
//相关讲解链接：https://www.bilibili.com/video/BV1zz4y1m7Nq/?spm_id_from=333.337.search-card.all.click

//需要一个标记是否录入最短路径，记录前一个节点
//

int pre[100010] = { 0 }, book[100010] = { 0 };//pre:前一个节点，book：是否被标记
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