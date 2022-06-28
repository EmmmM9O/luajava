#ifndef LUACOMP_H
#define LUACOMP_H

#include "lua.hpp"

#include <cstring>

/**
 * Opens individual libraries when one does not want them all
 */
static inline void luaJ_openlib_call(lua_State * L, const char *libName, lua_CFunction loader) {
    luaL_requiref(L, libName, loader, 1);
}

luaL_Reg allAvailableLibs[] = {
    { "_G",        luaopen_base },
    { "package",   luaopen_package },
    { "coroutine", luaopen_coroutine },
    { "string",    luaopen_string },
    { "table",     luaopen_table },
    { "utf8",      luaopen_utf8 },
    { "math",      luaopen_math },
    { "io",        luaopen_io },
    { "os",        luaopen_os },
    { "debug",     luaopen_debug },
    { NULL,        NULL },
};

static void luaJ_openlib(lua_State * L, const char * libName) {
    const luaL_Reg *lib = allAvailableLibs;
    for (; lib->func != NULL; lib++) {
        if (std::strcmp(lib->name, libName) == 0) {
            luaJ_openlib_call(L, lib->name, lib->func);
            return;
        }
    }
}

static int luaJ_compare(lua_State * L, int index1, int index2, int op) {
    if (op < 0) {
        return lua_compare(L, index1, index2, LUA_OPLT);
    } else if (op == 0) {
        return lua_compare(L, index1, index2, LUA_OPEQ);
    } else {
        return lua_compare(L, index1, index2, LUA_OPLE);
    }
}

static int luaJ_len(lua_State * L, int index) {
    lua_len(L, index);
    int length = lua_tointeger(L, -1);
    lua_pop(L, 1);
    return length;
}

static int luaJ_loadbuffer(lua_State * L, unsigned char * buffer, int size, const char * name) {
    return luaL_loadbuffer(L, (const char *) buffer, size, name);
}

static int luaJ_dobuffer(lua_State * L, unsigned char * buffer, int size, const char * name) {
    return (luaL_loadbuffer(L, (const char *) buffer, size, name) || lua_pcall(L, 0, LUA_MULTRET, 0));
}

static int luaJ_pcall(lua_State * L, int nargs, int nresults) {
    return lua_pcall(L, nargs, nresults, 0);
}

static int luaJ_resume(lua_State * L, int narg) {
    int nresults;
    return lua_resume(L, NULL, narg, &nresults);
}

#endif /* !LUACOMP_H */
