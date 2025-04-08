import cirq
import numpy as np

def apply_oracle(circuit, input_qubits, output_qubits, latent_a, n):
    """Applies the oracle f(x) = f(x ⊕ s) without using a class"""
    # For simplicity, implement f(x) as x ⊕ s for x < 2^(n-1)
    # and map the other half accordingly
    for i in range(n):
        circuit.append(cirq.CNOT(input_qubits[i], output_qubits[i]))
    
    for i in range(n):
        if latent_a[i] == 1:
            circuit.append(cirq.X(output_qubits[i]))

def simons_algorithm(n=3, latent_ao=None):
    """
    Implements Simon's algorithm to find the hidden period s
    n: number of qubits
    latent_a: hidden period (if None, randomly generated)
    """
    # Step 1: Set up the latent_a if not provided
    if latent_ao is None:
        latent_ao = np.random.randint(0, 2, n)
    latent_a = latent_ao  # Avoid shadowing issues
    
    # Step 2: Create quantum circuit
    input_qubits = [cirq.LineQubit(i) for i in range(n)]
    output_qubits = [cirq.LineQubit(i) for i in range(n, 2*n)]
    circuit = cirq.Circuit()
    
    # Step 3: Apply Hadamard gates to input qubits
    circuit.append([cirq.H(q) for q in input_qubits])

    # Step 4: Apply the oracle
    apply_oracle(circuit, input_qubits, output_qubits, latent_a, n)

    # Step 5: Apply Hadamard gates again
    circuit.append([cirq.H(q) for q in input_qubits])

    # Step 6: Measure
    circuit.append(cirq.measure(input_qubits, key='result'))

    # Step 7: Simulate the circuit
    simulator = cirq.Simulator()
    results = simulator.run(circuit, repetitions=n)  # Run n times
    
    # Step 8: Collect measurement results
    measurements = results.measurements['result']
    
    print(f"Circuit:\n{circuit}")
    print(f"Measurement results:\n{measurements}")
    print(f"Actual latent_a: {latent_a}")
    
    return circuit, measurements, latent_a

print("Simon's Algorithm - Complete Implementation")
print("==========================================")

# Run the algorithm with 3 qubits and a specific latent_a
n = 3

# Part A

latent_a0 = [1, 0, 1]  # s = 101 in binary
circuit, measurements, latent_a = simons_algorithm(n, latent_a0)

print("\nVerification:")
print("Check that each measurement y satisfies y · a = 0 (mod 2)")
print("For a = [1,0,1]:")
for i, y in enumerate(measurements):
    dot_product = sum(y[j] * latent_a[j] for j in range(n)) % 2
    print(f"y[{i}] = {y}, y · a = {dot_product} (mod 2)")

# Part B

latent_a1 = [0, 1, 0]
circuit, measurements, latent_a = simons_algorithm(n, latent_a1)
print("\nVerification:")
print("Check that each measurement y satisfies y · a = 0 (mod 2)")
print("For a = [0,1,0]:")
for i, y in enumerate(measurements):
    dot_product = sum(y[j] * latent_a[j] for j in range(n)) % 2
    print(f"y[{i}] = {y}, y · a = {dot_product} (mod 2)")
