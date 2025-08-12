#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        vector<int> A;
        int x;
        // Leer un escenario
        while (cin >> x && x != 0) {
            A.push_back(x);
        }
        // Terminación total si el primer es cero y no hay nada más
        if (A.empty()) break;

        int n = A.size();
        int start = *min_element(A.begin(), A.end());
        int result = -1;

        // Simular tiempo desde t = start (o sea, después del primer verde)
        for (int t = start; t <= 18000; ++t) {
            bool allGreen = true;
            for (int i = 0; i < n; ++i) {
                int cycle = 2 * A[i];
                int m = t % cycle;
                if (m >= A[i] - 5) { // si está en naranja o rojo
                    allGreen = false;
                    break;
                }
            }
            if (allGreen) {
                result = t;
                break;
            }
        }

        if (result < 0) {
            cout << "Signals fail to synchronise in 5 hours\n";
        } else {
            int h = result / 3600;
            int m = (result % 3600) / 60;
            int s = result % 60;
            cout << setw(2) << setfill('0') << h << ":"
                 << setw(2) << m << ":"
                 << setw(2) << s << "\n";
        }
    }

    return 0;
}
