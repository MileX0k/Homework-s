#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ceasar (char* ms, int key, int encrypt)
{
    if (ms == NULL)
        return NULL;

    const int ln = strlen(ms);
    if (ln == 0)
        return 0;
    char* out = (char*) malloc(sizeof(char) + ln);
    for (int i=0; i < ln; i++)
    {
        out[i] = *(ms + i) + ((encrypt) ? (char) key : (char) -key);
    }
    out[ln] = 0;
    return out;
}

char* shuffle(char* ms, int key, int encrypt)
{
    int l = strlen(ms);
    if (l == 0)
        return NULL;
    const int len = key * (1 +((l - 1) / key));

    char* out = (char*) malloc(sizeof(char) + len);
    if (encrypt == 0)
        key = len / key;
    int idx = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = i; j < len; j += key)
        {
            out[idx++] = (*(ms + j)) ? *(ms + j) : (char) 'x';
        }
    }
    out[len] = 0;
    return out;
}


int main()
{
    char* message = "hellodearteacher";
    printf("message: \t %s\n" , message);
    char* encrypt = ceasar(message, 6, 1);
    printf("encrypt: \t %s\n" , encrypt);
    char* decrypt = ceasar(encrypt, 6, 0);
    printf("decrypt: \t %s\n" , decrypt);


    char* message2 = "hellodearteacher";
    printf("\nmessage2: \t %s\n" , message2);
    char* encrypt2 = shuffle(message2, 6, 1);
    printf("encrypt2: \t %s\n" , encrypt2);
    char* decrypt2 = shuffle(encrypt2, 6, 0);
    printf("decrypt2: \t %s\n" , decrypt2);

    return 0;
}
