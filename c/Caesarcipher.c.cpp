
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

#define N 1000

//1917494027 Xu Jiahe

void encrypt();
void decrypt();
void decryptAll();


int main() {  //The main() function is responsible for generating a selection menu for users to choose from
    int s;
    while (1) {    //Beautiful menu 
        printf("                             --------------------**Mode selection**--------------------\n");
        printf("                             *                     1£ºEncryption                      *\n");
        printf("                             *                     2£ºDecryption                      *\n");
        printf("                             *            3£ºDecryption without a known key           *\n");
        printf("                             *                        4: Exit                         *\n");
        printf("                             ------------------------**********------------------------\n");
        printf("Please select£º");
        scanf("%d", &s);
        if (s == 1)
            encrypt();     
        else if (s == 2)
            decrypt();      
        else if (s == 3)
            decryptAll();       
        else if (s == 4)       
            return 0;
    }
}

int key() {  //Get the correct key format
    char k[N];     
    printf("Input a key(1~26)£º");
    gets(k);   
    while (1) {
        if (atoi(k) > 0 && atoi(k) <= 26)      
            break;
        printf("Format error, please re-enter(1~26)£º");
        gets(k);
    }
    return atoi(k);
}

void change(char plaintext[], char ciphertext[], int k) {  //Used for letter conversion during decryption
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (islower(ciphertext[i]))
            plaintext[i] =
                    ((ciphertext[i] - 'a' - k) > 0 ? (ciphertext[i] - 'a' - k) : ((ciphertext[i] - 'a' - k) + 26)) % 26 + 'A';
        else if (isupper(ciphertext[i]))
            plaintext[i] =

                    ((ciphertext[i] - 'A' - k) > 0 ? (ciphertext[i] - 'A' - k) : ((ciphertext[i] - 'A' - k) + 26)) % 26 + 'A';
        else
            plaintext[i] = ciphertext[i];  //If other characters are encountered, they will not be converted
    }
}

void encrypt() {  //Encryption function
    char plaintext[N] = {}, ciphertext[N] = {};
    int k;
    getchar();  //Clear the carriage returns left in the cache
    printf("Input plaintext£º");
    gets(plaintext);
    k = key();
    for (int i = 0; i < strlen(plaintext); i++) {
        if (islower(plaintext[i]))    
            ciphertext[i] = (plaintext[i] - 'a' + k) % 26 + 'A';
        else if (isupper(plaintext[i]))     
            ciphertext[i] = (plaintext[i] - 'A' + k) % 26 + 'A';
        else
            ciphertext[i] = plaintext[i];      
    }
    printf("The ciphertext is£º");
    puts(ciphertext);
}

void decrypt() { //Decryption function
    char plaintext[N] = {}, ciphertext[N] = {};
    int k;
    getchar();
    printf("Input ciphertext£º");
    gets(ciphertext);
    k = key();     
    change(plaintext, ciphertext, k);  //Call the change() function to process the conversion of ciphertext into plaintext
    printf("The plaintext is£º");
    puts(plaintext);
}

void decryptAll() {  //Decryption without a known key
    char plaintext[N] = {}, ciphertext[N] = {};
    getchar();
    printf("Input ciphertext£º");
    gets(ciphertext);
    for (int k = 1; k <= 26; ++k) {     //Enumerate the plaintext corresponding to each key
        change(plaintext, ciphertext, k);   
        printf("When key = %d£¬The plaintext is£º", k);
        puts(plaintext);
    }
}

