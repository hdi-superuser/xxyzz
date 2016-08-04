#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "main_lib.h"

/*
    Main testing program.
    Time complexity: O(M*N*(M+N)).
 */

bool fr[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int x, int y, int c) {
    int p = 1;
    queue <ii> q;   q.push(ii(x, y));   fr[x][y] = true;

    while (!q.empty()) {
        ii u = q.front();   q.pop();

        rep(t, 0, 3) {
            int nx = u.fst + dx[t], ny = u.snd + dy[t];
            if (nx < 1 || nx > m) continue;
            if (ny < 1 || ny > n) continue;
            if (fr[nx][ny]) continue;

            if (mat_res[nx][ny] == c) {
                p++;
                fr[nx][ny] = true;
                q.push(ii(nx, ny));
            }
        }
    }

    return p == a[abs(c)]*b[abs(c)];
}

bool ok_rect() {
    rep(i, 1, m) rep(j, 1, n) {
        if (fr[i][j] || mat_res[i][j] == 0) continue;
        if (!bfs(i, j, mat_res[i][j])) return false;
    }

    return true;
}

void excute_testing() {
    if (ok_rect()) cerr << "Check result: AC" << endl;
    else cerr << "Check result: WA" << endl;
}

#endif // TEST_H_INCLUDED
