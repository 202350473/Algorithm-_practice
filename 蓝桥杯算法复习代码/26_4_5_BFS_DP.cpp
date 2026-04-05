//题目链接：https://www.lanqiao.cn/problems/3352/
//【学习理解版（自己敲）】【✓】
//【待二次复习】【 】



#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
vector<int> g[N];
const long long mod=1e9+7;

int d[N],dp[N];//1-n距离，1-N方案数

//返回1-n最短路径方案数量
int bfs(int x){
  queue<int> q;
  bitset<N> vis;//vis不用数组，但是当bool数组使用
  //初始化  
  memset(d,0x3f,sizeof(d));
  d[1]=0;
  q.push(1);
  dp[1]=1;
  
  while(q.size()){
    //取出队头，更新dp
    int t=q.front();q.pop();
    if(vis[t])continue;
    vis[t]=true;//如果这个点已经扩展过了，就跳过，否则标记并进行扩展
    //扩展(找下一步)部分的代码：
    //扩展做了什么，这里只看出来扩展把dp更新了，没看懂扩展对d的更新之类的，为什么？？？
    //这道题目求的是最短路径的方案数么？？还是只求路径的方案数
    for(const auto &u:g[t]){
      if(d[t]+1>d[u])continue;//翻译：（更长的路）如果t往下走一步不是u，u在更少步数就能走到，那么跳过这个u
      else if(d[t]+1==d[u]){ dp[u]=(dp[t]+dp[u])%mod;}//【更新dp】翻译：（一样长的路）t的下一步是u，到t的方案数+u的方案数=到谁的方案数；
      else {
        d[u]=d[t]+1;//【更新d】:这里是对d[]距离的更新
        dp[u]=dp[t]%mod;;//【更新dp】翻译：更短的路
        q.push(u);
      }
    }
  }

  return dp[n]%mod;;
}

int main(){
  cin>>n>>m;
  while(m--){
    int x,y;cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  cout<<bfs(1)<<endl;
  return 0;
}
