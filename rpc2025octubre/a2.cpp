#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int f(int n, vector<int>& dp, vector<vector<int>>& longitud_valida)
{
    if(dp[n] != 0) return dp[n];

    for (int i = 0; i < 21; i++)
    {
        if(longitud_valida[n][i] != 0)
        {
            int aux=0;
            for (int j = 1; j <= longitud_valida[n][i]; j++)
            {
                int maxi = min(j, f(n-j, dp, longitud_valida));
                aux = max(aux, maxi);
            }
            dp[n]=max(dp[n], aux);
        }
    }
    return dp[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, h;
    cin >> n >> l >> h;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    const int K_OFFSET = 10;
    const int K_RANGE = 21;

    // --- FASE 1: Pre-cálculo (Sin cambios) ---
    // longitud_valida[i][k_idx] = Longitud del intervalo MÁS LARGO que 
    //                             termina en 'i' usando la transposición 'k'.
    vector<vector<int>> longitud_valida(n + 1, vector<int>(K_RANGE, 0));

    for (int i = 1; i <= n; ++i) {
        for (int k_idx = 0; k_idx < K_RANGE; ++k_idx) {
            int k = k_idx - K_OFFSET;
            int nota_t = a[i] + k * 12;

            if (nota_t >= l && nota_t <= h) {
                longitud_valida[i][k_idx] = longitud_valida[i - 1][k_idx] + 1;
            } else {
                longitud_valida[i][k_idx] = 0;
            }
        }
    }

    // --- FASE 2: DP Principal (Corregida a O(N^2 * K)) ---
    vector<int> dp(n + 1, 0);
    dp[0] = n + 1; // Caso base: "infinito"

    f(n, dp, longitud_valida);

    // La respuesta final
    cout << dp[n] << "\n";

    return 0;
}