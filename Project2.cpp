#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    int quantity;
public:
    void addBook()
    {
        ofstream out("books.txt", ios::app);

        cout << "\nEnter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Quantity: ";
        cin >> quantity;

        out << bookID << "," << title << "," << author << "," << quantity << endl;

        out.close();

        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        ifstream in("books.txt");

        cout << "\n============ All Books ============\n";

        bool found = false;

        while (in >> bookID)
        {
            in.ignore();

            getline(in, title, ',');
            getline(in, author, ',');
            in >> quantity;

            in.ignore();

            found = true;

            cout << "\nID: " << bookID << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Quantity: " << quantity << endl;
        }

        cout << "\n===================================" << endl;
        in.close();

        if (!found)
        {
            cout << "No book data found!" << endl;
        }
    }
};

class User {
private:
    int userID;
    string name;
public:
    void addUser()
    {
        cout << "\nEnter User ID: ";
        cin >> userID;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        ofstream out("libraryUser.txt", ios::app);
        out << userID << " " << name << endl;
        out.close();

        cout << "User added successfully!\n";
    }

    void displayUsers()
    {
        ifstream in("libraryUser.txt");

        cout << "\n============ All Users ============\n";
        bool found = false;
        while (in >> userID >> name)
        {
            found = true;
            cout << "\nID: " << userID << endl;
            cout << "Name: " << name << endl;
        }
        cout << "\n====================================" << endl;
        if (!found)
        {
            cout << "\nNo user data found!" << endl;
        }
        in.close();
    }
};

class Transaction {
public:
    void issueBook() {
        int bookID, userID;

        cout << "\nEnter User ID: ";
        cin >> userID;

        cout << "Enter Book ID: ";
        cin >> bookID;

        ofstream out("transactions.txt", ios::app);
        out << userID << " " << bookID << " ISSUED" << endl;
        out.close();

        cout << "Book Issued Successfully!\n";
    }

    void returnBook() {
        int bookID, userID;

        cout << "\nEnter User ID: ";
        cin >> userID;

        cout << "Enter Book ID: ";
        cin >> bookID;

        ofstream out("transactions.txt", ios::app);
        out << userID << " " << bookID << " RETURNED" << endl;
        out.close();

        cout << "Book Returned Successfully!\n";
    }
};

int main() {
    Book b;
    User u;
    Transaction t;

    int choice;

    cout << "====================================\n";
    cout << "           Library System           \n";
    cout << "====================================" << endl;

    do {
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Add User";
        cout << "\n4. Display Users";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            b.addBook();
            break;
        case 2:
            b.displayBooks();
            break;
        case 3:
            u.addUser();
            break;
        case 4:
            u.displayUsers();
            break;
        case 5:
            t.issueBook();
            break;
        case 6:
            t.returnBook();
            break;
        case 7:
            cout << "\n--------------------------------------------------" << endl;
            cout << "   Exiting program! Thanks for using system." << endl;
            cout << "--------------------------------------------------" << endl;
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    system("pause");
    return 0;
}