import subprocess
import random
import sys

def generar_caso():
    n = random.randint(2, 100)
    ciclos = [random.randint(10, 90) for _ in range(n)]
    return ciclos

def formatear_input(casos):
    lines = []
    for caso in casos:
        linea = ' '.join(map(str, caso)) + ' 0'
        lines.append(linea)
    lines.append("000")
    return '\n'.join(lines) + '\n'

def ejecutar(programa, entrada):
    try:
        resultado = subprocess.run(
            [programa],
            input=entrada.encode(),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=5
        )
        return resultado.stdout.decode().strip()
    except subprocess.TimeoutExpired:
        return "TIMEOUT"
    except Exception as e:
        return f"ERROR: {e}"

# 🔁 Comparar múltiples casos
for caso_num in range(1, 101):
    casos = [generar_caso() for _ in range(random.randint(1, 5))]
    entrada = formatear_input(casos)

    salida1 = ejecutar("./T2", entrada)
    salida2 = ejecutar("./T3", entrada)

    if salida1 != salida2:
        print(f"❌ Diferencia encontrada en caso {caso_num}")
        print("Entrada:\n", entrada)
        print("Salida 1:\n", salida1)
        print("Salida 2:\n", salida2)
        sys.exit(1)

print("✅ Todas las salidas coinciden en los 100 casos.")
