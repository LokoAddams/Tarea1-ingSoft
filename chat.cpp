#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<char> used;
int targetLen, need;

bool dfs(int cur, int start, int built) {
    // Si ya armamos need-1 palos, el último se determina automáticamente
    if (built == need - 1) return true;

    if (cur == targetLen) {
        // Empezar un nuevo palo
        return dfs(0, 0, built + 1);
    }

    int last = -1; // para saltar duplicados en este nivel
    for (int i = start; i < n; ++i) {
        if (used[i]) continue;
        int x = a[i];
        if (x == last) continue;          // evita duplicados
        if (cur + x > targetLen) continue;

        used[i] = 1;
        if (dfs(cur + x, i + 1, built)) return true;
        used[i] = 0;

        last = x;

        // Poda 1: si no pudimos colocar nada al inicio de un palo, no hay solución
        if (cur == 0) return false;
        // Poda 2: si intentamos cerrar el palo y falla, no seguir
        if (cur + x == targetLen) return false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n && n) {
        a.resize(n);
        int sum = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }

        sort(a.begin(), a.end(), greater<int>());

        int answer = sum;
        for (targetLen = mx; targetLen <= sum; ++targetLen) {
            if (sum % targetLen) continue;
            need = sum / targetLen;
            used.assign(n, 0);
            if (dfs(0, 0, 0)) { answer = targetLen; break; }
        }
        cout << answer << "\n";
    }
    return 0;
}
