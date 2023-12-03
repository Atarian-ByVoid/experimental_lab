
#include <pqxx/pqxx>
#include <iostream>
#include <chrono> 
#include <thread>
using namespace std;
using namespace pqxx;

int main() {
    try {
        while (true) {
        connection C("dbname=crow user=root password=root hostaddr=127.0.0.1 port=5432");
            if (C.is_open()) {
                cout << "Conexão com o banco de dados PostgreSQL estabelecida com sucesso." << endl;
            } else {
                cout << "Erro ao conectar ao banco de dados PostgreSQL." << endl;
                return 1;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
