#include "comp/relp.h"
#include "comp/queryparser.h"

void printPrompt()
{
    printf("SKDB>");
}
int main(int argc, char *argv[])
{
    InputBuffer *input_buffer = newInputBuffer();
    while (true)
    {
        printPrompt();
        readInput(input_buffer);

        if (strcmp(input_buffer->buffer, "exit") == 0)
        {
            closeInputBuffer(input_buffer);
            exit(EXIT_SUCCESS);
        }
        else
        {
            Query *query = getQuery(input_buffer);
            switch (query->queryType)
            {
            case QUERY_TYPE_SELECT:
                printf("select query\n");
                break;
            case QUERY_TYPE_INSERT:
                printf("insert query\n");
                break;

            default:
                printf("Invalid query\n");
                break;
            }
        }
    }
}
