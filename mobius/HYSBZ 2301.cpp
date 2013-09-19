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
        for(int j = 0; j < tot && i * p[j] <= n; j++) {
            vis[i * p[j]] = 1;
            if(i % p[j] == 0) {
                miu[i * p[j]] = 0;
                break;
            }
            miu[i * p[j]] = -miu[i];
        }
    }
    for(int i = 1; i <= n; i++)
        miu[i] += miu[i - 1];
}
int a, b, c, d, k;
int main() {
    mobius(50003);
    int cas, ca = 1;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        a--; c--;
        a /= k; b /= k; c /= k; d /= k;
        ll ans = 0;
        int w = min(b, d);
        for(int i = 1; i <= w; i++) {
            ll aa = (b/i-a/i);
            ll bb = (d/i-c/i);
            //printf("i = %d", i);
            int r = min(b/(b/i), d/(d/i));
            if(a/i) r = min(r, a/(a/i));
            if(c/i) r = min(r, c/(c/i));
            //printf("r = %d\n", r);
            ans +=  aa*bb*(miu[r]-miu[i-1]);
            i = r;
            //puts("~~");
        }
        printf("%lld\n", ans);
    }
    return 0;
}