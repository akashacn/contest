#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int main(){
	//freopen("in.txt","r",stdin);
	int cas; scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		int ret=0;
		for(int i=1;i<=n;i++){
			int x; scanf("%d",&x);
			ret += x*(n-x-1);
		}
		//printf("%d\n",ret);
		printf("%.3lf\n",1-ret*3.0/(n-1)/n/(n-2));
	}
	return 0;
}