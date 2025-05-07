#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class student {
    struct stud {
        int roll;
        string name;
        char div;
        string add;
    } rec;

public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create() {
    char ans;
    ofstream fout("stud.txt", ios::out);
    do {
        cout << "\n\tEnter Roll No of Student : ";
        cin >> rec.roll;
        cout << "\n\tEnter Name of Student : ";
        cin >> rec.name;
        cout << "\n\tEnter Division of Student : ";
        cin >> rec.div;
        cout << "\n\tEnter Address of Student : ";
        cin >> rec.add;
        fout << rec.roll << " " << rec.name << " " << rec.div << " " << rec.add << endl;
        cout << "\n\tDo You Want to Add More Records (y/n)? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display() {
    ifstream fin("stud.txt", ios::in);
    cout << "\n\tThe Content of the File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin >> rec.roll >> rec.name >> rec.div >> rec.add) {
        cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
    }
    fin.close();
}

int student::search() {
    int r;
    ifstream fin("stud.txt", ios::in);
    cout << "\n\tEnter a Roll No: ";
    cin >> r;
    while (fin >> rec.roll >> rec.name >> rec.div >> rec.add) {
        if (rec.roll == r) {
            cout << "\n\tRecord Found..\n";
            cout << "\tRoll No: " << rec.roll << "\n\tName: " << rec.name << "\n\tDivision: " << rec.div << "\n\tAddress: " << rec.add;
            fin.close();
            return 0;
        }
    }
    cout << "\n\tRecord Not Found..\n";
    fin.close();
    return 1;
}

void student::Delete() {
    int r, flag = 0;
    ifstream fin("stud.txt", ios::in);
    ofstream fout("temp.txt", ios::out);
    cout << "\n\tEnter Roll No to Delete: ";
    cin >> r;
    while (fin >> rec.roll >> rec.name >> rec.div >> rec.add) {
        if (rec.roll == r) {
            flag = 1;
            cout << "\n\tRecord Deleted.";
        } else {
            fout << rec.roll << " " << rec.name << " " << rec.div << " " << rec.add << endl;
        }
    }
    fin.close();
    fout.close();
    remove("stud.txt");
    rename("temp.txt", "stud.txt");
    if (!flag) {
        cout << "\n\tRecord Not Found.";
    }
}

int main() {
    student obj;
    int ch;
    char ans;
    do {
        cout << "\n\t1. Create\n\t2. Display\n\t3. Search\n\t4. Delete\n\t5. Exit";
        cout << "\n\tEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.search(); break;
            case 4: obj.Delete(); break;
            case 5: return 0;
            default: cout << "\n\tInvalid choice.";
        }
        cout << "\n\tDo you want to continue in main menu (y/n)? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}