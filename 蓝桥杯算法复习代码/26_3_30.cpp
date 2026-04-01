//搜索和图论







#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=N*2;
int n,m,ans;
//h相当于头指针（里面的数字，是这条链的大小），e存这个点的值，ne存下一个点的值，idx索引
int h[N],e[M],ne[M],idx;//每个头后边存的是这个节点e[M]能直接下一步走到的节点么
bool st[N];//用来存这个点是不是被访问过了


//在a后边加上b，把b加到a后边（但是这里指的是把值为a的后边加上b么？？）
void add(int a,int b){
    // h[a];ne[b]=ne[a];ne[a]=b;
    e[idx]=b,ne[idx]=ne[a],h[a]=idx++;//不是很理解
    //idx表示的是编号为这个号的节点么？？？【每次idx都是一个未存数的新空间】
}

//表示根为u点的树的节点总数量么
int dfs(int u){
    st[u]=true;//标记访问
    int res=0,sum=1,ans=0;
    for(int i=h[u];i!=-1;i=ne[i]){
        //相当于沿着h[u]为头的链遍历
        int j=e[i];
        if(!st[j]){
            int s=dfs(j);
            res=max(res,s);
            sum=sum+s;
        }
    }
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}

int main(){
    memset(h,-1,sizeof(h));//
    cin>>m;
    for((int i=0;i<m-1;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
   return 0;
}