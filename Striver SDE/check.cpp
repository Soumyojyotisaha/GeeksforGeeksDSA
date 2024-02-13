#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the determinant of a 2x2 matrix
int determinant(int a, int b, int c, int d) {
    return (a * d - b * c + 26) % 26; // Adding 26 to ensure the result is positive
}

// Function to find the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

// Function to encrypt a message using Hill cipher
string encrypt(string plaintext, string key) {
    int keyMatrix[2][2];
    int plaintextVector[2], ciphertextVector[2];

    // Fill the key matrix
    keyMatrix[0][0] = key[0] - 'A';
    keyMatrix[0][1] = key[1] - 'A';
    keyMatrix[1][0] = key[2] - 'A';
    keyMatrix[1][1] = key[3] - 'A';

    // Encrypt each 2-letter block of the plaintext
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i += 2) {
        // Fill the plaintext vector
        plaintextVector[0] = plaintext[i] - 'A';
        plaintextVector[1] = plaintext[i + 1] - 'A';

        // Perform matrix multiplication
        ciphertextVector[0] = (keyMatrix[0][0] * plaintextVector[0] + keyMatrix[0][1] * plaintextVector[1]) % 26;
        ciphertextVector[1] = (keyMatrix[1][0] * plaintextVector[0] + keyMatrix[1][1] * plaintextVector[1]) % 26;

        // Convert the result to letters and append to the ciphertext
        ciphertext += char(ciphertextVector[0] + 'A');
        ciphertext += char(ciphertextVector[1] + 'A');
    }

    return ciphertext;
}

// Function to decrypt a message using Hill cipher
string decrypt(string ciphertext, string key) {
    int keyMatrix[2][2];
    int invKeyMatrix[2][2];
    int ciphertextVector[2], decryptedVector[2];

    // Fill the key matrix
    keyMatrix[0][0] = key[0] - 'A';
    keyMatrix[0][1] = key[1] - 'A';
    keyMatrix[1][0] = key[2] - 'A';
    keyMatrix[1][1] = key[3] - 'A';

    // Calculate the determinant of the key matrix
    int det = determinant(keyMatrix[0][0], keyMatrix[0][1], keyMatrix[1][0], keyMatrix[1][1]);

    // Calculate the modular inverse of the determinant
    int detInverse = modInverse(det, 26);

    // Calculate the adjugate matrix
    invKeyMatrix[0][0] = keyMatrix[1][1];
    invKeyMatrix[0][1] = -keyMatrix[0][1];
    invKeyMatrix[1][0] = -keyMatrix[1][0];
    invKeyMatrix[1][1] = keyMatrix[0][0];

    // Apply modular arithmetic to the elements of the adjugate matrix
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            invKeyMatrix[i][j] = (invKeyMatrix[i][j] + 26) % 26;

    // Multiply the modular inverse of the determinant by the adjugate matrix
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            invKeyMatrix[i][j] = (detInverse * invKeyMatrix[i][j]) % 26;

    // Decrypt each 2-letter block of the ciphertext
    string decryptedText = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        // Fill the ciphertext vector
        ciphertextVector[0] = ciphertext[i] - 'A';
        ciphertextVector[1] = ciphertext[i + 1] - 'A';

        // Perform matrix multiplication
        decryptedVector[0] = (invKeyMatrix[0][0] * ciphertextVector[0] + invKeyMatrix[0][1] * ciphertextVector[1]) % 26;
        decryptedVector[1] = (invKeyMatrix[1][0] * ciphertextVector[0] + invKeyMatrix[1][1] * ciphertextVector[1]) % 26;

        // Convert the result to letters and append to the decrypted text
        decryptedText += char(decryptedVector[0] + 'A');
        decryptedText += char(decryptedVector[1] + 'A');
    }

    return decryptedText;
}

int main() {
    // Input plaintext and key
    string plaintext = "WELCOMETOVIT";
    string key = "NICE";

    // Encrypt the plaintext using Hill cipher
    string ciphertext = encrypt(plaintext, key);
    cout << "Cipher text: " << ciphertext << endl;

    // Decrypt the ciphertext using Hill cipher
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
