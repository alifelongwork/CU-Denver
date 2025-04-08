import cirq
import numpy as np

def apply_qft(qubits, circuit):
    """Applies Quantum Fourier Transform on the given qubits."""
    n = len(qubits)
    for i in range(n):
        circuit.append(cirq.H(qubits[i]))
        for j in range(i + 1, n):
            angle = np.pi / (2 ** (j - i))
            circuit.append(cirq.CZ(qubits[j], qubits[i]) ** (angle / np.pi))
    # Swap to reverse the bit order
    for i in range(n // 2):
        circuit.append(cirq.SWAP(qubits[i], qubits[n - i - 1]))

def normalize_vector(v):
    """Normalizes a vector to have unit norm."""
    norm = np.linalg.norm(v)
    return np.array(v) / norm

def qft_on_vector(data_vector):
    """Performs QFT on the given classical data vector."""
    state_vector = normalize_vector(data_vector)
    qubits = cirq.LineQubit.range(4)
    circuit = cirq.Circuit()

    # Prepare the state using StatePreparationChannel
    circuit.append(cirq.StatePreparationChannel(state_vector)(*qubits))
    apply_qft(qubits, circuit)

    simulator = cirq.Simulator()
    result = simulator.simulate(circuit)
    qft_output = result.final_state_vector

    return qft_output, state_vector

# Input array (length 16)
input_vector = [3.4, 7.8, 1.2, 9.5, 4.1, 6.7, 2.3, 8.9, 5.6, 0.9, 3.7, 6.2, 4.8, 1.5, 7.3, 9.1]

# Run QFT and get normalized input
qft_output, normalized_input = qft_on_vector(input_vector)

# Run FFT on the same normalized input vector
fft_output = np.fft.fft(normalized_input)

# Scale FFT to match QFT (QFT includes normalization factor 1/sqrt(N))
fft_scaled = fft_output / np.sqrt(len(normalized_input))

# Print and compare
print("\n--- Comparison ---")
print(f"{'Index':<6} {'QFT (Cirq)':<30} {'FFT (NumPy, scaled)':<30} {'|Difference|':<15}")
print("-" * 80)
for i in range(len(qft_output)):
    q = qft_output[i]
    f = fft_scaled[i]
    diff = np.abs(q - f)
    print(f"{i:<6} {str(np.round(q, 4)):<30} {str(np.round(f, 4)):<30} {diff:.4e}")
