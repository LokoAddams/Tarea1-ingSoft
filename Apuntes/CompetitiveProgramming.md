## Questions

- ¿ Cual es la mejor forma de determinar si una solucion entra en tiempo?
    - Remplazar en Big O() y si es menor a 10^8 entra en 1 segundo(¿acaso esto no es variable ya que big O no toma en cuenta constantes?)
    - Ya que una pc puede realizar 10^8 operaciones aprox(depende GHZ cpu, etc) , (N° operaciones / 10^8)

## Recordatorios
- Para la competencia puedes hacer el snipped en cualquier archivo no coloques tabs, luego remplaza \r?\n por \\n, no te olvides el snipped de out


## Chapter 1

1.  En big O siempre que hay un log es base 2 a menos que se aclare lo contrario.
2.  Una pc puede hacer 10^8 OPERACIONES por segundo, si un ciclo es 0 -> 10^8 pero tiene en su interior 30 operaciones eso son 30 segundos

```C++
int main()
{
    long long a = 0;
    for(long long i = 0; i < 1e8 ; i++)
    {
        for(int j = 0; j < 30 ; j++)
            a += i;
    }
    return 0;
}
```

3.  factorial de 10^14 es absurdamente grande entonces si queremos saber si n! es divisible por m podemos no calcular n! y simplemente expresarlo en numeros primos y descomponer m tambien en numeros primos y verificar si los numeros primos de m estan en los primos de n!
4.  Usar comandos para comparar input y output
5.  TLE si la complejidad es correcta hay un ciclo infinito
6.  Precomputar
    - cuando la variable es GLOBAL se hace en tiempo de COMPILACION
    - cuando es LOCAL se hace en tiempo de EJECUCION

```C++
ll a[92+1] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, ....};
ll fibo(ll n)
{
    if(a[n] != 0)
    {
        return a[n];
    }
    else
    {
        a[n] = fibo(n-1) + fibo(n-2);
        return a[n];
    }
}
int main() {
    ll b[92+1] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, ...};
    return 0;
}
```

- Para precomputar estructuras de datos complejas debemos precomputarlas en un array y luego insertarlas a nuestra estructura.

```C++
ll a[92+1] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, ...};
ll fibo(ll n)
{
    if(a[n] != 0) 
        return a[n];
    else
    {
        a[n] = fibo(n-1) + fibo(n-2);
        return a[n];
    }
}
int main() {
    priority_queue<int> b;
    for(auto i: a)
        b.push(i);
    int i = 0;
    while(!(b.empty()))
    {
        b.pop();
        i++;
    }
    cout << i; // output: "93"
    return 0;
}
```

- esto tambien es posible

```C++
  vector<long long> a = { 0, 1, 1, 2, 3, 5, 8, 13, 21, ...};
```

## Chapter 2
### 2.4. Data Structures with our own libraries
#### 2.4.1. Graphs

- Equivocacion libro: "The Adjacency Matrix AM" pag.95  
    ![alt text](image.png)
- Mejor no usar tuple  
    ![alt text](image-1.png)
- Para grafos con vertices no contiguos(contiguos: 1, 2, 3... - no contiguos: nombres, etc) es buena idea usar `unordered_map`

```C++
unordered_map< llave , valor>
unordered_map< string , vector<int>> graph;
```

- for auto en unordered_map solo recorre las llaves que existe no la hash completa

```C++
mapita["lucas"] = 1;
mapita["leo"] = 7;
mapita["mario"] = 4;
for(auto i: mapita)
{
    cout << i << endl;
}
//output:"7, 4, 1" ya que es una hash,
el orden no depende de como hayamos ingresado los datos
```

- Un grafo completo(o tambien llamado Convexo) tiene Vx(V-1)/2 aristas donde V=vertices
    - Para un grafo completo no dirigido O(Vx(V-1))  
        ![alt text](image-2.png)
    - Para un grafo completo dirigido O(Vx(V-1)/2)
    - Con un array de padres puedes obtener el Spanning Tree(arbol de expansion) generado por un DFS/BFS

```C++
p[1] = -1   // raíz no tiene padre
p[2] = 1
p[3] = 1
p[4] = 1
p[5] = 2
p[6] = 2
```

- In-degree y Out-degree  
    A → B  
    A → C  
    D → A  
    Entonces:
    - grado de salida(Out-degree) de A = 2 (porque va hacia B y C)
    - grado de ingreso(In-degree) de A = 1 (porque D apunta hacia A)
- Traspuesta de una matriz  
    ![alt text](image-3.png)
- Grafo estrella  
    ![alt text](image-4.png)
    - Los grafos estrella son bipartitos si tomamos al vertice del medio como parte del conjunto A y a todos los demas como parte del conjunto B.
- Grafo complementario.- contiene todas las aristas que no existen en el grafo original  
    ![alt text](image-5.png)

#### 2.4.2. Uniond find

Tambien se puede usar `set<>`

```C++
int main() {
    std::set<int> A = {1, 3, 5, 7};
    std::set<int> B = {2, 3, 6, 7, 8};

    // Opción 1: modificar A para que sea A ∪ B
    A.insert(B.begin(), B.end());
    // Ahora A == {1,2,3,5,6,7,8}
}
```

