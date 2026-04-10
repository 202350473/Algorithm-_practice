#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int a[N];

int main(){
  int n,s;cin>>n>>s;
  for(int i=1;i<=n;i++)cin>>a[i];
  int len=N;
  //对撞指针
  for(int i=1,j=0,sum=0;i<=n;i++){
    //右指针右移：先把sum和加到s[移动右指针]
    while(j<i||(sum<s&&j+1<=n))sum+=a[++j];


    //记录长度
    if(sum>=s)len=min(len,j-i+1);

    //左指针右移
    sum=sum-a[i];
  }

  cout<<(len>n?0:len)<<'\n';//影响最后一个案例的关键
  return 0;
}
