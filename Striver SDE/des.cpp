#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>

std::string hex2bin(std::string s) {
    std::unordered_map<char, std::string> mp = {
        {'0', "0000"},
        {'1', "0001"},
        {'2', "0010"},
        {'3', "0011"},
        {'4', "0100"},
        {'5', "0101"},
        {'6', "0110"},
        {'7', "0111"},
        {'8', "1000"},
        {'9', "1001"},
        {'A', "1010"},
        {'B', "1011"},
        {'C', "1100"},
        {'D', "1101"},
        {'E', "1110"},
        {'F', "1111"}
    };
    std::string bin = "";
    for (int i = 0; i < s.length(); i++) {
        bin += mp[s[i]];
    }
    return bin;
}

std::string bin2hex(std::string s) {
    std::unordered_map<std::string, char> mp = {
        {"0000", '0'},
        {"0001", '1'},
        {"0010", '2'},
        {"0011", '3'},
        {"0100", '4'},
        {"0101", '5'},
        {"0110", '6'},
        {"0111", '7'},
        {"1000", '8'},
        {"1001", '9'},
        {"1010", 'A'},
        {"1011", 'B'},
        {"1100", 'C'},
        {"1101", 'D'},
        {"1110", 'E'},
        {"1111", 'F'}
    };
    std::string hex = "";
    for (int i = 0; i < s.length(); i += 4) {
        std::string ch = "";
        ch += s[i];
        ch += s[i + 1];
        ch += s[i + 2];
        ch += s[i + 3];
        hex += mp[ch];
    }
    return hex;
}

int bin2dec(int binary) {
    int binary1 = binary;
    int decimal = 0, i = 0, n = 0;
    while (binary != 0) {
        int dec = binary % 10;
        decimal += dec * pow(2, i);
        binary /= 10;
        i++;
    }
    return decimal;
}

std::string dec2bin(int num) {
    std::string res = std::bitset<64>(num).to_string();
    if (res.length() % 4 != 0) {
        int div = res.length() / 4;
        div = int(div);
        int counter = (4 * (div + 1)) - res.length();
        for (int i = 0; i < counter; i++) {
            res = '0' + res;
        }
    }
    return res;
}

std::string permute(std::string k, int arr[], int n) {
    std::string permutation = "";
    for (int i = 0; i < n; i++) {
        permutation += k[arr[i] - 1];
    }
    return permutation;
}

std::string shift_left(std::string k, int nth_shifts) {
    std::string s = "";
    for (int i = 0; i < nth_shifts; i++) {
        for (int j = 1; j < k.length(); j++) {
            s += k[j];
        }
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}

std::string xor(std::string a, std::string b) {
    std::string ans = "";
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) {
            ans += "0";
        } else {
            ans += "1";
        }
    }
    return ans;
}

std::string encrypt(std::string pt, std::vector<std::string> rkb, std::vector<std::string> rk) {
    pt = hex2bin(pt);
    
    pt = permute(pt, initial_perm, 64);
    std::cout << "After initial permutation " << bin2hex(pt) << std::endl;
    
    std::string left = pt.substr(0, 32);
    std::string right = pt.substr(32, 64);
    for (int i = 0; i < 16; i++) {
        std::string right_expanded = permute(right, exp_d, 48);
        
        std::string xor_x = xor(right_expanded, rkb[i]);
        
        std::string sbox_str = "";
        for (int j = 0; j < 8; j++) {
            int row = bin2dec(std::stoi(xor_x.substr(j * 6, 1) + xor_x.substr(j * 6 + 5, 1)));
            int col = bin2dec(std::stoi(xor_x.substr(j * 6 + 1, 1) + xor_x.substr(j * 6 + 2, 1) + xor_x.substr(j * 6 + 3, 1) + xor_x.substr(j * 6 + 4, 1)));
            int val = sbox[j][row][col];
            sbox_str += dec2bin(val);
        }
        
        sbox_str = permute(sbox_str, per, 32);
        
        std::string result = xor(left, sbox_str);
        left = result;
        
        if (i != 15) {
            std::swap(left, right);
        }
        std::cout << "Round " << i + 1 << " " << bin2hex(left) << " " << bin2hex(right) << " " << rk[i] << std::endl;
    }
    
    std::string combine = left + right;
    
    std::string cipher_text = permute(combine, final_perm, 64);
    return cipher_text;
}

int main() {
    std::string pt = "123456ABCD132536";
    std::string key = "AABB09182736CCDD";
    
    key = hex2bin(key);
    
    int keyp[56] = {57, 49, 41, 33, 25, 17, 9,
                    1, 58, 50, 42, 34, 26, 18,
                    10, 2, 59, 51, 43, 35, 27,
                    19, 11, 3, 60, 52, 44, 36,
                    63, 55, 47, 39, 31, 23, 15,
                    7, 62, 54, 46, 38, 30, 22,
                    14, 6, 61, 53, 45, 37, 29,
                    21, 13, 5, 28, 20, 12, 4};
    
    key = permute(key, keyp, 56);
    
    int shift_table[16] = {1, 1, 2, 2,
                           2, 2, 2, 2,
                           1, 2, 2, 2,
                           2, 2, 2, 1};
    
    int key_comp[48] = {14, 17, 11, 24, 1, 5,
                        3, 28, 15, 6, 21, 10,
                        23, 19, 12, 4, 26, 8,
                        16, 7, 27, 20, 13, 2,
                        41, 52, 31, 37, 47, 55,
                        30, 40, 51, 45, 33, 48,
                        44, 49, 39, 56, 34, 53,
                        46, 42, 50, 36, 29, 32};
    
    std::string left = key.substr(0, 28);
    std::string right = key.substr(28, 56);
    std::vector<std::string> rkb;
    std::vector<std::string> rk;
    for (int i = 0; i < 16; i++) {
        left = shift_left(left, shift_table[i]);
        right = shift_left(right, shift_table[i]);
        
        std::string combine_str = left + right;
        
        std::string round_key = permute(combine_str, key_comp, 48);
        rkb.push_back(round_key);
        rk.push_back(bin2hex(round_key));
    }
    
    std::cout << "Encryption" << std::endl;
    std::string cipher_text = bin2hex(encrypt(pt, rkb, rk));
    std::cout << "Cipher Text: " << cipher_text << std::endl;
    
    std::cout << "Decryption" << std::endl;
    std::reverse(rkb.begin(), rkb.end());
    std::reverse(rk.begin(), rk.end());
    std::string text = bin2hex(encrypt(cipher_text, rkb, rk));
    std::cout << "Plain Text: " << text << std::endl;
    
    return 0;
}


