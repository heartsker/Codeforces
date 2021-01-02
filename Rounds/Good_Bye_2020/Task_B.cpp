//#define FILEINOUT

// includes
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// files
#ifdef FILEINOUT
ifstream In("Input.txt");
ofstream Out("Output.txt");
#else
#define In cin
#define Out cout
#endif

// macross
// loops
#define fori(x) for (ll i = 0; i < (x); i++)
#define fordi(x) for (ll i = (x - 1); i >= 0; i--)
#define forj(x) for (ll j = 0; j < (x); j++)
#define fordj(x) for (ll j = (x - 1); j >= 0; j--)
#define forn(i, n) for (ll i = 0; i < (n); i++)
#define fordn(i, n) for (ll i = (n - 1); i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define forin(x) for (auto &t : (x))
#define For(i, start, cond, dif) for (ll i = (start); (cond); (dif))

// short names
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define rz resize
#define sz size()
#define asg assign
#define ins insert
#define clr clear()

// upgraded funcs
#define min3(a, b, c) min(ll(a), min(ll(b), ll(c)))
#define max3(a, b, c) max(ll(a), max(ll(b), ll(c)))
#define abs0(x) max(L0, ll(x))
#define pow2(x) ((x) * (x))
#define pow3(x) ((x) * (x) * (x))
#define all(x) (x).begin(), (x).end()
#define dosort(x) sort(all(x))
#define doreverse(x) reverse(all(x))

// my funcs
#define read(x) for (auto &t : (x)) In >> t
#define write(x) for (auto &t : (x)) Out << t << ' ';
#define watch(x) cout << (#x) << " --> " << (x) << endl
#define in(x) ll x; In >> x
#define improve(a, b) (a = (a < (b) ? (b) : a))
#define deimprove(a, b) (a = (a > (b) ? (b) : a))

// olympic funcs
#define close_int(x) (ll)((ld)(x) + 0.5)
#define is_2_power() (x && (!(x & (x - 1)))
#define fastIO ios::sync_with_stdio(NULL); In.tie(NULL); Out.tie(NULL)
#define endl '\n'

// solution templates
#define tests(q) in(q); while (q--)
#define classic tests(q) { in(n); vi v(n); read(v); solve(v); }
#define matrix in(n); in(m); vvi v(n, vi(m)); fori(n) forj(m) In >> v[i][j];

typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef pair<double, double> dd;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
typedef set<ll> si;
typedef set<double> sd;
typedef set<string> ss;
typedef set<char> sc;
typedef map<ll, ll> mii;
typedef map<ll, double> mid;
typedef map<string, ll> msi;
typedef map<ll, vi> mivi;
typedef unordered_set<ll> usi;
typedef unordered_set<double> usd;
typedef unordered_set<string> uss;
typedef unordered_set<char> usc;
typedef unordered_map<ll, ll> umii;
typedef unordered_map<ll, double> umid;
typedef unordered_map<string, ll> umsi;
typedef queue<ll> qi;
typedef priority_queue<ll> maxheap;
typedef priority_queue <ll, vi, greater<ll> > minheap;
typedef deque<ll> deqi;

const ld ZERO = 1e-15;
const ld EPS = 1e-10;
const ll N = 100500;
const ll MOD = 1000000007;
const ll INF9 = 1e9;
const ll INF = 2 * 1e18;
const ll L0 = 0;
const ll L1 = 1;
const ld PI = acos(-1);
const ld SQ2 = sqrt(2.0);


// ------------------    CODE    ------------------ //

void solve() {

    in(n);
    vi v(n); read(v); dosort(v);

    si s;
    forin(v) {
        if (s.find(t) == s.end()) s.insert(t);
        else s.insert(t + 1);
    }

    Out << s.size() << endl;

    return;
}

int main() {
    fastIO;

    tests(q) solve();

    return 0;
}