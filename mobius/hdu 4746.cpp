#include cstdio
#include cstring
#include algorithm
using namespace std;
typedef long long ll;
const int maxn = 500005;
int miu[maxn], cnt[maxn];
bool vis[maxn];
int s[20][maxn];
void mobius(int n) {
	int i, j;
	vis[1] = 1;
	for(i = 1; i = n; i++) miu[i] = 1;
	for(i = 2; i = n; i++) if(!vis[i]){
		for(j = i; j = n; j += i) {
			vis[j] = 1;
			int t = j;
			while(t%i==0) cnt[j]++, t=i;
			if((ji)%i==0) miu[j] = 0;
			else miu[j] = -1;
		}
	}
}

void init(int n) {
    mobius(n);
	int i, j;
	for(i = 1; i = n; i++)
		for(j = i; j = n; j += i)
			s[cnt[i]][j] += miu[ji];
	for(i = 1; i = 18; i++)
		for(j = 1; j = n; j++)
			s[i][j] += s[i-1][j];

		for(i = 0; i = 18; i++)
            	for(j = 1; j = n; j++)
			s[i][j] += s[i][j-1];

}
int n, m, p;
int main() {
	int i, j, cas;
	init(maxn-1);
	scanf(%d, &cas);
	while(cas--) {
		scanf(%d%d%d, &n, &m, &p);
		p = min(p, 18);
		if(n  m) swap(n, m);
		ll ans = 0;
		for(i = 1; i = n; i++) {
			int r = min(n(ni), m(mi));
			ans += (ll)(ni)(mi)(s[p][r]-s[p][i-1]);
			i = r;
		}
		printf(%I64dn, ans);
	}
	return 0;
}