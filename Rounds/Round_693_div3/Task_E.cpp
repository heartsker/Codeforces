//  ----------------    INCLUDES    ----------------    //
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
//  ----------------    TYPEDEFS    ----------------    //
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef set<ll> si;
typedef set<string> ss;
typedef map<ll, ll> mii;
typedef map<str, ll> msi;
//  ----------------    MACROS      ----------------    //
#define forin(x) for (auto &t : x)
#define fori(x) for (ll i = 0; i < (x); i++)
#define forj(x) for (ll j = 0; j < (x); j++)
#define forn(i, n) for (ll i = 0; i < (n); i++)
#define fordn(i, n) for (ll i = (n - 1); i >= 0; i--)
#define For(i, start, cond, dif) for (ll i = (start); (cond); (dif))
#define inc(a, b) a = max(a, b)
#define dec(a, b) a = min(a, b)
#define is_2_power() (x && (!(x & (x - 1)))
#define fastIO() ios::sync_with_stdio(NULL); In.tie(NULL); Out.tie(NULL)
#define read(x) for (auto &t : (x)) In >> t
#define write(x) for (auto &t : (x)) Out << t << ' '
#define dbg(x) cout << (#x) << " --> " << (x) << endl]
#define in(x) forin(x) In >> t;
#define out(x) forin(x) Out << t << ' '
#define all(x) (x).begin(), (x).end()
#define dosort(x) sort(all(x))
#define doreverse(x) reverse(all(x))
#define tests ll q; In >> q; while (q--)
#define classic { ll n; In >> n; vi v(n); in(v); solvev(n, v); }
//  ----------------    FUNCTIONS   ----------------    //

// returns whether the number is prime
bool is_prime(ll n) {
    if (n <= 1) return false;
    ll cnt = 0;
    For(i, 2, i * i <= n, ++i) cnt += !(n % i);
    return !cnt;
}

// z[i] is length of the longest common prefix and i-th suffix
// z[0] = 0
vi z_func(vi& v) {
    ll n = v.size();
    vi z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && v[z[i]] == v[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] -1;
    }
    return z;
}

// pf[i] is length of the longest suffix v[0...i] which equals to its prefix
// pf[0] = 0
vi prefix_func(vi& v) {
    ll n = v.size();
    vi pf(n, 0);
    for (ll i = 0; i < n; ++i) {
        ll j = pf[i - 1];
        while (j > 0 && v[i] != v[j]) j = pf[j - 1];
        if (v[i] == v[j]) ++j;
        pf[i] = j;
    }
    return pf;
}

// returns (a ^ p) % m
ll modulo_power(ll a, ll p, ll m) {
    ll x = 1;
    ll y = a;
    while (p > 0) {
        if (p & 1) x = (x * y) % m;
        y = (y * y) % m;
        p >>= 1;
    }
    return x;
}

// returns factorisation of number
vii prime_divisors_extended(ll number) {
    vii divisors;
    if (number % 2 == 0) {
        ll cnt = 0;
        while (number % 2 == 0) { number /= 2; ++cnt; }
        if (cnt) divisors.push_back({2, cnt});
    }
    ll start_number = number;
    for (ll p = 3; p <= number && p * p <= start_number; p += 2) {
        ll cnt = 0;
        while (number % p == 0) { number /= p; ++cnt; }
        if (cnt) divisors.push_back({p, cnt});
    }
    if (number != 1) divisors.push_back({number, 1});
    return divisors;
}

// returns sorted list of all prime divisors of number
vi prime_divisors(ll number) {
    vi divisors;
    if (number % 2 == 0) {
        divisors.push_back(2);
        while (!(number % 2)) number /= 2;
    }
    ll start_number = number;
    for (ll p = 3; p <= number && p * p <= start_number; p += 2) {
        if (number % p) continue;
        divisors.push_back(p);
        while (!(number % p)) number /= p;
    }
    if (number - 1) divisors.push_back(number);
    return divisors;
}

// returns list of all divisors of number
vi all_divisors(ll number) {
    vi divisors;
    if (number % 2 == 0) {
        divisors.push_back(2);
        if (4 != number) { divisors.push_back(number / 2); }
    }
    for (ll p = 3; p * p <= number; p += 2) {
        ll t = p;
        if (number % t == 0) {
            divisors.push_back(p);
            if (p * p != number) { divisors.push_back(number / p); }
        }
    }
    return divisors;
}

// returns GCD(a, b) [GCD(0, 0) = 1]
ll gcd(ll a, ll b) {
    if (!(a || b)) return 1;
    return (b ? gcd(b, a % b) : a);
}

// returns number of combination for N choose K
ll combinations(ll n, ll k) {
    return (k && n - k) ? combinations(n - 1, k) + combinations(n - 1, k - 1) : 1;
}

// returns factorial of N (N!)
ll factorial(ll n) {
    return (n > 1) ? n * factorial(n - 1) : 1;
}
//  ----------------    CONSTS      ----------------    //
const ld ZERO = 1e-15;
const ld EPS = 1e-10;
const ll N = 100500;
const ll MOD = 1000000007;
const ll INF9 = 1e9;
const ll INF = 2 * 1e18;
//  ----------------    FILES       ----------------    //
//#define FILEINOUT
#ifdef FILEINOUT
ifstream In("Input.txt");
ofstream Out("Output.txt");
#else
#define In cin
#define Out cout
#endif
//  ----------------    CODE        ----------------    //

void solvev(ll n, vi&v) {

    return;
}

void solve() {

    ll n; In >> n;

    vii ind;
    vi h(n), w(n);

    fori(n) {
        In >> h[i] >> w[i];
        if (h[i] > w[i]) swap(h[i], w[i]);
        ind.push_back({h[i], i});
    }
    dosort(ind);
    ll mj = -1, j = 0;

    vi ans(n, -1);

    fori(n) {
        ll id = ind[i].second;
        while (ind[j].first < h[id]) {
            ll jd = ind[j].second;
            if (mj == -1 || w[mj] > w[jd]) mj = jd;
            j++;
        }
        if (mj != -1 && w[mj] < w[id]) ans[id] = mj + 1;
    }

    out(ans); Out << endl;

    return;
}

signed main() {
    fastIO();

    //classic
    //solve();
    tests solve();
    //tests classic

    return 0;
}