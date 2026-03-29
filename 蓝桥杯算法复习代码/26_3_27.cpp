#include<bits/stdc++.h>
using namespace std;
const int N=110;
int ma[N][N];//地图
int d[N][N];//用来存距离表，步数表 
int n,m;//行数和列数 
typedef pair<int,int> PII;
PII p[N*N],pre[N][N];//为什么这里队列要开N*N ,这里村的first和second是什么？？是地图的xy坐标么？？ 
//因为队列最大就是把所有的点都入队，first，second是该点的坐标
// pre用来存上一个节点，输出地图的路线
//宽度优先搜索，返回最少步数 
int bfs(){
	//利用队列的话，至少现在我得把开头起始整好，初始化好
	int hh=0,tt=0; 
	p[0]={0,0};//表示走到了00这个位置
	memset(d,-1,sizeof(d));//初始化距离数组
	d[0][0]=0;//第一步已落地
	
	int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1}; 
	while(hh<=tt){
		PII t=p[hh++];//取出队头
		//四个方向搜索并移动 
		for(int i=0;i<4;i++){
			//不能越界，必须是第一次访问，必须是路 
			int x=t.first+dx[i],y=t.second+dy[i]; 
			if(x>=0&&x<n&&y>=0&&y<m&&ma[x][y]==0&&d[x][y]==-1){
				//满足条件则移动
				d[x][y]=d[t.first][t.second]+1;
				pre[x][y]=t;//存x，y点的上一个节点
				//而且还要入队
				p[++tt]={x,y}; 
			}
		}
		 
	}
	//用来输出走的路线
	int x=n-1,y=m-1;
	while(x||y){
		cout<<x<<' '<<y<<endl;;//输出的是点的坐标
		PII t=pre[x][y];
		x=t.first,y=t.second;//pre存的是前一个点，所以给他赋的就是上一个点，一直往上追溯
	} 
	 return d[n-1][m-1];
} 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		cin>>ma[i][j]; 
	}
	cout<<bfs()<<endl;
	return 0;
} 