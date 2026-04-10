#include<bits/stdc++.h>
using namespace std;
int n,m;const int N=1e6+10;
const int M=1e5+10;
long long a[N];
long long w[M];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//		bool find=true;
//		for(int j=1;j<=n;j++){
//			if(a[j]==w[i]){
//				find=false;
//				cout<<j<<' ';
//				break;
//			}
//		}
//		if(find)cout<<"-1"<<' ';
//	}
	//考虑怎么用二分解决这个问题,用了二分怎么确定是第一个呢 
	bool find=false;
	for(int i=1,find=false;i<=m;i++){
		cin>>w[i];
		int l=1,r=n,mid=1,ans=0;
		
		while(l+1!=r){
			mid=(l+r)/2;
			if(a[mid]<w[i]){
				l=mid;continue;
			}
			if(a[mid]>=w[i]){
				r=mid;
				if(a[mid]==w[i]){
					find=true;
					ans=min(ans,i);
				}
			} 
			
		}
		if(!find)ans=-1;
		cout<<ans<<' ';
	} 
	
	return 0;
	 
} 
