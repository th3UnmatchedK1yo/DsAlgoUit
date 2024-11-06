#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void computeLPS(const string& pattern, int lps[]) {
    int m = pattern.length();
    lps[0] = 0;  
    int len = 0; 

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    int* lps = new int[m];
    computeLPS(pattern, lps);

    int i = 0; 
    int j = 0; 
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) { 
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1]; 
        } else if (i < n && pattern[j] != text[i]) { 
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }
    }

    delete[] lps; 
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
