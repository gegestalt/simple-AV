#include "simple-af-av.h"

Database mkdatabase(int32 cap) {
    Database db;
    Entry* p; 
    int32 size; 
    
    db.num = 0; 
    db.cap = cap; 
    size = cap * sizeof(struct s_entry);
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
	int32 n;

    printf("cap:\t%d\nnum:\t%d\n", db.cap, db.num);
	for (n = 0; n < db.num; n++) {
		printf("Entry %d: %s/%s\n", n, db.entries[n].dir, db.entries[n].file);
	}
}

void addto_database (Database db, Entry e) {
	int32 size, cap, ix;

	//check if the capacity is full
	if (db.num == db.cap) {
		cap	= db.cap + Blocksize;
		size =cap * sizeof(struct s_entry);
		db.entries = realloc(db.entries, size); //if realloc fails, db.entries will be NULL
		assert(db.entries);
		db.cap = cap;
	}
	ix = db.num;
	memcpy($c &e , $c &db.entries[ix],sizeof(struct s_entry));
	db.num++;

	return;

	

}
int main(int argc, char *argv[]) {
    Database db; 

	Entry e1, e2;
	memcpy(e1.file, "FILE1.txt", strlen("FILE1.txt") + 1);
    memcpy(e1.dir, "/tmp", strlen("/tmp") + 1);
    memcpy(e2.file, "FILE2.txt", strlen("FILE2.txt") + 1);
    memcpy(e2.dir, "/tmp", strlen("/tmp") + 1);

    db = mkdatabase(50000);
	addto_database(db, e1);
	addto_database(db, e2);
    showdb(db);
    destroydb(db);
    return 0;
}