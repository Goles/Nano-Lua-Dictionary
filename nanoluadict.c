//
//  nanoluadict.c
//  lua_test
//
//  Created by Nicolas Goles on 8/25/12.
//  Copyright (c) 2012 GandoGames. All rights reserved.
//

#include "nanoluadict.h"

KeyValuePair kvPairWithNumber(char *key, float number) {
    KeyValuePair kv;
    kv.key = key;
    kv.type = NUMBER;
    kv.num = number;
    return kv;
}

KeyValuePair kvPairWithString(char *key, char *string) {
    KeyValuePair kv;
    kv.key = key;
    kv.type = STRING;
    kv.text = string;
    return kv;
}

void luaDict(lua_State *L, char *tableName, int kvCount, ...)
{
    lua_newtable(L);
    va_list arguments;
    va_start(arguments, kvCount);

    for (int i = 0; i < kvCount; ++i) {
        KeyValuePair kv = va_arg(arguments, KeyValuePair);
        lua_pushstring(L, kv.key);

        switch (kv.type) {
            case NUMBER:
                lua_pushnumber(L, kv.num);
                break;
            case STRING:
                lua_pushstring(L, kv.text);
                break;
            default:
                break;
        }

        lua_settable(L, -3);
    }

    lua_setglobal(L, tableName);
    va_end(arguments);
}
