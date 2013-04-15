#ifndef __REMOD_H__
#define __REMOD_H__

#include "fpsgame.h"

// worlio.cpp
extern void cutogz(char *s);


// remod.cpp
typedef vector<char *> extensionslist;
extern bool addextension(const char *name);
char *conc(char **w, int n, bool space);
extern const extensionslist* getextensionslist();
extern char *authfile;

void reloadauth();

#define EXTENSION(name) bool __dummyext_##name = addextension(#name)

namespace server
{
    void filtercstext(char *str);
    bool checkpban(uint ip);
    void addban(int cn, char* actorname, int expire);
    void addpban(const char *name, const char *reason);
}

namespace remod
{
    using namespace server;

    extern char *mapdir;

    clientinfo* findbest(vector<clientinfo *> &a);
    bool playerexists(int *pcn);
    int parseplayer(const char *arg);
    bool ismaster(int *cn);
    bool isadmin(int *cn);
    bool isspectator(int *cn);
    bool isediting(int *cn);
    void concatpstring(char** str, const char *piece);
    void concatpstring(char** str, int count,  ...);
    void loadbans();
    void writebans();
    bool loadents(const char *fname, vector<entity> &ents, uint *crc);
    bool writeents(const char *mapname, vector<entity> &ents, uint mapcrc);
}
#endif
