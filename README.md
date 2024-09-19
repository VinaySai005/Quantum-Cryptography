# Quantum-Cryptography
The Quantum Cryptography Simulator project aims to develop a comprehensive simulation  platform for quantum cryptography, providing a detailed understanding of its principles and  applications. 


Code Description


Random Basis Generation:
generateRandomBasis(int size): Creates a random basis string where each character is either 'r' (Rectilinear) or 'd' (Diagonal).
generateRandomMessage(int size): Generates a random bit string of length size consisting of '0's and '1's.
generateRandomBit(): Returns a random bit ('0' or '1').
Binary and Basis Validation:

isBinary(const char *str): Checks if a string contains only '0's and '1's.
isBasis(const char *str): Checks if a string contains only 'r's and 'd's.
Encryption and Decryption:

encrypt(char *message, char *enc_basis): Encrypts a message based on the provided encryption basis, converting '0's and '1's into 'H', 'R', 'V', and 'L' based on the basis.
decrypt(char *enc_str, char *dec_basis): Decrypts an encrypted string using a decryption basis, converting 'H', 'R', 'V', and 'L' back into '0's and '1's, with potential noise introduced.
Interception by Eve:

intercept(char *enc_str): Simulates Eve intercepting the encrypted message, generating a random decryption basis, decrypting the message, and then re-encrypting it before forwarding it to Bob.
Main Functionality:

User inputs the length of the message.
Alice generates a random bit string and basis, encodes the message, and optionally, Eve intercepts and manipulates it.
Bob measures the bits using his basis and compares the results with Alice's bases to establish a shared key.



# Quantum Cryptography Simulator

The Quantum Cryptography Simulator is a C program that emulates the Quantum Key Distribution (QKD) BB84 protocol. It demonstrates the principles of quantum cryptography, allowing users to explore secure communication through quantum channels. The simulator handles the generation of random basis strings, encryption, decryption, and potential interception by Eve.

## Features

- **Random Basis Generation**: Generate random rectilinear or diagonal bases.
- **Encryption and Decryption**: Encrypt and decrypt messages using quantum principles.
- **Interception Simulation**: Simulate Eve's interception and manipulation of the encrypted message.
- **User Interaction**: Input message length and choose whether to include Eve's interception.

## Code Overview

- **`generateRandomBasis(int size)`**: Generates a random basis string of length `size`.
- **`generateRandomMessage(int size)`**: Creates a random bit string of length `size`.
- **`generateRandomBit()`**: Returns a random bit ('0' or '1').
- **`isBinary(const char *str)`**: Checks if a string is binary.
- **`isBasis(const char *str)`**: Checks if a string is a valid basis.
- **`encrypt(char *message, char *enc_basis)`**: Encrypts the message based on the encryption basis.
- **`decrypt(char *enc_str, char *dec_basis)`**: Decrypts the encrypted string using the decryption basis.
- **`intercept(char *enc_str)`**: Simulates interception by Eve, including decryption and re-encryption of the message.


## Example

Enter the length of the message: 5

Alice's randomly generated bits: 10101
Alice's randomly generated basis: drdrr
Alice's encoded message: VLRVV

Would you like the simulation to have Eve intercept the string Alice sends Bob? [y/n]: y
Eve's randomly generated decryption basis: dddrd
Eve has decrypted Alice's encrypted string to: 11011
Eve will now encrypt the (decrypted) string back with the encryption basis to generate: HLHHL

Bob's measured bits: 11011

Public announcement of bases:
Alice: drdrr
Bob: dddrd

Shared key bits: 11011



