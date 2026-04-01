// https://www.luogu.com.cn/problem/P1395

#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,M=N*2;
int h[M],e[N],ne[M],idx;
int d[N],q[N];//d是距离，q是队列
 int n;

void add(int a,int b){
    e[idx]=b; 
    ne[idx]=h[a];
    h[a]=idx;
}

//宽度搜索
int dfs(){
    int hh=0,tt=0;
    q[0]=1;
    memset(d,-1,sizeof(d));
    d[1]=0;
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]==-1){
                d[j]=d[t]+1;
                q[++tt]=j;
            }
        }
    }
    return d[n];
}

int main(){
   cin>>n;
    memset(h,-1,sizeof(h));
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);add(b,a);
    }
    cout<<dfs()<<endl;
    return 0;

}