#### 2.4.3. fenwick tree

- Cuando ii es potencia de 2 (2, 4, 8), el rango es \[1..i\]\[1..i\].
- Para impares no potencias de 2, el rango es trivial \[i..i\]\[i..i\].
- En valores intermedios (6, 10, …), agrupa los últimos 2 o más elementos según LSOne(i)LSOne(i).

#### 2.4.3. Segment Tree
- Build O(V) donde v son los vertices del segment tree, entonces si construimos un st en base a un vector A con tamaño "A" , Build(4*A)
- ¿Por que st es de tamaño 4*A?
    - Un arbol binario de tamaño de exactamente alguna potencia de 2 tiene 2*n nodos(n = nodos de la base(nodos hoja), en esta caso el vector original A).Entonces "un arbol con un tamaño menor" como n-1, NO va a tener mas de 2*n nodos. Por eso hacemos que nuestro tamaño A sea la siguiente potencia de dos, la cual no es mas del doble de A lo cual es 2*A, entonces si tamaño_arbol_mas_grande = 2*A, sus nodos seran 2*tamaño_arbol_mas_grande, lo que es equivalente a 2*2*A.
    - ⌊x⌋ trucar(aproximacion hacia abajo 3.88 = 3)
    - ⌈x⌉ redondear(aproximacion hacia arriba 3.88 = 4)
    - 2\*2^⌈(log2(n))⌉ = 2\*2\*n
- Cuando hacemos un update realmente no se actualizan los nodos hojas, sino solo actualizamos x de los nodos superiores, done x \< N (donde x es mucho menor que N), en vez de N actualizaciones(lazy propagation), solo cuando el nodo hoja sea consultado con una QUERY ese nodo sera actualizado.
    - Lazy update = actualizacion retrasada

| ![alt text](image-7.png) |
|:---------------------------:|
| _UPDATE(l=7,r=23,val=99)_ |
|_Lo que esta en morado no fue realmente actualizado en A pero si sus rangos(nodos superiores), los nodos encerrados en rojo tuvieron que ser actualizados ya que ningun nodo superior cubre su rango la gran ventaja fue que actualizamos 6 nodos en total en vez de los 16 nodos hoja_  |
### 2.3. Non-Linear Data Structures with built-in libraries
#### 2.3.1. Priority_queue
Por defecto es de MAYOR a MENOR, osea mayor en el top.
Podemos invertir el orden convirtiendo todos los numeros a negativos.
##### Create
- O(n)
```C++
vector<int> d = {12,3,4,3,3,5,34,343,5325,235,23452,3532};
priority_queue<int> a (d.begin(), d.end());
```
- O(n * log n)
```C++
vector<int> d = {12,3,4,3,3,5,34,343,5325,235,23452,3532};
priority_queue<int> a;
for(auto i: d)
    a.push(i);
```
##### Partial Sort
Cuando Solo necesitamos los primeros k elementos de un array.
![alt text](image-8.png)

##### Update and delete on priority_queue C++
Update: Dijskstra lo utiza de forma indirecta ya que efectivamente ****C++ no permite hacer `update()` directamente en un `priority_queue`**** pero podemos usar **#include <bits/extc++.h>** que tiene una version extendida de priority queue.

*****Entonces... ¿Cómo se simula el `update()` en C++?*****
La técnica que se usa (como en el código del libro) es:
****Simplemente **se inserta una nueva copia** con la mejor distancia:****
```cpp
pq.push({dist[v], v});
```
Y luego, **al sacar el tope de la cola**, se verifica si esa copia es válida o desactualizada:
```cpp
auto [d, u] = pq.top(); pq.pop();
if (d > dist[u]) continue; // ⚠ muy importante
```
****¿Por qué esto funciona?****
Supongamos que a un vértice `u` se le insertó una copia con `dist[u] = 10`, pero luego se encontró un mejor camino con `dist[u] = 6`. Entonces ahora habrá **dos copias** de `u` en la cola:
* `{10, u}` (vieja)
* `{6, u}` (nueva)

Como el `priority_queue` ordena por el valor más bajo (`greater<ii>`), la copia con `6` saldrá primero. Cuando salga:

```cpp
if (d > dist[u]) continue;
```

El `d == dist[u]`, así que **se procesa**.

Pero luego, cuando salga `{10, u}`, se ejecuta:

```cpp
if (d > dist[u]) continue;
```

→ Como `10 > 6`, esa copia se **descarta** (se ignora), y así se evita hacer trabajo innecesario o incorrecto.

- Delete: se me ocurre que podriamos hacer algo similar al update, pero en vez de 6 que es el valor que no ayuda a descartar a 10 con un valor muy pequeño que en realidad no existe.

###### Nota: Tener en cuenta que esto solo funciona si la actualizacion siempre es menor, o siempre es mayor, ya que solo asi se puede hacer el descarte.

#### Hash table
Es muy importante que segun la entrada, reservemos la cantidad de espacios a 2*N previamente para evitar rehashings.

