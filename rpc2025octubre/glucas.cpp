#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

// --- Implementación de Grafo y Tarjan para SCC ---

int n_graph; // Número de nodos (nombres únicos)
vector<vector<int>> adj; // Lista de adyacencia
vector<vector<int>> adj_scc; // Lista de adyacencia del grafo condensado (DAG)

// Variables para Tarjan
vector<int> disc; // Tiempo de descubrimiento
vector<int> low;  // Low-link (el ancestro más antiguo alcanzable)
stack<int> st;
vector<bool> onStack;
int timer;
vector<int> scc; // scc[i] = ID del componente al que pertenece el nodo i
int scc_count;   // Contador de SCCs

void find_scc(int u) {
    disc[u] = low[u] = timer++;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) { // No visitado
            find_scc(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) { // Back-edge a un nodo en el stack
            low[u] = min(low[u], disc[v]);
        }
    }

    // Si u es la raíz de un SCC
    if (low[u] == disc[u]) {
        scc_count++;
        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;
            scc[v] = scc_count; // Asignar ID de SCC
            if (u == v) break;
        }
    }
}

// Mapa para nombres
map<string, int> nameToId;
set<string> allNames;
int nextId = 0;

int getId(const string& name) {
    if (nameToId.find(name) == nameToId.end()) {
        nameToId[name] = nextId++;
    }
    return nameToId[name];
}

// --- Fin de la implementación de Grafo ---


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); // Consumir salto de línea

    if (n == 0) {
        cout << "possible\n";
        return 0;
    }

    // --- 1. Construir el Grafo ---
    int max_nodes = 2 * n + 5;
    adj.resize(max_nodes);

    string delimiter = ", son of ";
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        size_t pos = line.find(delimiter);
        if (pos == string::npos) continue;

        string childName = line.substr(0, pos);
        string fatherName = line.substr(pos + delimiter.length());

        allNames.insert(childName);
        allNames.insert(fatherName);

        int fatherId = getId(fatherName);
        int childId = getId(childName);

        adj[fatherId].push_back(childId); // Arista: Padre -> Hijo
    }

    n_graph = nextId; // Número total de nombres únicos

    // --- 2. Encontrar SCCs con Tarjan ---
    disc.assign(n_graph, -1);
    low.assign(n_graph, -1);
    onStack.assign(n_graph, false);
    scc.assign(n_graph, 0);
    timer = 0;
    scc_count = 0;

    // Ejecutar Tarjan en todos los nodos no visitados
    for (int i = 0; i < n_graph; ++i) {
        if (disc[i] == -1) {
            find_scc(i);
        }
    }

    // --- 3. Contar Raíces en el Grafo Condensado (DAG) ---
    
    // Si no hay nodos (n=0 ya se manejó), pero por si acaso
    if (n_graph == 0) { 
        cout << "possible\n";
        return 0;
    }

    vector<int> indegree_scc(scc_count + 1, 0);

    // Construir el DAG y calcular indegrees
    for (int u = 0; u < n_graph; ++u) {
        for (int v : adj[u]) {
            // Si u y v están en diferentes SCCs, es una arista en el DAG
            if (scc[u] != scc[v]) {
                indegree_scc[scc[v]]++; // Flecha de scc[u] -> scc[v]
            }
        } 
    }

    // Contar el número de "raíces" (SCCs con indegree 0)
    int root_count = 0;
    for (int i = 1; i <= scc_count; ++i) {
        if (indegree_scc[i] == 0) {
            root_count++;
        }
    }

    // --- 4. Dar el Resultado ---
    if (root_count == 1) {
        cout << "possible\n";
    } else {
        // Si hay 0 o más de 1 raíz, es imposible
        cout << "impossible\n";
    }

    return 0;
}