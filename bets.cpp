#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define forl(i, a, b) for (ll i = a; i < b; i++)
#define nl "\n"
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const ll mod = 1000000007;
const ll N = 1e7 + 2;
const ll inf = 1e18;

template <typename T>
istream& operator>>(istream& input, vector<T>& v) {
    for (auto& i : v) cin >> i;
    return input;
}

template <typename T>
ostream& operator<<(ostream& output, vector<T>& v) {
    for (auto& i : v) cout << i << " ";
    return output;
}

template <int MOD = 998'244'353>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }
    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) {
        return os << a.value;
    }
    friend bool operator==(Modular const& a, Modular const& b) {
        return a.value == b.value;
    }
    friend bool operator!=(Modular const& a, Modular const& b) {
        return a.value != b.value;
    }
};

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll addition(vector<ll> a) {
    ll sum = 0;
    for (auto i : a) {
        sum += i;
    }
    return sum;
}

bool sortbysec(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return (a.second < b.second);
}

ll inv(ll i) {
    if (i == 1) return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_mul(ll a, ll b) {
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

ll mod_add(ll a, ll b) {
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : (a / b) + 1; }

ll power(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// -------------------------------------------------------------------------------------------//

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b)
        cout << 0 << " " << 0 << nl;

    else {
        ll g = abs(a - b);
        ll m = min(a % g, g - a % g);
        cout << g << " " << m << nl;
    }
}

int main() {
    fio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    ll __t = t;
    while (t--) {
        // cout << "Case #" << __t-t << ": "; //GOOGLE
        // cout << "Case #" << __t-t << ": " << nl; //FACEBOOK
        solve();
    }
    return 0;
}