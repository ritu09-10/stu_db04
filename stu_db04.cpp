#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void show_data(int searchkey); // function used to show data to end-user.
void get_data(int i);          // function use to obtain data from end-user.
void search_student(int searchkey);
void add_student();              // this function is used to add record of new student.
void edit_student(int idnumber); // function is used to edit existing record.

int ts;

struct student // structure student is made to store student attributes.
{
    int rollno;
    string name;
    string fname;
    string cell;
    string dob;
    string address;
};

student rec[50]; // This is a basic array of defined structure to store data.

int main()
{
    system("CLS");
    system("color B1");
    int choice;    // int variable used to determine which operation user wants to perform.
    int idnumber;  // int variable used to record ID number which user wants to edit.
    int searchkey; // int variable to store student roll_no by which user can search.

    cout << "Enter the Total Number of student(s) (Max 50): ";
    cin >> ts;

    while (true)
    {
        cout << "\n\t\tWhat do you want to do?" << endl;
        cout << "\t\t----------------------" << endl;
        cout << "\t\t1-Add student" << endl;
        cout << "\t\t2-Edit student" << endl;
        cout << "\t\t3-Search student" << endl;
        cout << "\t\t4-Quit Program" << endl;
        cout << "\t\t----------------------" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            if (rec[0].rollno == 0)
            {
                cout << "Please add students first." << endl;
                system("pause");
            }
            else
            {
                cout << "Which ID number do you want to edit: ";
                cin >> idnumber;

                if (idnumber >= ts || idnumber < 0)
                {
                    cout << "\nInvalid ID Number." << endl;
                }
                else
                {
                    edit_student(idnumber);
                }
            }
            break;
        case 3:
            if (rec[0].rollno == 0)
            {
                cout << "Please add students first." << endl;
                system("pause");
            }
            else
            {
                cout << "Enter roll_no of student you want to search: ";
                cin >> searchkey;
                search_student(searchkey);
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid number." << endl;
            system("pause");
        }
    }
    return 0;
}

void get_data(int i)
{
    cout << "Enter student roll number in format (1XXX): ";
    cin >> rec[i].rollno;
    cout << "Enter student name: ";
    cin >> rec[i].name;
    cout << "Enter student's Father name: ";
    cin >> rec[i].fname;
    cout << "Enter student's cell phone number: ";
    cin >> rec[i].cell;
    cout << "Enter student's Date of Birth (dd/mm/yyyy): ";
    cin >> rec[i].dob;
    cout << "Enter student's Address: ";
    cin.ignore();
    getline(cin, rec[i].address);
}

void show_data(int searchkey)
{
    int i = searchkey;
    cout << i << "    ";
    cout << rec[i].rollno << "   ";
    cout << rec[i].name << "   ";
    cout << rec[i].fname << "   ";
    cout << rec[i].cell << "   ";
    cout << rec[i].dob << "   ";
    cout << rec[i].address << "\n\n";
}

void search_student(int searchkey)
{
    for (int i = 0; i < ts; i++)
    {
        if (rec[i].rollno == searchkey)
        {
            show_data(i);
            return;
        }
    }
    cout << "Student not found." << endl;
}

void add_student()
{
    for (int i = 0; i < ts; i++)
    {
        get_data(i);
    }
    system("CLS");
    for (int i = 0; i < ts; i++)
    {
        show_data(i);
    }
    system("pause");
}

void edit_student(int idnumber)
{
    for (int i = 0; i < ts; i++)
    {
        if (idnumber == i)
        {
            cout << "\nExisting information about this record:\n\n";
            show_data(i);
            cout << "\nEnter new data for the above shown record.\n\n";
            get_data(i);
            cout << "\nRecord updated successfully." << endl;
            system("pause");
            return;
        }
    }
    cout << "Invalid ID." << endl;
}
