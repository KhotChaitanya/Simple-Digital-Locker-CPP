// File: DigitalLocker.cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Locker {
private:
    vector<string> names;
    vector<string> secrets;

public:
    void addItem() {
        string name, secret;
        cout << "\nEnter item name (example: Bank Password): ";
        getline(cin >> ws, name); // ws to consume any whitespace
        cout << "Enter secret data: ";
        getline(cin, secret);

        names.push_back(name);
        secrets.push_back(secret);

        cout << "✅ Item added successfully!\n";
    }

    void viewItems() {
        if (names.empty()) {
            cout << "\n⚠️ No items in locker yet!\n";
            return;
        }

        cout << "\n----- Locker Items -----\n";
        for (size_t i = 0; i < names.size(); ++i) {
            cout << i + 1 << ". " << names[i] << " : " << secrets[i] << endl;
        }
    }

    void deleteItem() {
        if (names.empty()) {
            cout << "\n⚠️ No items to delete!\n";
            return;
        }

        int index;
        cout << "\nEnter item number to delete: ";
        cin >> index;

        if (index < 1 || index > names.size()) {
            cout << "\n⚠️ Invalid item number!\n";
            return;
        }

        names.erase(names.begin() + index - 1);
        secrets.erase(secrets.begin() + index - 1);

        cout << "🗑️ Item deleted successfully!\n";
    }

    void menu() {
        int choice;
        while (true) {
            cout << "\n===== Simple Digital Locker =====\n";
            cout << "1. Add Item\n";
            cout << "2. View Items\n";
            cout << "3. Delete Item\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // clear the input buffer

            switch (choice) {
                case 1:
                    addItem();
                    break;
                case 2:
                    viewItems();
                    break;
                case 3:
                    deleteItem();
                    break;
                case 4:
                    cout << "\nThank you for using Simple Digital Locker!\n";
                    return;
                default:
                    cout << "\n⚠️ Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    Locker locker;
    locker.menu();
    return 0;
}
