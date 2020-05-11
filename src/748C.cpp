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
char str[200100];
int main()
{
	int n,step=0,ans=0;
	int cx=0,cy=0;
	int now_x=0,now_y=0;
	cin >> n;
	cin >> str;

	for(int i=0;i<n;i++)
	{
		// cout << step << ' ' << cx << ' ' << cy;
		// printf(" %d %d",now_x,now_y);
		// NL;
		step++;
		if(str[i]=='L')
			cx--;
		if(str[i]=='R')
			cx++;
		if(str[i]=='U')
			cy++;
		if(str[i]=='D')
			cy--;
		if(abs(cx-now_x)+abs(cy-now_y)!=step)
		{
			step=0;
			cx=now_x=0;
			cy=now_y=0;
			i--;
			ans++;
		}
	}
	cout << ans+1;
	return 0;
}