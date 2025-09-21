#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define srep(i,l,r) for(ll i=l;i<=r;i++)
#define irep(i,r,l) for(ll i=r;i>=l;i--)
using ll = long long;
using ld = long double;
const ll mod=998244353;
#define vout(v) for(auto i :v) cout<<i<<" ";
#define INF 9223300000000000000ll
#define Winf 5e12
#define nl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define vl vector<ll>
#define pb push_back
#define vc vector<char>
#define vb vector<bool>
#define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())
#define eb emplace_back



void no(void) { cout<<"No"<<nl;}
void yes(void) {cout<<"Yes"<<nl;}
void yn(bool a) {
    cout<<(a ? "Yes":"No")<<nl;
}


vector<ll> dx={-1,0,1,0,1,1,-1,-1};
vector<ll> dy={0,-1,0,1,-1,1,-1,1};

bool isin(ll i,ll j,ll h,ll w) {
    if(i<0 || i>=h || j<0 || j>=w) return false;
    return true;
}

template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}


template<class T>T vecmax(const vector<T>&v){return *max_element(all(v));}
template<class T>T vecmin(const vector<T>&v){return *min_element(all(v));}

ll safemod(ll num,ll rule) {
    return (num%rule+rule)%rule;
}

ll sum(vector<ll> &a) {
    return accumulate(all(a),0ll);
}


template<typename t> class segtree {
    function<t(t,t)> op;
    function<t()> e;
    ll n;
    vector<t> seg;
    ll siz=1;
    public:
        segtree(ll n,function<t(t,t)> op,function<t()> e) : n(n),op(op),e(e) {
            while(siz<n) siz*=2;
            seg = vector<t>(2*siz,e());
        }


        segtree(const vector<t>& v, function<t(t,t)> op, function<t()> e):segtree((ll)v.size(), op, e) {
            for (ll i=0;i<(ll)v.size();++i) seg[siz+i]=v[i];
            for (ll i=siz-1;i>0;--i) seg[i]=op(seg[2*i],seg[2*i+1]);
        }

        void set(ll ind,t val) {
            ind+=siz;
            seg[ind]=val;
            while(ind>>=1) seg[ind]=op(seg[2*ind],seg[2*ind+1]);
        }

        void add(ll ind,t val) {
            ind+=siz;
            seg[ind]=op(seg[ind],val);
            while(ind>>=1) seg[ind]=op(seg[2*ind],seg[2*ind+1]);
        }

        t one_p(ll ind) {
            return seg[ind+siz];
        }

        t prod(ll lef,ll rig) { // [l,r)
            lef+=siz,rig+=siz;
            t opl=e(),opr=e();
            for(;lef<rig;lef>>=1,rig>>=1) {
                if(lef&1) opl=op(opl,seg[lef++]);
                if(rig&1) opr=op(seg[--rig],opr);
            }
            return op(opl,opr);
        }

        template<class c> ll max_right(ll lef,c judge) {
            ll LEF=lef+siz,wid=1; //LEF=seg列上の位置,lef=配列上のindex
            t ansl=e();
            for(;lef+wid<=n;LEF>>=1,wid<<=1) if(LEF&1) {
                if(!judge(op(ansl,seg[LEF]))) break;
                ansl=op(ansl,seg[LEF++]);
                lef+=wid;
            }
            while(LEF<<=1,wid>>=1) {
                //if(wid==0) break;
                if(lef+wid<=n && judge(op(ansl,seg[LEF]))) {
                    ansl=op(ansl,seg[LEF++]);
                    lef+=wid;
                }
            }
            return lef;
        }

        template<class c> ll min_left(ll rig,c judge) {
            ll RIG=rig+siz,wid=1;
            t ansr=e();
            for(;rig-wid>=0;RIG>>=1,wid<<=1) if(RIG&1) {
                if(!judge(op(seg[RIG-1],ansr))) break;
                ansr=op(seg[--RIG],ansr);
                rig-=wid;
            }
            while(RIG<<=1,wid>>=1) {
                //if(wid==0) break;
                if(rig-wid>=0 && judge(op(seg[RIG-1],ansr))) {
                    ansr=op(seg[--RIG],ansr);
                    rig-=wid;
                }
            }
            return rig;
        }
};

ll modpow(ll fl, ll po, ll mode) {  // mode: 0=modなし, 1=modあり
    ll ret=1;
    if (mode) {
        while (po>0) {
            if (po&1) ret=(ret*fl)%mod;
            fl=(fl*fl)%mod;
            po>>=1;
        }
    } else {
        while (po>0) {
            if(po&1) ret*=fl;
            fl*=fl;
            po>>=1;
        }
    }
    return ret;
}

ll op(ll a,ll b) {return a+b;}
ll e() {return 0ll;}

std::random_device rd;
std::mt19937_64 rng(rd());
std::uniform_int_distribution<unsigned long long> dist;

unsigned long long hash1(dist(rng) | 1ULL);
unsigned long long hash2(dist(rng) | 1ULL);

//ファイル読み込みは第二フォルダから ex:include "mathtype/hoge.hpp"
int main() {
    ll n,q; cin>>n>>q;
    segtree<unsigned long long> seg(n,op,e);
    segtree<unsigned long long> seg2(n,op,e);
    rep(i,q) {
        ll a,b; cin>>a>>b;
        a--; b--;
        if(a>b) swap(a,b);
        if(seg.prod(a,b)!=0 || seg2.prod(a,b)!=0) {
            no();
        }
        else {
            yes();
            unsigned long long rand=dist(rng);
            rand>>=2;
            seg.set(b,rand);
            seg.set(a,-1*rand);
            unsigned long long rand2=dist(rng);
            rand>>=2;
            seg2.set(b,rand2);
            seg2.set(a,-1*rand2);
        }
    }
}