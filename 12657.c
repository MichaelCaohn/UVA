#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100005;
int le[N], ri[N], n, m;
typedef long long ll;
void link(int l, int r)
{
    le[r] = l; ri[l] = r;
}
int main()
{
    int cas = 0, op, x, y, t;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; ++i)
            ri[i] = i + 1, le[i] = i - 1;
        ri[n] = 0, le[0] = n, ri[0] = 1;
        int flag = 0;
        while(m--)
        {
            scanf("%d", &op);
            if(op == 4) flag = !flag;
            else{
                scanf("%d%d", &x, &y);
                if(flag && op != 3) op = 3 - op;
                if(ri[y]== x && op == 3)
                    t = x, x = y, y = t;
                if( (op == 1 && le[y] == x) || (op == 2 && ri[y] == x)) continue;
                if(op == 1)
                    link(le[x], ri[x]), link(le[y], x), link(x, y);
                else if(op == 2)
                    link(le[x], ri[x]), link(x, ri[y]), link(y, x);
                else if(y == ri[x])
                    link(le[x], y), link(x,ri[y]),link(y, x);
                else{
                    int ry = ri[y], ly = le[y];
                    link(le[x], y), link(y, ri[x]),link(ly, x),link(x, ry);
                }
            }
        }
        t = 0;
        ll ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            t = ri[t];
            if(i % 2) ans += t;
        }
        if(n % 2 == 0 && flag)
            ans = (ll) n / 2 * (1 + n) - ans;
        printf("Case %d: %lld\n", ++cas, ans);
    }
    return 0;
}