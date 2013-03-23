#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,t;
const int maxn = 500;
long long ret[22][maxn];
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d %d %d",&a,&b,&t) != EOF){
		int f = t/15;
		int n = (f+1)/2;
		int m = b+(f/2)-a+1;
		if(m<0) m = 0;
		memset(ret,0,sizeof(ret));
		ret[0][0]=1;
		for(int i=0;i<=n;i++) for(int j=0;j<=m;j++){
			ret[i+1][min(j+1,m)] += ret[i][j];
			ret[i+1][min(j+2,m)] += ret[i][j];
			ret[i+1][min(j+3,m)] += ret[i][j];
		}
		printf("%I64d\n",ret[n][m]);
		ret[n][m]=0;
	}
	return 0;
}