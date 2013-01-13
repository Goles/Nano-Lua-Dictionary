//
//  nanoluadict.c
//  lua_test
//
//  Created by Nicolas Goles on 8/25/12.
//  Copyright (c) 2012 GandoGames. All rights reserved.
//

#include "nanoluadict.h"

KeyValuePair kvPairWithNumber(char *key, float number)
{
    KeyValuePair kv;
    kv.key = key;
    kv.type = NUMBER;
    kv.value.numericVal = number;
    return kv;
}

KeyValuePair kvPairWithString(char *key, char *string)
{
    KeyValuePair kv;
    kv.key = key;
    kv.type = STRING;
    kv.value.stringVal = string;
    return kv;
}

KeyValuePair kvPairWithCFunction(char *key, void *function)
{
    KeyValuePair kv;
    kv.key = key;
    kv.type = CFUNCTION;
    kv.value.genericVal = function;
    return kv;
}

void luaDict(lua_State *L, char *tableName, int kvCount, ...)
{
    int i;
    lua_newtable(L);
    va_list arguments;
    va_start(arguments, kvCount);

    for (i = 0; i < kvCount; ++i) {
        KeyValuePair kv = va_arg(arguments, KeyValuePair);
        lua_pushstring(L, kv.key);

        switch (kv.type) {
            case NUMBER:
                lua_pushnumber(L, kv.value.numericVal);
                break;
            case STRING:
                lua_pushstring(L, kv.value.stringVal);
                break;
            case CFUNCTION:
                lua_pushcfunction(L, kv.value.genericVal);
                break;
            default:
                break;
        }

        lua_settable(L, -3);
    }

    lua_setglobal(L, tableName);
    va_end(arguments);
}
