---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/structure/ValueHavingUF.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define rep(i,n) for(ll i=0;i<n;i++)\nusing ll = long long;\n\
    \ntemplate<class T>\nstruct ValueHavinguf {\n    vector<int> par;\n    vector<int>\
    \ siz;\n    vector<T> info;\n    function<T(const T&, const T&)> op;\n    int\
    \ count;\n\n    ValueHavinguf(int N, function<T(const T&, const T&)> op_, const\
    \ T& default_value=T())\n    : par(N), siz(N, 1), info(N), op(move(op_)), count(N)\
    \ {\n        rep(i,N) { par[i]=i, info[i]=default_value; }\n    }\n\n    ValueHavinguf(const\
    \ vector<T>& initial_info, function<T(const T&, const T&)> op_)\n        : par((int)initial_info.size()),\
    \ siz(initial_info.size(), 1),\n          info(initial_info), op(move(op_)), count((int)initial_info.size())\n\
    \    {\n        rep(i,(int)par.size()) par[i] = i;\n    }\n\n    int root(int\
    \ x){\n        if(par[x]==x) return x;\n        else return par[x]=root(par[x]);\n\
    \    }\n\n    void unite(int x,int y){\n        int rx=root(x), ry=root(y);\n\
    \        if (rx==ry) return;\n        if (siz[rx]<siz[ry]) {\n            par[rx]=ry;\n\
    \            siz[ry]+=siz[rx];\n            siz[rx]=0;\n            info[ry]=op(info[rx],\
    \ info[ry]);\n            info[rx]=T();\n        } else {\n            par[ry]=rx;\n\
    \            siz[rx]+=siz[ry];\n            siz[ry]=0;\n            info[rx]=op(info[rx],\
    \ info[ry]);\n            info[ry]=T();\n        }\n        --count;\n    }\n\n\
    \    bool same(int x,int y) {\n        return root(x)==root(y);\n    }\n\n   \
    \ int comp_count() {\n        return count;\n    }\n\n    T& getinfo(int x) {\n\
    \        return info[root(x)];\n    }\n\n    void setinfo(int x,const T& v) {\n\
    \        info[root(x)]=v;\n    }\n\n    int size(int x) {\n        return siz[root(x)];\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n#define rep(i,n)\
    \ for(ll i=0;i<n;i++)\nusing ll = long long;\n\ntemplate<class T>\nstruct ValueHavinguf\
    \ {\n    vector<int> par;\n    vector<int> siz;\n    vector<T> info;\n    function<T(const\
    \ T&, const T&)> op;\n    int count;\n\n    ValueHavinguf(int N, function<T(const\
    \ T&, const T&)> op_, const T& default_value=T())\n    : par(N), siz(N, 1), info(N),\
    \ op(move(op_)), count(N) {\n        rep(i,N) { par[i]=i, info[i]=default_value;\
    \ }\n    }\n\n    ValueHavinguf(const vector<T>& initial_info, function<T(const\
    \ T&, const T&)> op_)\n        : par((int)initial_info.size()), siz(initial_info.size(),\
    \ 1),\n          info(initial_info), op(move(op_)), count((int)initial_info.size())\n\
    \    {\n        rep(i,(int)par.size()) par[i] = i;\n    }\n\n    int root(int\
    \ x){\n        if(par[x]==x) return x;\n        else return par[x]=root(par[x]);\n\
    \    }\n\n    void unite(int x,int y){\n        int rx=root(x), ry=root(y);\n\
    \        if (rx==ry) return;\n        if (siz[rx]<siz[ry]) {\n            par[rx]=ry;\n\
    \            siz[ry]+=siz[rx];\n            siz[rx]=0;\n            info[ry]=op(info[rx],\
    \ info[ry]);\n            info[rx]=T();\n        } else {\n            par[ry]=rx;\n\
    \            siz[rx]+=siz[ry];\n            siz[ry]=0;\n            info[rx]=op(info[rx],\
    \ info[ry]);\n            info[ry]=T();\n        }\n        --count;\n    }\n\n\
    \    bool same(int x,int y) {\n        return root(x)==root(y);\n    }\n\n   \
    \ int comp_count() {\n        return count;\n    }\n\n    T& getinfo(int x) {\n\
    \        return info[root(x)];\n    }\n\n    void setinfo(int x,const T& v) {\n\
    \        info[root(x)]=v;\n    }\n\n    int size(int x) {\n        return siz[root(x)];\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/structure/ValueHavingUF.hpp
  requiredBy: []
  timestamp: '2025-09-05 22:53:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/structure/ValueHavingUF.hpp
layout: document
redirect_from:
- /library/library/structure/ValueHavingUF.hpp
- /library/library/structure/ValueHavingUF.hpp.html
title: library/structure/ValueHavingUF.hpp
---
