#include "simple-af-av.h"

Database mkdatabase(int16 cap) {
    Database db;
    Entry* p; 
    int16 size; 
    
    db.num = 0; 
    db.cap = cap; 
    size = cap * sizeof(Entry);
    p = (Entry*)malloc(size);
    assert(p);
    memset(p, 0, size);  // Replace zero() with memset()
    db.entries = p;
    return db;
}

void destroydb(Database db) {
    db.cap = 0;
    db.num = 0; 
    free(db.entries);
}

void showdb(Database db) {
    printf("cap:\t%d\nnum:\t%d\n", db.cap, db.num);
}

int main(int argc, char *argv[]) {
    Database db; 
    db = mkdatabase(50000);
    showdb(db);
    destroydb(db);
    return 0;
}