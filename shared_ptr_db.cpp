#include <iostream>
#include <memory>
using namespace std;

class Database {
public:
    Database() {cout << "Database Connected" << "\n";}
    ~Database() {cout << "Database DisConnected" << "\n";}
    void query() { cout << "query DB" << "\n"; }
};


void useDatabase(shared_ptr<Database> db) {
    cout << db.use_count() << endl;
    cout << "Using database...\n";
    db->query();
}

int main(){

    shared_ptr<Database> db1 = make_shared<Database>();
    cout << db1.use_count() << "\n";

    shared_ptr<Database> db2 = db1;

    useDatabase(db2);

    cout << db2.use_count() << endl;

    return 0;
}