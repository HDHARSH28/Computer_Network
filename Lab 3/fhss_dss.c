    #include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DSS_KEY "1011011000"

static int xorBits(int firstBit, int secondBit) {
    return firstBit ^ secondBit;
}

void dssSender(void) {
    char data[100];
    char spread[1000];
    int ptr = 0;
    int dataLen, keyLen, i, j;

    printf("\nEnter Binary Data for DSSS: ");
    scanf("%99s", data);

    dataLen = (int)strlen(data);
    keyLen = (int)strlen(DSS_KEY);

    for (i = 0; i < dataLen; i++) {
        for (j = 0; j < keyLen; j++) {
            spread[ptr++] = xorBits(data[i] - '0', DSS_KEY[j] - '0') + '0';
        }
    }
    spread[ptr] = '\0';

    printf("\nTransmitted DSSS Data: %s\n", spread);
}

void dssReceiver(void) {
    char received[1000];
    int dataLen, keyLen, i;

    printf("\nEnter Received DSSS Data: ");
    scanf("%999s", received);

    dataLen = (int)strlen(received);
    keyLen = (int)strlen(DSS_KEY);

    if (dataLen % keyLen != 0) {
        printf("\nError: Corrupted data (length mismatch).\n");
        return;
    }

    printf("\nOriginal Data: ");
    for (i = 0; i < dataLen; i += keyLen) {
        char origBit = xorBits(received[i] - '0', DSS_KEY[0] - '0') + '0';
        printf("%c", origBit);
    }
    printf("\n");
}

void fhssSender(void) {
    char data[100];
    int hopSeq[] = {0, 2, 1, 3, 2, 0, 3, 1};
    int hopCount = (int)(sizeof(hopSeq) / sizeof(hopSeq[0]));
    int len, i;

    printf("\nEnter Binary Data for FHSS: ");
    scanf("%99s", data);

    len = (int)strlen(data);
    printf("\nTransmitted FHSS Channels: ");
    for (i = 0; i < len; i++) {
        int bit = data[i] - '0';
        int hop = hopSeq[i % hopCount];
        int channel = (hop + bit) % 4;
        printf("%d", channel);
        if (i + 1 < len) {
            printf(" ");
        }
    }
    printf("\n");
}

void fhssReceiver(void) {
    char line[1000];
    int hopSeq[] = {0, 2, 1, 3, 2, 0, 3, 1};
    int hopCount = (int)(sizeof(hopSeq) / sizeof(hopSeq[0]));
    int channels[100];
    int count = 0;
    char *token;

    printf("\nEnter FHSS Channels (space separated): ");
    fgets(line, sizeof(line), stdin);
    fgets(line, sizeof(line), stdin);

    token = strtok(line, " \n");
    while (token != NULL && count < 100) {
        channels[count++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    printf("\nDecoded Data: ");
    for (int i = 0; i < count; i++) {
        int hop = hopSeq[i % hopCount];
        int bit = (channels[i] - hop + 4) % 4;
        printf("%d", bit);
    }
    printf("\n");
}

int main(void) {
    int choice;

    printf("===== FHSS and DSSS Demonstration =====\n");
    printf("1. DSSS Sender\n");
    printf("2. DSSS Receiver\n");
    printf("3. FHSS Sender\n");
    printf("4. FHSS Receiver\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            dssSender();
            break;
        case 2:
            dssReceiver();
            break;
        case 3:
            fhssSender();
            break;
        case 4:
            fhssReceiver();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
