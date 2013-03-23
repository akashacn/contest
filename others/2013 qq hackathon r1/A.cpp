#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int b[30][30];
const int ox[4]={0,1,-1,0};
const int oy[4]={1,0,0,-1};
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d %d",&n,&m) != EOF){
		if(n==0&&m==0) break;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&b[i][j]);
		int ansr = 1, ansc = 1, ansv  = -10000;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			int tmp = 0;
			for(int k=0;k<4;k++){
				int r = i+ox[k];
				int c = j+oy[k];
				if(r>0&&c>0&&r<=n&&c<=m){
					if(b[i][j]*b[r][c]<0) tmp += abs(b[r][c]);
					else tmp -= abs(b[r][c]);
				}
			}
			if(ansv < tmp){
				ansv = tmp;
				ansr = i;
				ansc = j; 
			}
		}
		printf("%d %d %d\n",ansr,ansc,ansv);
	}
	return 0;
}