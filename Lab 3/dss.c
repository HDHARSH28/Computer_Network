#include <stdio.h>
#include <string.h>

#define KEY "1011011000"

int xorBits(int firstBit, int secondBit) {
    if (firstBit == secondBit) {
        return 0;
    } else {
        return 1;
    }
}

void sender(void) {
    char data[100];
    char spread[1000];
    int ptr = 0;
    int dataLen, keyLen, i, j;

    printf("\nEnter Binary Data: ");
    scanf("%s", data);

    dataLen = (int)strlen(data);
    keyLen = (int)strlen(KEY);

    for (i = 0; i < dataLen; i++) {
        for (j = 0; j < keyLen; j++) {
            int result = xorBits(data[i] - '0', KEY[j] - '0');
            spread[ptr++] = result + '0';
        }
    }

    spread[ptr] = '\0';
    printf("\nTransmitted DSSS Data: %s\n", spread);
}

void receiver(void) {
    char received[1000];
    int dataLen, keyLen, i, j;

    printf("\nEnter Received DSSS Data: ");
    scanf("%999s", received);

    dataLen = (int)strlen(received);
    keyLen = (int)strlen(KEY);

    if (dataLen % keyLen != 0) {
        printf("\nError: Corrupted data (length mismatch).\n");
        return;
    }

    printf("\nOriginal Data: ");
    for (i = 0; i < dataLen; i += keyLen) {
        int sum = 0;
        for (j = 0; j < keyLen; j++) {
            int bit = xorBits(received[i + j] - '0', KEY[j] - '0');
            sum += bit;
        }
        int decodedBit = (sum == keyLen ) ? 1 : 0;
        printf("%d", decodedBit);
    }
    printf("\n");
}

int main(void) {
    int choice;

    printf("===== DSSS Program =====\n");
    printf("1. Sender\n");
    printf("2. Receiver\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sender();
            break;
        case 2:
            receiver();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
