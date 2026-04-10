https://www.lanqiao.cn/problems/3683/learning/
肖恩的苹果林
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long  a[N];
int n,m;

//最近距离是x是后，能放下多少颗树
bool check(int x){
  int res=1,lst=1;
  for(int i=2;i<=n;i++){
    if(a[i]-a[lst]>=x){
      res++;//这个位置种树
      lst=i;
      }
  }
  
  if(res>=m)return true;
  else return false;
}

int main(){
  cin>>n>>m;//n个位置种m颗数
  for(int i=1;i<=n;i++){
    cin>>a[i];//第 i 个可以种植苹果树的位置。
  }
  sort(a+1,a+n+1);

  //对最近距离进行二分
  long long l=0,r=1e9+10;
  while(l+1!=r){
    long long mid=(l+r)/2;
    if(check(mid))l=mid;
    else r=mid;
  }
  cout<<l<<'\n';
  return 0;
}
