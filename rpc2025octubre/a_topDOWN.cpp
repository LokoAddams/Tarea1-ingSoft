#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Variables globales para la recursión
int n, l, h;
vector<int> a;
vector<vector<int>> longitud_valida;
vector<int> memo; // Memoización para la Fase 2 (dp[i])

const int K_OFFSET = 10;
const int K_RANGE = 21;

// --- FASE 1: Pre-cálculo (Sin cambios) ---
void precompute() {
    longitud_valida.assign(n + 1, vector<int>(K_RANGE, 0));
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
}

// --- FASE 2: DP Principal (Top-Down Corregida) ---
// solve(i) calcula y devuelve el valor de dp[i]
int solve(int i) {
    // Caso base: prefijo vacío tiene longitud "infinita"
    if (i == 0) {
        return n + 1; 
    }

    // Verificar memoización
    if (memo[i] != -1) {
        return memo[i];
    }

    // Calcular el estado dp[i]
    int max_min_len = 0; // Resultado para dp[i]

    // Para cada nota i...
    for (int k_idx = 0; k_idx < K_RANGE; ++k_idx) {
        // ...probamos cada transposición k
            
        // L = Longitud MÁXIMA del último intervalo si usamos k
        int L = longitud_valida[i][k_idx];

        // *** LA CORRECCIÓN ESTÁ AQUÍ ***
        // Iteramos sobre CUALQUIER longitud 'j' desde 1 hasta L.
        for (int j = 1; j <= L; ++j) {
            // j = longitud del último segmento que estamos probando
            
            // La solución del prefijo antes de este segmento es solve(i - j)
            int solucion_prefijo = solve(i - j);
            
            // El mínimo para esta partición es min(j, solucion_prefijo)
            int min_len_actual = min(solucion_prefijo, j);

            // Queremos maximizar este valor
            max_min_len = max(max_min_len, min_len_actual);
        }
    }

    // Guardar en memo y devolver
    memo[i] = max_min_len;
    return memo[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> h;

    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 1. Ejecutar el pre-cálculo
    precompute();

    // 2. Inicializar la memoización con -1 (estado no calculado)
    memo.assign(n + 1, -1);

    // 3. Llamar a la función recursiva para n
    cout << solve(n) << "\n";

    return 0;
}