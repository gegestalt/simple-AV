#include "simple-av.h"

Database mk_database(int32_t capacity) {
    Database db;
    size_t size;
    Entry *entry_pointer;

    db.number_of_entries = 0;
    db.capacity = capacity;
    size = capacity * sizeof(Entry);
    entry_pointer = (Entry *)malloc(size);
    assert(entry_pointer);
    memset(entry_pointer, 0, size);
    db.entries = entry_pointer;

    return db;
}

void destroy_database(Database db) {
    db.number_of_entries = 0;
    db.capacity = 0;
    free(db.entries);
}

void show_database(Database db) {
    printf("Database capacity: \t%d\nnumber:\t%d\n", db.capacity, db.number_of_entries);
}

int main(int argc, char *argv[]) {
    Database db;
    db = mk_database(50000);
    show_database(db);
    destroy_database(db);
    return 0;
}