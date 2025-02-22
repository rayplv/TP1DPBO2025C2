#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PetShop {
private:
    struct Product {
        int id;
        string name;
        string category;
        double price;
    };
    
    vector<Product> products;
    int nextId = 1;

public:
    void addProduct(const string& name, const string& category, double price) {
        products.push_back({nextId++, name, category, price});
        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void displayProducts() {
        if (products.empty()) {
            cout << "Tidak ada produk tersedia." << endl;
            return;
        }
        for (const auto& p : products) {
            cout << "ID: " << p.id << ", Nama: " << p.name << ", Kategori: " << p.category << ", Harga: " << p.price << endl;
        }
    }

    void updateProduct(int id, const string& name, const string& category, double price) {
        for (auto& p : products) {
            if (p.id == id) {
                p.name = name;
                p.category = category;
                p.price = price;
                cout << "Produk berhasil diperbarui!" << endl;
                return;
            }
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void deleteProduct(int id) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->id == id) {
                products.erase(it);
                cout << "Produk berhasil dihapus!" << endl;
                return;
            }
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void searchProduct(const string& name) {
        bool found = false;
        for (const auto& p : products) {
            if (p.name.find(name) != string::npos) {
                cout << "Ditemukan -> ID: " << p.id << ", Nama: " << p.name << ", Kategori: " << p.category << ", Harga: " << p.price << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Produk tidak ditemukan." << endl;
        }
    }
};