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
#include <random>

using namespace std;

//  ----------------    TYPEDEFS    ----------------    //

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> ii;
typedef pair<ld, ld> dd;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<str> vs;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
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
#define FOR(i, start, end) for (ll i = (start); i < (end); i++)
#define inc(a, b) a = max(a, b)
#define dec(a, b) a = min(a, b)
#define is_2_power() (x && (!(x & (x - 1)))
#define pow2(x) ((x) * (x))
#define abs0(x) max(ll(0), (x))
#define fastIO() ios::sync_with_stdio(false); In.tie(NULL); Out.tie(NULL);
#define read(x) for (auto &t : (x)) In >> t;
#define write(x) for (auto &t : (x)) Out << t << ' ';
#define dbg(x) cout << (#x) << " --> " << (x) << endl]
#define in(x) forin(x) In >> t;
#define out(x) forin(x) Out << t << ' ';
#define precision(x) Out << fixed << setprecision(x);
#define all(x) (x).begin(), (x).end()
#define dosort(x) sort(all(x))
#define doreverse(x) reverse(all(x))
#define minel(x) *min_element(all(x))
#define tests { ll q; In >> q; while (q--) { solve(); } }
#define classic { ll n; In >> n; vi v(n); in(v); solvev(n, v); }
#define tests_classic { ll q; In >> q; while (q--) { classic } }

//  ----------------    CONSTS      ----------------    //

const ld ZERO = 1e-15;
const ld EPS = 1e-10;
const ll N = 505;
const ll MOD = 1000000007;
const ll INF9 = 2 * 1e9;
const ll INF = 2 * 1e18;

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
    return x % m;
}

// returns (a * b) % m
ll modulo_mult(ll a, ll b, ll m) {
    if (!a || !b) return 0;
    if (a & 1) return (b + modulo_mult(a-1, b, m)) % m;
    return (modulo_mult(a / 2, b, m) * 2) % m;
}

// returns quantity of co-prime with n numbers from 1 to n
ll euler_func(ll n) {
    ll result = n;
    For(i, 2, i * i <= n, ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
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
    for (ll p = 1; p * p <= number; p++) {
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

// returns {x, y} such a * x + b * y = gcd(a, b)
ll gcd_coef(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd_coef(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// returns number of combination for N choose K
ll combinations(ll n, ll k) {
    return (k && n - k) ? combinations(n - 1, k) + combinations(n - 1, k - 1) : 1;
}

// returns whether the number is prime
bool is_prime_Fermat(ll number, ll iterations) {
    if (number <= 1 || number == 4) return false;
    if (number <= 3) return true;

    while (iterations--) {
        ll a = 1 + rand() % (number - 1);
        if (gcd(number, a) != 1) return false;
        if (modulo_power(a, number - 1, number) != 1) return false;
    }
    return true;
}

// returns list of all primes less than n
vi eratosthenes_sieve(ll n) {
    n++;
    vb isprime(n, true); // prime -> true
    vi primes(0); // list of primes
    vi spf(n); // smallest prime factor of a number
    isprime[0] = isprime[1] = false;
    For(i, 2, i < n, ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        For(j, 0, j < primes.size() && i * primes[j] < n && primes[j] <= spf[i], ++j) {
            isprime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
    return primes;
    //return isprime;
}

//ll fact[N];
//// returns list of factorials modulo mod
//void modulo_factorial(ll n, ll mod) {
//    fact[0] = fact[1] = 1;
//    For(i, 2, i < n, ++i) fact[i] = (fact[i - 1] * i) % mod;
//}
//
//// returns number of combinations from n by k
//// (fact and inv_fact are needed)
//ll modulo_combinations(ll n, ll k, ll mod) {
//    if (k > n) return 0;
//    ll t = (fact[k] * fact[n - k]) % mod;
//    t = modulo_power(t, mod - 2, mod);
//    return (fact[n] * t) % mod;
//}

// returns x such a * x = 1 (mod m) or -1 if x does not exist
ll modulo_inverted_element(ll a, ll m) {
    ll x, y;
    ll g = gcd_coef(a, m, x, y);
    if (g != 1) return -1;
    else return (x % m + m) % m;;
}

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

}

unordered_set<ll> cubes;

void solve() {
    ll n; In >> n;

    For(a, 1, a * a * a < n, ++a) {
        ll b = n - a * a * a;
        if (cubes.count(b)) {
            Out << "YES" << endl;
            return;
        }
    }
    Out << "NO" << endl;
}

signed main() {
    fastIO()
    precision(2);
    setlocale(LC_ALL, "");

    For(a, 1, a * a * a < INF, ++a) cubes.insert(a * a * a);

    //for test: n + vi
    //classic

    //for test: n + k
    //solve();

    //for sub tests: n + k
    tests

    //for sub tests: n + vi
    //tests_classic

    return 0;
}