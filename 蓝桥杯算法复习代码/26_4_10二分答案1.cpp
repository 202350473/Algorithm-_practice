https://www.lanqiao.cn/problems/364/learning/
跳石头 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int l,n,m;
//当最短跳跃距离是m的时候，需要移走的石头数量是否超过M
bool check(int dd){
  int k=0,lst=0;
  for(int i=1;i<=n;i++){
    if(a[i]-a[lst]<dd){
      k++;
      }
      else lst=i;
  }
  //最后一块到终点
  if(l-a[lst]<dd)k++;//最后一个测试用例的关键之处
  if(k>m)return false;
  else return true;
}
int main(){
  cin>>l>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  //二分最短跳跃距离么？？枚举最短跳跃距离，检查移走的石头数量限制M
  int L=0,R=l+10;long long mid;
  while(L+1<R){
     mid=(R+L)/2;
    if(check(mid))L=mid;
    else R=mid;
  }
  cout<<L<<'\n';
  return 0;
}
