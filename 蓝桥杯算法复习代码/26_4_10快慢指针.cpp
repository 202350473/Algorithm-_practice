#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	int n,m,k;cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	int ans=0;
	for(int i=1,j=0,count=0;i<=n;i++) 
	{
		//ÓÒÖ¸ÕëÓÒÒÆµ½c>k 
		while(i>j||(count<k&&j+1<=n)){
			j++;
			if(a[j]>=m){
			count++;} 
		}
		
		//
		if(count>=k)ans+=n-j+1; 
		
		//ÓÒÒÆ¶¯×óÖ¸Õë
		if(a[i]>=m)count--; 
	}
	cout<<ans<<'\n';
	return 0;
} 
