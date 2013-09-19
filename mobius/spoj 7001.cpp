#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1000030;

bool vis[maxn];
int miu[maxn], p[maxn], tot;
int n;
void mobius(int n) {
    miu[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) {
            p[tot++] = i;
            miu[i] = -1;
        }
        for(int j = 0;j < tot && i*p[j]<=n; j++) {
            vis[ i*p[j] ] = 1;
            if(i%p[j] == 0) {
                miu[ i*p[j] ] = 0;
                break;
            }
            miu[ i*p[j] ] = -miu[i];
        }
    }
     for(i = 1;i <= n; i++) miu[i] += miu[i-1];
}
int main() {
	int i;
    mobius(1000000);
   
    int a, b, k, cas, ca=1;
    scanf("%d", &cas);
    while(cas--) {
    	ll ans = 3;
    	scanf("%d", &n);
    	for(i = 1; i <= n; i++) {
    		ll t = n/i;
    		int r = n/(n/i);
    		ans += (t*t*t+t*t*3)*(miu[r]-miu[i-1]);
    		i = r;
    	}
    	printf("%lld\n", ans);
    }
    return 0;
}