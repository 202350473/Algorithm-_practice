#include<bits/stdc++.h>
using namespace std;
const int N=110; 
int n,m;//n，m表示行和列 
int a[N][N];//用a来表示地图
int d[N][N];//用来存距离d秒距离d，里面最大的值就是最短的路径吧
typedef pair<int,int> PII;//重命名 
PII q[N*N]; 
//用了队列的思想，是怎么回事。？？？这个队列的理解？？？ 
 int bfs(){//dfs 返回最短路径长度
  	int hh=0,tt=0;//应该可以理解为头指针和尾指针队头队尾吧 
  	q[0]={0,0};
  	memset(d,-1,sizeof(d));//所有d初始化为-1
	d[0][0]=0;//表示00位置已经访问
	
	int dx[4]={-1,0,1,0} ,dy[4]={0,1,0,-1};
	while(hh<=tt){
		PII t=q[hh++];//取出队头给t
		//尝试移动上下左右
		for(int i=0;i<4;i++){
			int x=t.first+dx[i];
			int y=t.second+dy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]==0&&d[x][y]==-1){
				d[x][y]=d[t.first][t.second]+1;
				q[++tt]={x,y};	
			}
		}		 
		
	}   
 	return d[n-1][m-1];
 }
int main(){
	cin >>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)cin >> a[i][j]; 
	cout<<bfs()<<endl;
	return 0; 
}
//
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
