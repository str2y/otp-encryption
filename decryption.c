#include <stdio.h>
#include <stdlib.h>

void decrypt(FILE* encrypted_file, FILE* key_file, FILE* decrypted_file) {
    int encrypted_character;
    
    while((encrypted_character = fgetc(encrypted_file)) != EOF) {
        int key_character = fgetc(key_file);
        int decrypted_character = encrypted_character ^ key_character;
        
        fputc(decrypted_character, decrypted_file);
    }
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("You have to provide the encrypted file and the key as arguments\n");
    } else {
        FILE* encrypted_file = fopen(argv[1], "r");
        FILE* key_file = fopen(argv[2], "r");
        FILE* decrypted_file = fopen("decrypted.out", "w");
        
        decrypt(encrypted_file, key_file, decrypted_file);

        fclose(encrypted_file);
        fclose(key_file);
        fclose(decrypted_file);
    }
}