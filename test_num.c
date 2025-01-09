#include <stdio.h>
/*
int main() {
    unsigned int numero = 0;  // L'intero da costruire
    int bit, posizione = 0;   // Variabili per il bit e la posizione

    printf("Costruisci un intero inserendo i bit uno alla volta (da meno significativo a più significativo).\n");
    printf("Inserisci -1 per terminare.\n");

    while (1) {
        printf("Inserisci il bit in posizione %d (0 o 1): ", posizione);
        if (scanf("%d", &bit) != 1 || (bit != 0 && bit != 1 && bit != -1)) {
            printf("Input non valido! Riprova.\n");
            while (getchar() != '\n');  // Pulisci il buffer
            continue;
        }

        if (bit == -1) break; // Termina il ciclo

        // Aggiungi il bit alla posizione corretta nell'intero
        numero |= (bit << posizione);

        // Passa alla posizione successiva
        posizione++;

        printf("Numero corrente: %u\n", numero);
        printf("carattere corrente: %c\n", numero);
    }

    printf("\nNumero finale costruito: %u\n", numero);
    return 0;
}
*/

#include <unistd.h>

void    test_num(char c)
{
    unsigned int i;
    unsigned int bit;
    unsigned char res;

    i = 0;
    res = 0;
    while (i++ < 8)
    {
        bit = c & (0b10000000 >> i);
        if (bit != 0)
            //res |= (0b10000000 >> (8 - i));
            //res |= (1 << (7 - i));
            res |= (0b10000000 >> i);
        else
            //res &= ~(1 << (7 - i));
            //res &= (0b11111111 ^ (0b10000000 >> (8 - i)));
            res &= (0b11111111 ^ (0b10000000 >> i));
    }
    //printf("%c\n", res);
    if (res != '\0')
    {
        write(1, "|", 1);
        write(1, &res, 1);
        write(1, "|", 1);
    }
}

int main(int ac, char **av)
{
    while (*av[1])
        test_num(*av[1]++);
    return (0);
}
