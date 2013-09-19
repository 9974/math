#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000006;
char s[maxn];
int sign;
ll p[103], d;
ll Pow(ll x, ll n) {
	ll ret = 1;
	while(n) {
		if(n & 1)
			ret = ret * x % d;
		x = x * x % d;
		n >>= 1;
	}
	return ret;
}
bool cal(ll x) {
	int i;
	ll ret = 0;
	for(i = 0; i <= 100; i++)
		if(p[i]) {
			ret += p[i] * Pow(x, i) % d;
			ret %= d;
		}
	return !ret;
}
int main() {
	int i, j, ca = 1;
	while(~scanf("%s", s) && s[0] != '.') {
		memset(p, 0, sizeof(p));
		int l = strlen(s);
		for(i = 1; i < l; i++) {
			if(s[i] == '-') {
				sign = -1;
				i++;
			}
			else {
				if(s[i] == '+')
					i++;
				sign = 1;
			}

			ll c = 0;
			if(s[i] == 'n') {
				c = 1;
			}
			else {
				while(s[i] != 'n' && s[i] != ')' && i < l) {
					c = c * 10 + s[i] - '0';
					i++;
				}
			}
			if(s[i] == ')') {
				p[0] = c * sign;
				break;
			}
			i++;
			if(s[i] == '^') {
				i++;
				ll e = 0;
				while(s[i] >= '0' && s[i] <= '9' && i < l) {
					e = e * 10 + s[i] - '0';
					i++;
				}
				i--;
				p[e] = c * sign;
			}
			else {
				p[1] = c * sign;
				i--;
			}
			if(s[i] == ')')
				break;
		}
		//	puts("~~~~");
		//	printf("i = %d\n", i);
		//	printf("%c----", s[i]);
		while(s[i] == ')' || s[i] == '/')
			i++;
		d = 0;
		while(s[i] >= '0' && s[i] <= '9' && i < l) {
			d = d * 10 + s[i] - '0';
			i++;
		}
		//printf("d = %d\n", d);
		//puts("~~~~");
		for(i = 1; i <= 101; i++)
			if(!cal(i))
				break;
		//  puts("!!!!!");
		printf("Case %d: ", ca++);
		if(i != 102)
			puts("Not always an integer");
		else
			puts("Always an integer");

	}
	return 0;
}