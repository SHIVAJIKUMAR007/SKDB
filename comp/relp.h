#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct InputBuffer
{
    char *buffer;
    size_t bufferLength;
    long inputLength;

} InputBuffer;

InputBuffer *newInputBuffer()
{
    InputBuffer *inputBuffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    inputBuffer->buffer = NULL;
    inputBuffer->bufferLength = 0;
    inputBuffer->inputLength = 0;

    return inputBuffer;
}

void readInput(InputBuffer *inputBuffer)
{
    size_t byteRead = getline(&inputBuffer->buffer, &inputBuffer->bufferLength, stdin);

    if (byteRead <= 0)
    {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    // Remove newline character
    inputBuffer->inputLength = byteRead - 1;
    inputBuffer->buffer[inputBuffer->inputLength] = 0;
}
void closeInputBuffer(InputBuffer *inputBuffer)
{
    free(inputBuffer->buffer);
    free(inputBuffer);
}
