#include "PetShop.cpp"

int main() {
    PetShop shop;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Produk\n2. Tampilkan Produk\n3. Ubah Produk\n4. Hapus Produk\n5. Cari Produk\n0. Keluar\nPilih: ";
        cin >> choice;
        cin.ignore();
        
        string name, category;
        double price;
        int id;

        switch (choice) {
            case 1:
                cout << "Nama: "; getline(cin, name);
                cout << "Kategori: "; getline(cin, category);
                cout << "Harga: "; cin >> price;
                shop.addProduct(name, category, price);
                break;
            case 2:
                shop.displayProducts();
                break;
            case 3:
                cout << "ID produk: "; cin >> id;
                cin.ignore();
                cout << "Nama baru: "; getline(cin, name);
                cout << "Kategori baru: "; getline(cin, category);
                cout << "Harga baru: "; cin >> price;
                shop.updateProduct(id, name, category, price);
                break;
            case 4:
                cout << "ID produk: "; cin >> id;
                shop.deleteProduct(id);
                break;
            case 5:
                cout << "Nama produk: "; cin.ignore(); getline(cin, name);
                shop.searchProduct(name);
                break;
            case 0:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);
    
    return 0;
}