##### unordered_map
Almacena pares CLAVE,VALOR
- Tamaño ideal n*1.33
```C++
int n = 1e6;
unordered_map<string,int> a;
a.reserve(n*1.33);
// Este 1.33 se puede demostrar con la formula
// si no recuerdo mal dependia de los numeros primos
```
- Acceso con claves
```C++
unordered_map<string,int> a;
a["lucas"] = 10;
// si no habia nada en lucas a["lucas"] devuelve 0
```
##### unordered_set
Solo valores, te dice si una clave existe o no
```C++
//
unordered_set<string> a;
if(a.find("lucas") != a.end())
    cout << "existe" << endl;
```

##### Es posible modificar la formula de una hash
```C++
const int input = 1e5;
struct formula{
  size_t operator()(const pair<string, string>& s) const {
    long long sum = 0;
    int mult = 1;
    for(auto i:s.first)
    {
      sum += (mult*i);
      mult++;
    }
    mult = 1;
    for(auto i:s.second)
    {
      sum += (mult*i);
      mult++;
    }
    return sum%int(input);
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  unordered_set<pair<string , string>, formula> my_hash;
  my_hash.reserve(input);// INPUT
  string a, b;
  while (cin >> a >> b)
  {
    my_hash.insert({a, b});
  }
  
  for(auto i: my_hash)
    cout << i.first << " " << i.second << endl;
  cout << my_hash.load_factor() << endl;
  // Promedio de colisiones
      
  return 0;
}
```

#### BST
##### Map (Clave->valor)
Es un BBST(balanced binary search tree) en c++ esta implementado como Reb Black Tree con punteros(al estar implementado con punteros la cache tiene que acceder a memoria no continua y por lo tanto no es tan eficiente).

- *****¿ Si begin(devuelve el menor elemento) O(1) + erase es O(log n) por que existe priority queue top O(1) + pop O(log n)?*****
Aunque la complejidad asintotica es la misma en al ejecucion el hecho de usar punteros hace la diferencia.Ya que la priority queue usa un array(hijo derecho(2*p) , hijo izquierdo (2*p +1)) el acceso a memoria es casi secuencial.

- *****Ordenado*****
Entonces lo podemos recorrer en orden(de menor a mayor) con:
```C++
for(auto& i: map)
```

###### Nota: tambien podemos usar upper_bound y lower_bound

##### Multimap(clave->valor)
Permite varios valores con la misma clave.

##### Set(solo valores)
No permited elementos duplicados, como tambien es un BBST tambiem podemos recorrerlo en orden usar upper_bound y lower bound , begin es el menor, end el mayor ,etc.

- Obtener el k-esimo elemento de un BST cualquiera con advance O(n), pero con order statistic tree es O(n log n)
```C++
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set<int> a;// Cualquier otro arbol
  form(i,1,10)
    a.insert(i);
  auto it = a.begin();
  advance(it, 5);/* O(n) por que son punteros 
  entonces realmente los recorre como una lista enlazada*/
  cout << (it).operator*() << endl;
  //output: 6
  return 0;
}
```

#### Order Statistic Tree
- Ranking(v) = posicion del elemento v
- Select(k) = k-esimo elemento mas pequeño
##### Quick sort O(n log n)
- Al colocar todos los mayores y menores al pivote, a los costados del pivote genera que el pivote este en el indice que le correspondera cuando el array este completamente ordenado.
arr = [4,8,10,2,1,9] 
primer partition con pivote 4:[2,1,4,10,8,9]
4 ya esta en el lugar que le corresponde cuando todo el array este completamente ordenado [1,2,4,8,9,10], entonces podemos dejarlo ahi ([2,1,4,10,8,9]) y concentrarnos en colocar los demas en sus lugares.
##### Quick Select(Select(k) = k-esimo elemento mas pequeño)
Podemos hacer el mismo procedimiento de quick sort y cuando el pivote sea el k-esimo elemento paramos.

##### Tree para select en O(n* log n)(#include <bits/extc++.h>) 
```C++
#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>                         // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

int main() {
  int n = 9;
  int A[] = { 2, 4, 7,10,15,23,50,65,71};        // as in Chapter 2
  ost tree;
  for (int i = 0; i < n; ++i)                    // O(n log n)
    tree.insert(A[i]);
  // O(log n) select
  cout << *tree.find_by_order(0) << "\n";        // 1-smallest = 2
  cout << *tree.find_by_order(n-1) << "\n";      // 9-smallest/largest = 71
  cout << *tree.find_by_order(4) << "\n";        // 5-smallest = 15
  // O(log n) rank
  cout << tree.order_of_key(2) << "\n";          // index 0 (rank 1)
  cout << tree.order_of_key(71) << "\n";         // index 8 (rank 9)
  cout << tree.order_of_key(15) << "\n";         // index 4 (rank 5)
  
  return 0;
}
```
## Chapter 3
### 3.2. Complete Search


## Chapter 5
### 5.3. Number Theory
- Mersenne prime numbers
Un primo de Mersenne es todo número que puede escribirse 
    - M=(2^p)-1 
Donde p es primo, si p no es primo M es compuesto.

### 5.4. Combinatorics
