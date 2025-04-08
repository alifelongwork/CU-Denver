import cirq
import numpy as np

def apply_oracle(circuit, qubits, mu, n):
    """Applies the oracle for f(x) = x · mu mod 2"""
    for i in range(n):
        if mu[i] == 1:
            circuit.append(cirq.CNOT(qubits[i], qubits[n]))  # CNOT from input i to output qubit if s[i] = 1

def bernstein_vazirani(n=4, mu_input=None):
    """
    Implements the Bernstein-Vazirani algorithm to find the hidden string mu
    n: number of input qubits
    mu_input: hidden string mu (if None, randomly generated)
    """
    if mu_input is None:
        mu_input = np.random.randint(0, 2, n)
    mu = mu_input
    
    # Create n input qubits and 1 output qubit
    qubits = [cirq.LineQubit(i) for i in range(n + 1)]
    circuit = cirq.Circuit()

    # Step 1: Prepare the output qubit in |-> state (MISSING LINES)
    # |-> = (1 / sqrt(2)) * (|0> - |1>) = H(|1>)
    circuit.append(cirq.X(qubits[len(qubits)-1]))
    circuit.append(cirq.H(qubits[len(qubits)-1]))

    # Step 2: Apply Hadamard gates to input qubits (input qubits are every qubit except the last)
    for i in range(len(qubits)-1):
        circuit.append(cirq.H(qubits[i]))

    # Step 3: Apply the oracle
    apply_oracle(circuit, qubits, mu, n)
    
    # Step 4: Apply Hadamard gates to input qubits again
    for i in range(len(qubits)-1):
        circuit.append(cirq.H(qubits[i]))

    # Step 5: Measure the input qubits
    circuit.append(cirq.measure(qubits[:len(qubits)-1], key='result'))

    simulator = cirq.Simulator()
    results = simulator.run(circuit)
    measurements = results.measurements['result']
    
    return circuit, measurements, mu


print("Bernstein-Vazirani Algorithm Homework - Complete the Implementation")
print("==============================================================")

n = 4
mu = [1, 0, 1, 1]  # mu = 1011 in binary
circuit, measurements, mu = bernstein_vazirani(n, mu)
    
print(f"Circuit:\n{circuit}")
print(f"Measurement result: {measurements}")
print(f"Actual mu: {mu}")
