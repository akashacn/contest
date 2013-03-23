#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
const int maxn = 1100;
struct event{
	int s,e,c;
}q[maxn];
int operator < (const event &e1,const event &e2){
	if(e1.e == e2.e) return e1.s < e2.s;
	return e1.e < e2.e;
}
int ans[maxn];
int main(){
//freopen("in.txt","r",stdin);
	int cas; scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&m,&n);
		for(int i=1;i<=n;i++) scanf("%d %d %d",&q[i].s,&q[i].e,&q[i].c);
		sort(q+1,q+n+1);
		memset(ans,0,sizeof(ans));
		int now =1;
		for(int i=1;i<=m;i++){
			ans[i] = ans[i-1];
			while(now<=n&&q[now].e==i){
				ans[i] = max(ans[i], ans[q[now].s-1] + q[now].c);
				now ++;
			}
		}
		printf("%d\n",ans[m]);
	}
	return 0;
}