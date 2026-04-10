//给定一个浮点数求三次方根 ，结果保留六位小数 

#include<bits/stdc++.h>
using namespace std;
int main(){
	double n;cin>>n;
	//实际上就是用二分搜索三次方等于n的数
	int l=-10000,r=10000;
	while(r-l>1e-8){//保留六位小数加2得8
		double mid=(l+r)/2;
		if(mid*mid*mid>=n){
			r=mid;
		} else l=mid;
	
	}
	printf("%lf\n",l);
	return 0; 
}
