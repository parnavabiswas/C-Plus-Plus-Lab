/*
 * Book shop example: runtime polymorphism through base-class pointers.
 *
 * Virtual-function rules illustrated here:
 * - Virtual functions are non-static member functions declared in a base class.
 * - Derived overrides should have matching signatures; `override` lets the
 *   compiler verify this.
 * - A virtual call through a base pointer/reference dispatches to the function
 *   for the object's dynamic type.
 * - Virtual functions remain virtual in further derived classes.
 * - Constructors cannot be virtual; polymorphic base classes should have a
 *   virtual destructor so derived objects are safely destroyed via base pointers.
 * - Virtual dispatch does not call a more-derived override from a base
 *   constructor or destructor.
 * - Default arguments on virtual functions are selected by the static type.
 */
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Media {
protected:
    string title;
    string publication;

public:
    virtual ~Media() = default;

    virtual void read() {
        cout << "Title: ";
        getline(cin, title);

        cout << "Publication: ";
        getline(cin, publication);
    }

    virtual void show() const {
        cout << "Title: " << title << '\n'
             << "Publication: " << publication << '\n';
    }
};

class Book : public Media {
private:
    int pages{};

public:
    void read() override {
        Media::read();
        cout << "Number of pages: ";
        cin >> pages;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void show() const override {
        cout << "\nBook\n";
        Media::show();
        cout << "Pages: " << pages << '\n';
    }
};

class Tape : public Media {
private:
    double playingTime{}; // Minutes

public:
    void read() override {
        Media::read();
        cout << "Playing time (minutes): ";
        cin >> playingTime;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void show() const override {
        cout << "\nVideo tape\n";
        Media::show();
        cout << "Playing time: " << playingTime << " minutes\n";
    }
};

int main() {
    vector<unique_ptr<Media>> items;
    int count;

    cout << "How many items? ";
    if (!(cin >> count) || count < 0) {
        cerr << "Please enter a non-negative number.\n";
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < count; ++i) {
        char type;
        cout << "\nEnter B for book or T for tape: ";
        cin >> type;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        unique_ptr<Media> item;
        if (type == 'B' || type == 'b') {
            item = make_unique<Book>();
        } else if (type == 'T' || type == 't') {
            item = make_unique<Tape>();
        } else {
            cout << "Unknown type; please try again.\n";
            --i;
            continue;
        }

        item->read(); // Dispatches to Book::read() or Tape::read().
        items.push_back(move(item));
    }

    cout << "\n--- Items in the shop ---\n";
    for (const auto& item : items) {
        item->show(); // Dispatches to Book::show() or Tape::show().
    }

    return 0;
}
