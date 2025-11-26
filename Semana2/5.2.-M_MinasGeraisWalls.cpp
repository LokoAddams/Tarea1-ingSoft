#include <bits/stdc++.h>
using namespace std;

// Usando tus macros para familiaridad
#define form(i, s, e) for(int i = s; i < e; i++)
#define icin(x)  \
  int x;         \
  cin >> x;
#define endl '\n'
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef vector<ll> vll; // Usar long long para las alturas
typedef vector<int> vi;
typedef pair<ll, int> pli; // Par de (valor, indice)

// Constante para infinito (usada en los arreglos min)
const ll INF = 2e18; 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  icin(n);
  icin(k);
  vll nums(n);
  form(i, 0, n) cin >> nums[i];

  // --- 1. Pre-cálculo para "mínimo FUERA de la ventana" ---
  // O(N)
  vll prefix_min(n, INF);
  vll suffix_min(n, INF);

  prefix_min[0] = nums[0];
  form(i, 1, n) {
    prefix_min[i] = min(prefix_min[i - 1], nums[i]);
  }

  suffix_min[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix_min[i] = min(suffix_min[i + 1], nums[i]);
  }

  // --- 2. Preparación para "mínimo DENTRO de la ventana" ---
  // O(N)
  // Creamos el arreglo auxiliar y[j] = nums[j] + j
  vll y(n);
  form(i, 0, n) {
    y[i] = nums[i] + i;
  }

  // --- 3. El Sliding Window ---
  // O(N)
  // Deque para mantener el "Sliding Window Minimum" de y[j]
  // Almacena ÍNDICES
  deque<int> dq;
  ll max_global_min = -1; // La respuesta final

  // Iteramos i por todos los posibles puntos finales del refuerzo
  form(i, 0, n) {
    // ---- Lógica del Sliding Window Minimum ----

    // a. Eliminar índices que están fuera de la ventana
    // La ventana empieza en max(0, i - k + 1)
    // Así que eliminamos todo índice <= i - k
    while (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }

    // b. Mantener la propiedad monotónica (creciente)
    // Eliminamos de atrás cualquier cosa >= que el elemento actual (y[i])
    while (!dq.empty() && y[dq.back()] >= y[i]) {
      dq.pop_back();
    }

    // c. Añadir el índice actual
    dq.push_back(i);

    // ---- Cálculo de Mínimos ----

    // d. Mínimo DENTRO de la ventana
    // El índice del mínimo y[j] en la ventana [i-k+1, i] está en dq.front()
    // min(nums[j]+j) es y[dq.front()]
    // La altura mínima es (nums[j]+j) + k - i
    ll min_in_window = y[dq.front()] + k - i;

    // e. Mínimo FUERA de la ventana
    // Usamos los arreglos pre-calculados
    ll min_left = (i - k >= 0) ? prefix_min[i - k] : INF;
    ll min_right = (i + 1 < n) ? suffix_min[i + 1] : INF;
    ll min_out_window = min(min_left, min_right);
    
    // Si la ventana cubre todo (i-k < 0 y i+1 >= n), min_out es INF
    // lo cual está bien, ya que min() escogerá min_in_window

    // f. Mínimo global para este 'i'
    ll current_global_min = min(min_in_window, min_out_window);

    // g. Actualizar la respuesta
    max_global_min = max(max_global_min, current_global_min);
  }

  cout << max_global_min << endl;

  return 0;
}