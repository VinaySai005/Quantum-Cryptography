#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Helper function to generate a random basis (Rectilinear or Diagonal)
char *generateRandomBasis(int size) {
    int randNum;
    char *randStr = malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        randNum = rand() % 2;
        if (randNum == 0) {
            randStr[i] = 'r';  // r => Rectilinear
        } else {
            randStr[i] = 'd';  // d => Diagonal
        }
    }
    randStr[size] = '\0';
    return randStr;
}

// Helper function to generate a random string
char *generateRandomMessage(int size) {
    int randNum;
    char *randStr = malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        randNum = rand() % 2;
        randStr[i] = (randNum == 0) ? '0' : '1';
    }
    randStr[size] = '\0';
    return randStr;
}

// Helper function to generate a random bit of 1 or 0
char generateRandomBit() {
    return (rand() % 2 == 0) ? '0' : '1';
}

// Helper function to encrypt the message with the encryption basis
char *encrypt(char *message, char *enc_basis) {
    int length = strlen(message);
    char *enc_str = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (message[i] == '0') {
            enc_str[i] = (enc_basis[i] == 'r') ? 'H' : 'R';
        } else {
            enc_str[i] = (enc_basis[i] == 'r') ? 'V' : 'L';
        }
    }
    enc_str[length] = '\0';
    return enc_str;
}

// Helper function to decrypt the encrypted string with the decryption basis
char *decrypt(char *enc_str, char *dec_basis) {
    int length = strlen(enc_str);
    char *dec_str = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        char temp = generateRandomBit();
        if (enc_str[i] == 'V') {
            dec_str[i] = (dec_basis[i] == 'r') ? '1' : temp;
        } else if (enc_str[i] == 'H') {
            dec_str[i] = (dec_basis[i] == 'r') ? '0' : temp;
        } else if (enc_str[i] == 'R') {
            dec_str[i] = (dec_basis[i] == 'd') ? '0' : temp;
        } else if (enc_str[i] == 'L') {
            dec_str[i] = (dec_basis[i] == 'd') ? '1' : temp;
        }
    }
    dec_str[length] = '\0';
    return dec_str;
}

// Helper function to simulate Eve intercepting the message
char *intercept(char *enc_str) {
    int length = strlen(enc_str);
    char *dec_basis = generateRandomBasis(length);
    printf("Eve's randomly generated decryption basis: %s\n", dec_basis);
    char *dec_str = decrypt(enc_str, dec_basis);
    printf("Eve has decrypted Alice's encrypted string to: %s\n", dec_str);
    char *intercepted_str = encrypt(dec_str, dec_basis);
    printf("Eve will re-encrypt and forward: %s\n", intercepted_str);
    return intercepted_str;
}

int main() {
    srand(time(NULL));

    // Input message length
    int messageLength;
    printf("Enter the length of the message: ");
    scanf("%d", &messageLength);

    // Alice generates random bits and basis
    char *aliceBits = generateRandomMessage(messageLength);
    char *aliceBases = generateRandomBasis(messageLength);
    printf("Alice's bits: %s\n", aliceBits);
    printf("Alice's basis: %s\n", aliceBases);

    // Bob generates random basis
    char *bobBases = generateRandomBasis(messageLength);
    printf("Bob's basis: %s\n", bobBases);

    // Alice encrypts her message
    char *aliceEncoded = encrypt(aliceBits, aliceBases);
    printf("Alice's encoded message: %s\n", aliceEncoded);

    // Eve intercepts if chosen
    char eveInput;
    printf("Should Eve intercept? [y/n]: ");
    scanf(" %c", &eveInput);
    if (eveInput == 'y' || eveInput == 'Y') {
        aliceEncoded = intercept(aliceEncoded);
    }

    // Bob decrypts the message
    char *bobMeasuredBits = decrypt(aliceEncoded, bobBases);
    printf("Bob's measured bits: %s\n", bobMeasuredBits);

    // Shared key generation
    printf("Shared key bits: ");
    for (int i = 0; i < messageLength; i++) {
        if (bobBases[i] == aliceBases[i]) {
            printf("%c ", bobMeasuredBits[i]);
        }
    }
    printf("\n");

    // Cleanup
    free(aliceBits);
    free(aliceBases);
    free(bobBases);
    free(aliceEncoded);
    free(bobMeasuredBits);

    return 0;
}
