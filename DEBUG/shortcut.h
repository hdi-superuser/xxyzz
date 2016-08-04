#ifndef SHORTCUT_H_INCLUDED
#define SHORTCUT_H_INCLUDED

#include "main_lib.h"

using namespace std;

/*
    C++ shortcut.
    Shortcut for faster and greater than code.
 */

#define fst first
#define snd second
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define ALL(x) (x).begin(), (x).end()
#define popcnt(x) __builtin_popcount(x)
#define remain(x) if (x > MOD) x -= MOD
#define rep(i, j, k) for (int i = j; i <= k; i++)
#define dow(i, j, k) for (int i = j; i >= k; i--)
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void outln() { cout << endl; }
template<typename T> void in(T& x) { cin >> x; }
template<typename T> void out(T x) { cout << x; }
template<typename T> void outln(T x) { cout << x << endl; }
template<typename T> void outbrk(T x) { cout << x; exit(0); }
template<typename T, typename X> void out(T x, X y) { cout << x << y; }

#endif // SHORTCUT_H_INCLUDED
