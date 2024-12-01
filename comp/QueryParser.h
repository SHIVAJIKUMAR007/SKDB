#include <ctype.h>

typedef enum QueryType
{
    QUERY_TYPE_SELECT,
    QUERY_TYPE_INSERT,
    QUERY_TYPE_UPDATE,
    QUERY_TYPE_DELETE,
    QUERY_INVALID
} QueryType;

typedef struct Query
{
    char *query;
    QueryType queryType;
    long queryLength;

} Query;

Query *getNewQuery(InputBuffer *inputBuffer, QueryType queryType)
{
    Query *query = (Query *)malloc(sizeof(Query));
    query->query = inputBuffer->buffer;
    query->queryType = queryType;
    query->queryLength = inputBuffer->inputLength;

    return query;
}
void toLowerCase(char *str)
{
    while (*str) // While the string is not null-terminated
    {
        *str = tolower((unsigned char)*str); // Convert each character to lowercase
        str++;                               // Move to the next character
    }
}

Query *getQuery(InputBuffer *inputBuffer)
{
    char *query = inputBuffer->buffer;
    toLowerCase(query);

    if (strncmp(query, "select ", 7) == 0)
    {
        return getNewQuery(inputBuffer, QUERY_TYPE_SELECT);
    }
    else if (strncmp(query, "insert ", 7) == 0)
    {
        return getNewQuery(inputBuffer, QUERY_TYPE_INSERT);
    }
    else if (strncmp(query, "update ", 7) == 0)
    {
        return getNewQuery(inputBuffer, QUERY_TYPE_UPDATE);
    }
    else if (strncmp(query, "delete ", 7) == 0)
    {
        return getNewQuery(inputBuffer, QUERY_TYPE_DELETE);
    }
    else
    {
        return getNewQuery(inputBuffer, QUERY_INVALID);
    }
}