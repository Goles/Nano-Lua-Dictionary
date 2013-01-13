#ifndef _NANO_LUADICT_
#define _NANO_LUADICT_

#include <lua.h>

typedef union {
    void *genericVal;
    char *stringVal;
    float numericVal;
} Value;

enum EVENT_TYPE {
   NUMBER,
   STRING,
   CFUNCTION,
};

struct kvPair {
    enum EVENT_TYPE type;
    char *key;
    Value value;
};

typedef struct kvPair KeyValuePair;

KeyValuePair kvPairWithNumber(char *key, float number);
KeyValuePair kvPairWithString(char *key, char *string);
KeyValuePair kvPairWithCFunction(char *key, void *function);

void luaDict(lua_State *L, char *tableName, int kvCount, ...);

#endif
