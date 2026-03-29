#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
char a[N][N];//用来输出棋盘
bool col[N],djx[2*N],fdjx[2*N]; 
void dfs(int x,int y,int s){//x,y,是当前格子的坐标，s是当前皇后的数量
//解决y越界问题
	if(y==n+1)y=1,x++;	
//出口（n需要设成全局变量）
	if(x>n){
		if(s==n){
			for(int i=1;i<=n;i++)puts(a[i]+1);
			puts("");
		} 
		return;
	}
	//当前格子放不放
	//当前格子如果放皇后的话？？
	 //这个地方是不是体现了每个格子的两个分支
	 //分支一：不放皇后
	 dfs(x,y+1,s);
	 //分支二：放皇后(得满足前提才能放吧，不是想放就能放的吧，但是后边能不能放取决于前边放的情况)
	//是不是放皇后的话，当前这一行就解决了，下一步直接到下一行就行了
	//如果不放皇后的话，下一步是下一列而已
	//这里只是处理单个格子，所以不用遍历直接判断就行吧
	if(!col[y]&&!djx[x+y]&&!fdjx[y-x+n]){
		//进来了就说明这个地方能放
		col[y]=true;
		djx[x+y]=true;
		fdjx[y-x+n]=true;
		a[x][y]='Q';//防止皇后
		dfs(x+1,1,s+1);
		col[y]=false;//恢复现场 
		djx[x+y]=false;
		fdjx[y-x+n]=false;
		a[x][y]='.';
	} 
}
int main(){
	 cin >> n;
	 for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++)a[i][j]='.';
	 }
	dfs(1,1,0);
	return 0;
} 