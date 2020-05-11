#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <time.h>

#define SQR(_x) ((_x)*(_x))
#define NL printf("\n")
#define LL long long
#define DB double
#define PB push_back
#define INF 1<<30
#define LB lower_bound
#define UB upper_bound
#define F front
#define PQ priority_queue

using namespace std;
struct data{
	int a,b;
}arr[200200];
int l=-20000010,r=20000010;
int mid;
int main()
{
	int n;
	int temp,c=0,poss=0,allone=0;
	int ans=-20000100,change;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].a,&arr[i].b);
		if(arr[i].b==2) allone=1;
	}
	while(l<=r)
	{
		mid=(l+r)/2;
		temp =mid;
		c=0;
		change =0;
		//printf("%d %d %d\n",l,r,mid);
		for(int i=0;i<n;i++)
		{
			
			if(arr[i].b==1 and temp>=1900)
			{
				temp+=arr[i].a;
			}
			else if(arr[i].b==2 and temp<1900)
			{
				temp+=arr[i].a;
			}
			else
			{
				c=1;
				


			}
			(temp>=1900)?change=-1:change=1;
			if(c==1) break;
		}

		if(c==0)
		{
			(temp<ans)?change=-1:change=1;
			ans=max(ans,temp);
			poss=1;
		}
		if(change == -1)
		{
			r=mid-1;
		}
		if(change == 1)
		{
			l=mid+1;
		}
	}

	if(allone == 0) cout << "Infinity";
	else if(poss==0) cout<< "Impossible";
	else cout << ans;

	return 0;
}