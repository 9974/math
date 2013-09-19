#include cstdio
#include cstring
#include algorithm
using namespace std;
typedef long long ll;
const int maxn = 4000006;
int phi[maxn];
ll ans[maxn];
void phi_init(int n) {
	int i, j;
	for(i = 1; i = n; i++) phi[i] = i;
	for(i = 2; i = n; i++) if(phi[i] == i)
		for(j = i; j = n; j += i)
			phi[j] = phi[j]  i  (i-1);

}
ll a[maxn];
void init(int n) {
	phi_init(n);
	int i, j;
	for(i = 1; i = n; i++)
		for(j = 2i; j = n; j+=i)
			ans[j] += (ll)iphi[ji];
    for(i = 3; i = n; i++) ans[i] += ans[i-1];
}
int n;
int main() {
	init(4000000);
	int i, j;
	while(~scanf(%d, &n) && n)
		printf(%lldn, ans[n]);
	return 0;
}