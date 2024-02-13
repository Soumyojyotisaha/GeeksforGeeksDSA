#include <iostream>

class VigenereCipher 
{
public:
    // This function generates the key in
    // a cyclic manner until its length isn't
    // equal to the length of the original text
    static std::string generateKey(const std::string& str, const std::string& key)
    {
        int x = str.length();
        std::string generatedKey = key;
 
        for (int i = key.length(); i < x; )
        {
            generatedKey += key[i % key.length()];
            i++;
        }
        return generatedKey;
    }
 
    // This function returns the encrypted text
    // generated with the help of the key
    static std::string encrypt(const std::string& plaintext, const std::string& key)
    {
        std::string ciphertext = "";
 
        for (size_t i = 0, j = 0; i < plaintext.length(); i++)
        {
            // Skip spaces in plaintext
            if (plaintext[i] == ' ')
            {
                continue;
            }

            // converting in range 0-25
            int x = (plaintext[i] + key[j]) % 26;
 
            // convert into alphabets(ASCII)
            x += 'A';
 
            ciphertext += static_cast<char>(x);
            j = (j + 1) % key.length();
        }
        return ciphertext;
    }
 
    // This function decrypts the encrypted text
    // and returns the original text
    static std::string decrypt(const std::string& ciphertext, const std::string& key)
    {
        std::string originalText = "";
 
        for (size_t i = 0, j = 0; i < ciphertext.length(); i++)
        {
            // Skip spaces in ciphertext
            if (ciphertext[i] == ' ')
            {
                continue;
            }

            // converting in range 0-25
            int x = (ciphertext[i] - key[j] + 26) % 26;
 
            // convert into alphabets(ASCII)
            x += 'A';
            originalText += static_cast<char>(x);
            j = (j + 1) % key.length();
        }
        return originalText;
    }

    // This function will convert the lower case character to Upper case
    static std::string lowerToUpper(const std::string& s)
    {
        std::string str = s;
        for(size_t i = 0; i < s.length(); i++)
        {
            if(islower(s[i]))
            {
                str[i] = toupper(s[i]);
            }
        }
        return str;
    }
};

int main() 
{
    std::string plaintext = "VELLORE INSTITUTE OF TECHNOLOGY";
    std::string key = "SCOPE";
       
    std::string processedPlaintext = VigenereCipher::lowerToUpper(plaintext);
    std::string processedKey = VigenereCipher::lowerToUpper(key);
 
    std::string generatedKey = VigenereCipher::generateKey(processedPlaintext, processedKey);
    std::string ciphertext = VigenereCipher::encrypt(processedPlaintext, generatedKey);
 
    std::cout << "Plaintext: " << processedPlaintext << "\n";
    std::cout << "Key: " << processedKey << "\n";
    std::cout << "Ciphertext: " << ciphertext << "\n";
 
    std::string decryptedText = VigenereCipher::decrypt(ciphertext, generatedKey);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
