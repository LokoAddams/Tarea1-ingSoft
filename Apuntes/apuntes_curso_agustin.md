## 1.next permutation
ordenado, cuidado con duplicados

## 2.backtracking
- en cada paso evaluamos(si fallan los chequeos cortamos y no seguimos), no solo al final
- no tiene que ser recursivo obligatoriamente

## 3.Grafos
- si tenemos una matriz de adyacencias la podemos representar con bitset y para saber las adyacencias en comun podemos hacer un AND

## 4.Preguntas
El uso de memoria se toma en cuenta igual con las variables destruidas?

## 5.Multiconjuntos vs conjuntos
- Multiconjuntos.-Los elementos pueden repetirse.
- Conjunto.-Cada elemento aparece una sola vez.

## 6.Operaciones Combinables
Si una operacion es combinable, Lo podemos usar con Segment Trees, rerooting, divide & conquer, etc.
- ¿Que es combinable?
Podemos calcular el resultado para un conjunto grande A ∪ B usando solo los resultados ya calculados para los subconjuntos A y B, sin tener que ver los elementos individuales de nuevo.

##### 🔴 Pero... ¿la asociatividad garantiza que sea combinable?
**NO siempre. Aquí está el contraejemplo prometido.**
##### ❌ Contraejemplo: **mediana**
La **mediana** es una función común en análisis de datos. Veamos por qué **no es combinable**, aunque la operación que uno podría pensar (ordenar y tomar el del medio) **es técnicamente asociativa** si tratás conjuntos como listas ordenadas.
##### Imaginá:
* $A = \{1, 9\}$ → mediana(A) = 5 (promedio de 1 y 9)
* $B = \{3, 7\}$ → mediana(B) = 5 (promedio de 3 y 7)
¿La mediana de $A \cup B = \{1, 3, 7, 9\}$ es 5?
✅ Sí, casualmente sí.
Pero ahora:
* $A = \{1, 1, 1\}$ → mediana(A) = 1
* $B = \{9, 9, 9\}$ → mediana(B) = 9
Entonces:
* valor(A) = 1
* valor(B) = 9
¿Podés combinar esos dos valores `1` y `9` y obtener la mediana de $A \cup B = \{1, 1, 1, 9, 9, 9\}$, que es 5?
❌ ¡No! No hay forma de deducir eso **solo con saber que A = 1 y B = 9**.
Porque la mediana **depende del conjunto completo y del orden**, no se puede reducir a un solo número.
##### 🔍 ¿Qué pasa aquí?
* **La mediana no es una operación binaria sobre "valores acumulados"**.
* No tiene una regla tipo $\text{mediana}(A \cup B) = f(\text{mediana}(A), \text{mediana}(B))$
* Aunque podamos ordenar listas y combinar resultados, **el resultado depende del contenido completo**, no solo de un resumen parcial.
##### ✅ Conclusión
* Si una operación es **asociativa y tiene una representación acumulable**, entonces sí, **es combinable**.
* **Pero no toda función asociativa en sentido amplio** (como funciones estadísticas) **es combinable en el sentido útil para algoritmos**.

## Viernes
- input 
getline, string stream

dijskstra n2 sin priority_queue

suma de prefijos y sufijos
es mas facil combinar que desarmar

lowest commong ancestor con segment Tree en base a Euler Tour

### Probabilidad
Saber diferenciar si los eventos son mutuamente excluyentes, no pueden pasar a la vez.
p1, p2 disjuntos 1 = p1+p2
p1, p2 juntos 1 = p1+p2-(P(p1,p2))
independientes != disjuntos
dependiente ejemplo.-la suma de dos dados sea x?
independientes.- primero salga x y segundo z
si no son independientes no podemos multiplicar

Propiedad de la esperanza funciona aunque x y z no sean independientes