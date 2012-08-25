#ifndef _NANO_LUADICT_
#define _NANO_LUADICT_

#include <lua.h>

enum EVENT_TYPE
{
   NUMBER,
   STRING,
};

struct kvPair {
    enum EVENT_TYPE type;
    char *key;
    char *text;
    float num;
};

typedef struct kvPair KeyValuePair;

KeyValuePair kvPairWithNumber(char *key, float number);
KeyValuePair kvPairWithString(char *key, char *string);
void luaDict(lua_State *L, char *tableName, int kvCount, ...);

#endif
