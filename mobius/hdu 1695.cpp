#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100010;

bool vis[maxn];
int miu[maxn], p[maxn], tot;
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
    for(int i = 1;i <= n; i++)
    	miu[i] += miu[i-1];
}

int main() {
    mobius(100000);
    int a, b, k, cas, ca=1;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%*d%d%*d%d%d", &a, &b, &k);
        if(k == 0) {
            printf("Case %d: 0\n", ca++);
            continue;
        }
        a /= k; b /= k;
        if(a > b) swap(a, b);
        ll ans = 0;
        for(int i = 1;i <= a; i++) {
            int aa = a/i, bb = b/i;
            int r = min(a/aa, b/bb);
            ans += 1LL*(1LL*aa*(aa+1)/2+1LL*(bb-aa)*aa)*(miu[r] - miu[i-1]);
            i = r;
        }
        printf("Case %d: %I64d\n", ca++, ans);
    }
    return 0;
}