// https://www.acwing.com/problem/content/849/   847. 图中点的层次
// 去做--》https://www.lanqiao.cn/problems/3352/  可行路径的方案数
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];

int n,m;
int d[N];//存1到N点的距离
//宽度搜索最短路径，求出1-n的最短路径
int bfs(){
    queue<int> q;
    //初始化
    memset(d,-1,sizeof(d));//初始化d为-1
    q.push(1);//队列里面存的是节点的编号
    d[1]=0;
    
    
    //搜索（前提:队列不为空）
    while(q.size()){
        //取出队头编号
        int t=q.front();q.pop();
        //搜索g[N]//遍历vector想到那个const auto 那个遍历
        for(const auto &u:g[t]){
            if(d[u]==-1){
                d[u]=d[t]+1;
                q.push(u);
            }
        }
    }
    return d[n];
    }

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    cout<<bfs()<<endl;
    return 0;
}