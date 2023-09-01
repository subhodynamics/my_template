//! We can go up or down, either ways I am prepared

//! Hello there! Subhadeep this side.

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mid(low, high) (low + ((high - low) >> 1))

const int64_t MOD = 1000000007;
const int64_t MOD1 = 998244353;
const int64_t INF = (int64_t)1e18;

using ll = int64_t;
using ull = uint64_t;
using lld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

vector<ll> hashPrimes;
int primes;
const ll base = 31;
vector<vector<ll>> powersOfBase;
vector<vector<ll>> invOfPowersOfBase;
 
void preCalculate(int n) {
    hashPrimes.clear(); hashPrimes = {1000000009, 100000007}; //for now two hashprimes
    primes = sz(hashPrimes);    // for now 2 primes
    
    powersOfBase.resize(primes);
    invOfPowersOfBase.resize(primes);
    for(int i = 0; i < primes; i++) {
        powersOfBase[i].resize(n + 1, 1);
        invOfPowersOfBase[i].resize(n + 1, 1);
        ll inv = expo(base, hashPrimes[i]-2, hashPrimes[i]);
        for(int j = 1; j <= n; j++) {
            powersOfBase[i][j] = (powersOfBase[i][j - 1] * base) % hashPrimes[i];
            // invOfPowersOfBase[i][j] = expo(powersOfBase[i][j], hashPrimes[i]-2, hashPrimes[i]);
            invOfPowersOfBase[i][j] = (j == 1) ? inv : mod_mul(invOfPowersOfBase[i][j-1], inv, hashPrimes[i]);
        }
    }
}
 
struct Hashing{
    string s;
    int n;
    vector<vector<ll>> hashValues;
    Hashing(string a) {
        s = a; n = s.size(); 
        
        hashValues.resize(primes);
        for(int i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++) {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r) {
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++) {

            ll hash_r = hashValues[i][r];
            ll hash_lMinus1 = l > 0 ? hashValues[i][l - 1] : 0LL;

            ll numerator = mod_sub(hash_r, hash_lMinus1, hashPrimes[i]);
            ll b = invOfPowersOfBase[i][l];

            hash[i] = mod_mul(numerator, b, hashPrimes[i]);
        }
        return hash;
    }
};

void solve() {
    string str; cin >> ws >> str;
    ll n = sz(str);

    // string str_prefix, str_suffix;
    // str_prefix = str.substr(0, n/2);
    // ll ss = (n%2 == 0) ? n/2 : n/2+1;
    // str_suffix = str.substr(ss, n/2);
    // debug(str_prefix)
    // debug(str_suffix)
    // Hashing strPref (str_prefix);
    // Hashing strSuff (str_suffix);

    Hashing wholeStr (str);

    for (ll i = 0; i < n-1; i++) {
        vector<ll> substr1 = wholeStr.substringHash(0, i);
        vector<ll> substr2 = wholeStr.substringHash((n-1)-i, (n-1));
        debug(substr1) debug(substr2)
        if (substr1 == substr2) cout << i + 1 << " ";
        // if (substr1 == substr2) cout << str.substr(0, i+1) << nline;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

fastio();
    int t=1;
    preCalculate(1e6+3);
    // cin>>t;
    while(t--) {
        solve();
    }
    
    return 0;
}