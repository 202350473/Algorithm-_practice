#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2*N;
int e[M], h[N], ne[M], idx;
int q[N],d[N]; //队列和距离 
int n,m;

//把值为b的值加到值为a的值的后面 
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];//b的下一个存a的索引 
	h[a]=idx++;//a 开头的队列 队首存b的索引 
}
 //宽度搜索，队列模拟 
int dfs(){
	int hh=0,tt=0;
	memset(d,-1,sizeof(d));
	//搜索第一步:初始化 根
	q[0]=1;//问：队列里面存的是什么
	d[1]=0;//第一个步数为0
	while(hh<=tt){
		int t=q[hh++];//取出队头
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
 cin>>n>>m;
 memset(h,-1,sizeof(h)); 
 for(int i=0;i<m;i++){
 	int a,b;
 	cin>>a>>b;
 	add(a,b);
 	add(b,a);
 }
 
 cout<<dfs()<<endl;
 return 0;	
}
//
//
//9 8
//1 2
//1 7 
//1 4
//2 8
//2 5
//4 3
//3 9
//4 6
