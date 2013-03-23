#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,v1,v2,m;
const int maxn = 110;
int a[maxn],b[maxn],v[maxn];
int ans[maxn][maxn][10];
int main(){
//	freopen("in.txt","r",stdin);
//	int cas; scanf("%d",&cas);
	while(scanf("%d %d %d %d",&n,&v1,&v2,&m) !=EOF){
		int app = 0;	
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&v[i]);
			if(a[i]==0||b[i]==0){
				app+=v[i];
				n--; i--;
			}
		}
		//printf("%d\n",app);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			int t1 = a[i],t2 = b[i],val = v[i];
		//	printf("%d %d %d\n",t1,t2,val);
			for(int j=v1;j>=0;j--) for(int k=v2;k>=0;k--) for(int s=m;s>=0;s--){
				if(j+t1<=v1) ans[j+t1][k][s] = max(ans[j+t1][k][s], ans[j][k][s]+val);
				if(k+t2<=v2) ans[j][k+t2][s] = max(ans[j][k+t2][s], ans[j][k][s]+val);
				if(s+1<=m) ans[j][k][s+1] = max(ans[j][k][s+1], ans[j][k][s]+val);
 			}
 		}
		int ret = 0;
		for(int i=0;i<=v1;i++) for(int j=0;j<=v2;j++) for(int s=0;s<=m;s++) ret=max(ret,ans[i][j][s]);
		printf("%d\n",ret+app);
	}
	return 0;
}