import random
import subprocess
import tempfile
import os

def generate_test_case(max_cases=10, max_n=20, max_piece=50):
    """Generates a random block of test cases for the stick reconstruction problem."""
    num_cases = random.randint(1, max_cases)
    lines = []
    for _ in range(num_cases):
        n = random.randint(1, max_n)
        pieces = [random.randint(1, max_piece) for _ in range(n)]
        lines.append(str(n))
        lines.append(" ".join(map(str, pieces)))
    lines.append("0")
    return "\n".join(lines) + "\n"

def run_solution(executable, input_data):
    """Runs the given executable with input_data and returns its stdout."""
    result = subprocess.run([executable], input=input_data, text=True, capture_output=True)
    if result.returncode != 0:
        raise RuntimeError(f"Executable {executable} exited with code {result.returncode}:\n{result.stderr}")
    return result.stdout

def main():
    # Replace these with your compiled C++ executables
    sol1 = "./chat.exe"
    sol2 = "./11sticks.exe"

    # Ensure executables exist
    for sol in (sol1, sol2):
        if not os.path.isfile(sol) or not os.access(sol, os.X_OK):
            raise FileNotFoundError(f"Executable not found or not executable: {sol}")

    # Run multiple random tests
    for test_num in range(1, 101):
        tc = generate_test_case()
        out1 = run_solution(sol1, tc)
        out2 = run_solution(sol2, tc)
        if out1 != out2:
            print(f"Mismatch on test #{test_num}:\n{tc}")
            print("Output of solution1:\n", out1)
            print("Output of solution2:\n", out2)
            return
    print("All 100 random tests matched!")

if __name__ == "__main__":
    main()

# Save this script to a file
script_path = "/mnt/data/test_runner.py"
with open(script_path, "w") as f:
    f.write("""{}""".format(generate_test_case.__doc__ + "\n" + __import__('inspect').getsource(run_solution) + "\n" + __import__('inspect').getsource(main) + "\n"))
print(f"Test runner saved to {script_path}")
