def algo_potencias(N):
    # arr[j] contará cuántas veces j es una potencia de algún i
    arr = [0] * N

    for i in range(2, N):
        j = i * i
        # mientras j = i^k siga dentro de rango...
        while j < N:
            arr[j] += 1
            j *= i        # paso a la siguiente potencia: i^k → i^(k+1)

    return arr

def uno(arr):
    numeritos = []
    for i in range(2, len(arr)):
        if arr[i] > 1:
            numeritos.append(i)
            print(f"{i} es potencia de algún i (marcado {arr[i]} veces)")
    return numeritos

if __name__ == "__main__":
    N = int(2e19)       # elige un N razonable para tu entorno
    arr = algo_potencias(N)
    resultado = uno(arr)
