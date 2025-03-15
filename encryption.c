#include <stdio.h>
#include <stdlib.h>

void encrypt(FILE* file, FILE* encrypted_file, FILE* key_file) {
    int character;
    while((character = fgetc(file)) != EOF) {
        int key = rand();
        int encrypted_character = character ^ key;

        fputc(key, key_file);
        fputc(encrypted_character, encrypted_file);
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Provide the to-be encrypted file\n");
    } else {
        char* file_name = argv[1];
        FILE* file = fopen(file_name, "r");
        FILE* encrypted_file = fopen("encrypted.out", "w");
        FILE* key_file = fopen("key.out", "w");

        encrypt(file, encrypted_file, key_file);

        fclose(file);
        fclose(encrypted_file);
        fclose(key_file);
    }
}