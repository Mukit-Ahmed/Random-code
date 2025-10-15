#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;
#define F              first
#define S              second
#define pb             push_back
#define pbs            pop_back()
#define vi             vector<int>
#define r(v)           for(auto &i:v) cin>>i
#define w(v)           for(auto &i:v) cout<<i<<" "
#define all(v)         v.begin(),v.end()
#define rall(v)        v.rbegin(),v.rend()
#define sz(x)          (int)(x).size()
#define yes            cout<<"YES\n"
#define no             cout<<"NO\n"
#define nl             "\n"
#define ali            cout<<"Alice\n"
#define bob            cout<<"Bob\n"
#define int            ll
#define decF_incS(v)   sort(v.begin(), v.end(), [](const auto &a, const auto &b) {if (a.first != b.first)return a.first > b.first;return a.second.first < b.second.first; });
#define incF_decS(v)   sort(v.begin(), v.end(), [](const auto &a, const auto &b) {if (a.first != b.first)return a.first < b.first;return a.second.first > b.second.first; });
#define MOD            1000000007
const double PI = acos(-1.0);
vector<int> num_divisor(int n);
vector<int> divisor_sum(int n);
vector<bool> build_seive(int n);
vector<int> primes(int n,vector<bool> &is);
ll binpow(ll a,ll b,ll mod);
vector<int> prime_factors(int n,vector<int>&prime);
vector<int> build_spf(int n);
vector<int> factorial_fact_count(int n,vector<int> &spf);
int nCr(int n,int r,vector<vector<int>> &dp);

int t;

void solve()
{
    int n,m;
    cin>>n>>m;
    if(!(n==m||n==(m+1)))
    {
        cout<<"unknown topology";
        return;
    }
    map<int,int> freq;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        freq[a]++;
        freq[b]++;
    }
    bool ring=true;
    bool bus=true;
    bool star=true;
    bool found = false;
    int ctr=0;
    int max1=0;
    for(auto &[key,value]:freq)
    {
        max1=max(max1,value);
    }
    for(auto &[key,value]:freq)
    {
        if(value!=2)
        {
            ring=false;
        }
        if(value==1)
        {
            ctr++;
            if(ctr==3)
            {
                bus=false;
            }

        }
        if(value>=3) bus=false;

        if(value>1)
        {
            if(value!=max1)
                star=false;
            if(found && value==max1)
                star=false;
        }
        if(value==max1) found=true;
    }
    if(ring) cout<<"ring topology";
    else if(bus) cout<<"bus topology";
    else if(star) cout<<"star topology";
    else cout<<"unknown topology";
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    vector<bool> is=build_seive(5000000);
//    vector<int> prime=primes(5000000,is);
//    vector<int> spf=build_spf(5000000);
//    vector<int> query=factorial_fact_count(5000000,spf);

//    cin>>t;
//    while(t--)
//    {
//        solve();
//    }

    solve();

}

vector<bool> build_seive(int n)
{
    vector<bool> is(n+1,1);
    is[0]=is[1]=0;
    for(int i=2; i*i<=n; i++)
    {
        if(is[i])
        {
            for(int j=i*i; j<=n; j+=i)
            {
                is[j]=0;
            }
        }
    }
    return is;
}
ll binpow(ll a,ll b,ll mod)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
vector<int> primes(int n,vector<bool> &is)
{
    vector<int> prime;
    for(int i=0; i<=n; i++)
    {
        if(is[i]) prime.pb(i);
    }
    return prime;
}
vector<int> num_divisor(int n)
{
    vector<int> div(n+1,1);
    for(int i=2; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            div[j]++;
        }

    }
    return div;
}
vector<int> divisor_sum(int n)
{
    vector<int> div(n+1,1);
    for(int i=2; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            div[j]+=i;
        }

    }
    return div;
}
vector<int> prime_factors(int n,vector<int>&prime)
{

    vector<int> factor;

    if(n<0)
    {
        factor.push_back(-1);
        n*=-1;
    }

    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {

        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                factor.push_back(prime[i]);
                n/=prime[i];
            }
        }
    }
    if(n!=1)
    {
        factor.push_back(n);
    }

    return factor;

}
vector<int> build_spf(int n)
{
    vector<int> spf(n+1);
    for (int i = 2; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}

vector<int> factorial_fact_count(int n,vector<int> &spf)
{

    vector<int> pref(n+1,0);
    for (int i = 2; i <= n; i++)
    {
        int x = i;
        int ctr = 0;
        while (x > 1)
        {
            ctr++;
            x /= spf[x];
        }
        pref[i] = pref[i-1] + ctr;
    }
    return pref;
}
int nCr(int n,int r,vector<vector<int>> &dp)
{
    if (n < 0) return 0;
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = nCr(n-1, r-1, dp) + nCr(n-1, r, dp);
}
