#pragma once
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll = long long;

template<class T>
struct ValueHavinguf {
    vector<int> par;
    vector<int> siz;
    vector<T> info;
    function<T(const T&, const T&)> op;
    int count;

    ValueHavinguf(int N, function<T(const T&, const T&)> op_, const T& default_value=T())
    : par(N), siz(N, 1), info(N), op(move(op_)), count(N) {
        rep(i,N) { par[i]=i, info[i]=default_value; }
    }

    ValueHavinguf(const vector<T>& initial_info, function<T(const T&, const T&)> op_)
        : par((int)initial_info.size()), siz(initial_info.size(), 1),
          info(initial_info), op(move(op_)), count((int)initial_info.size())
    {
        rep(i,(int)par.size()) par[i] = i;
    }

    int root(int x){
        if(par[x]==x) return x;
        else return par[x]=root(par[x]);
    }

    void unite(int x,int y){
        int rx=root(x), ry=root(y);
        if (rx==ry) return;
        if (siz[rx]<siz[ry]) {
            par[rx]=ry;
            siz[ry]+=siz[rx];
            siz[rx]=0;
            info[ry]=op(info[rx], info[ry]);
            info[rx]=T();
        } else {
            par[ry]=rx;
            siz[rx]+=siz[ry];
            siz[ry]=0;
            info[rx]=op(info[rx], info[ry]);
            info[ry]=T();
        }
        --count;
    }

    bool same(int x,int y) {
        return root(x)==root(y);
    }

    int comp_count() {
        return count;
    }

    T& getinfo(int x) {
        return info[root(x)];
    }

    void setinfo(int x,const T& v) {
        info[root(x)]=v;
    }

    int size(int x) {
        return siz[root(x)];
    }
};