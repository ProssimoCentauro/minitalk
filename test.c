#include <stdio.h>

// Funzione che stampa i bit di un carattere
void print_bits(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

// Funzione per stampare un carattere Unicode in UTF-8
void send_unicode_as_bits(const char *unicode_char) {
    while (*unicode_char) {
        unsigned char byte = (unsigned char)*unicode_char;
        print_bits(byte);  // Stampa i bit di ogni byte
        printf(" ");
        unicode_char++;
    }
    printf("\n");
}

int main() {
    // Carattere Unicode '世' (U+4E16) in UTF-8
    const char *unicode_char = "世";

    // Stampa i bit della rappresentazione UTF-8
    printf("Rappresentazione binaria del carattere '世' in UTF-8: ");
    send_unicode_as_bits(unicode_char);

    // Mostra il carattere originale
    printf("Il carattere originale è: %s\n |世|", unicode_char);

    return 0;
}

