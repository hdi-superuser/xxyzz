#ifndef QUEUE_GREEDY_H_INCLUDED
#define QUEUE_GREEDY_H_INCLUDED

#include "main_lib.h"

/*
    Greedy with queue tricks.
 */

struct qrs_cmp {
    bool operator() (regions a, regions b) {
        return a.hi() != b.hi() ? a.hi() > b.hi() : a.wi() > b.wi();
    }
};

vector <rectangle> lrs;
vector <regions> lrs_result;

priority_queue <regions, vector <regions>, qrs_cmp > qrs;

bool pin[N];

bool lrs_cmp(rectangle a, rectangle b) {
    return a.a != b.a ? a.a > b.a : a.b > b.b;
}

void arrange_by_queue() {
    rep(i, 1, k) lrs.push_back(make_rectangle(a[i], b[i], i));
    qrs.push(make_regions(0, 0, m, n, 0));

    fill(pin + 1, pin + k + 1, false);
    lrs.push_back(make_rectangle(inf, inf, inf));
    sort(ALL(lrs), lrs_cmp);

    int cnt = 0;

    while (sz(qrs) && sz(lrs)) {
        regions reg = qrs.top();  qrs.pop();
        if (reg.isEmpty()) continue;

        int dif = inf, select_item = 0;
        rep(i, 1, sz(lrs) - 1) {
            if (pin[i]) continue;

            if (reg.hi() >= lrs[i].a && reg.wi() >= lrs[i].b) {
                int fit = reg.hi() - lrs[i].a + reg.wi() - lrs[i].b;
                if (dif > fit) dif = fit, select_item = i;
            }

            if (reg.hi() >= lrs[i].b && reg.wi() >= lrs[i].a) {
                int fit = reg.hi() - lrs[i].b + reg.wi() - lrs[i].a;
                if (dif > fit) dif = fit, select_item = -i;
            }
        }

        if (select_item == 0) return;
        pin[abs(select_item)] = true;
        rectangle obj = lrs[abs(select_item)];

        int d = (select_item > 0 ? obj.a : obj.b);
        int r = (select_item > 0 ? obj.b : obj.a);

        lrs_result.push_back(make_regions(reg.x1, reg.y1, reg.x1 + d, reg.y1 + r, lrs[select_item].idx));
        if (++cnt >= k) { finish = true; return; }

        pair<regions, regions> n_obj1, n_obj2;

        n_obj1.fst.x1 = reg.x1;         n_obj1.fst.y1 = reg.y1 + r;
        n_obj1.fst.x2 = reg.x2;         n_obj1.fst.y2 = reg.y2;
        n_obj1.snd.x1 = reg.x1 + d;     n_obj1.snd.y1 = reg.y1;
        n_obj1.snd.x2 = reg.x2;         n_obj1.snd.y2 = reg.y1 + r;

        n_obj2.fst.x1 = reg.x1;         n_obj2.fst.y1 = reg.y1 + r;
        n_obj2.fst.x2 = reg.x1 + d;     n_obj2.fst.y2 = reg.y2;
        n_obj2.snd.x1 = reg.x1 + d;     n_obj2.snd.y1 = reg.y1;
        n_obj2.snd.x2 = reg.x2;         n_obj2.snd.y2 = reg.y2;

        int n_size_1 = max(n_obj1.fst.size(), n_obj1.snd.size());
        int n_size_2 = max(n_obj2.fst.size(), n_obj2.snd.size());

        if (n_size_1 > n_size_2) {
            if (!n_obj1.fst.isEmpty()) qrs.push(n_obj1.fst);
            if (!n_obj1.snd.isEmpty()) qrs.push(n_obj1.snd);
        } else {
            if (!n_obj2.fst.isEmpty()) qrs.push(n_obj2.fst);
            if (!n_obj2.snd.isEmpty()) qrs.push(n_obj2.snd);
        }
    }
}

void generate_mat_res() {
    rep(i, 0, sz(lrs_result) - 1) {
        regions R = lrs_result[i];
        put(R.x1 + 1, R.y1 + 1, R.x2, R.y2, R.color);
    }
    back_up();
}

void queue_greedy(int m, int n, int k, int a[], int b[]) {
    arrange_by_queue();
    if (finish) generate_mat_res();
}

#endif // QUEUE_GREEDY_H_INCLUDED
