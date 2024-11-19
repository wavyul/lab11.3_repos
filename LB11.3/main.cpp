#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

struct Route
{
    string start_point;
    string end_point;
    int route_number = 0;
};

void Create(const string file_name, const int option);
void Print(const string file_name);
void Search(const string file_name);
void AddToFile(const string file_name);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string file_name = "test.txt";

    int MenuItem;

    while (true)
    {
        cout << endl << endl << endl;
        cout << "������ ��:" << endl;
        cout << "1 - ������ ���������� ��� �������" << endl;
        cout << "2 - ������� ���������� ��� ��������" << endl;
        cout << "3 - ����� �������� �� �������" << endl;
        cout << "4 - ������ ���������� �� �����" << endl;
        cout << "0 - ��������� ������ ��������" << endl;
        cout << "������: ";
        cin >> MenuItem;
        cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(file_name, 1);
            break;
        case 2:
            Print(file_name);
            break;
        case 3:
            Search(file_name);
            break;
        case 4:
            AddToFile(file_name);
            break;
        }
        if (MenuItem == 0) break;
    }

    return 0;
}

void Create(const string file_name, int option)
{
    Route R;

    ofstream f;

    if (option == 1)
        f.open(file_name, ios::out);
    else
        f.open(file_name, ios::app);

    if (!f.is_open())
    {
        cout << "���� �� �������!" << endl;
        return;
    }
    cin.get();

    string keep;

    do
    {
        cout << "���������� �����: ";
        getline(cin, R.start_point);
        f << R.start_point << endl;

        cout << "ʳ������ �����: ";
        getline(cin, R.end_point);
        f << R.end_point << endl;

        cout << "����� ��������: ";
        cin >> R.route_number;
        f << R.route_number << endl;

        cin.get();
        cout << "��� ���������� ������ (Y): ";
        getline(cin, keep);
        cout << endl;
    } while (keep == "y" || keep == "Y");
}

void Print(const string file_name)
{
    ifstream f(file_name, ios::in);

    if (!f.is_open())
    {
        cout << "���� �� �������!" << endl;
        return;
    }

    cout << "========================================================================" << endl;
    cout << "| � |   ���������� �����   |    ʳ������ �����    |   ����� ��������   |" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    Route R;
    int number = 1;

    while (getline(f, R.start_point) && getline(f, R.end_point) && f >> R.route_number)
    {
        f.ignore();
        cout << "|" << setw(3) << number++ << "|"
            << setw(21) << R.start_point << " |"
            << setw(21) << R.end_point << " |"
            << setw(19) << R.route_number << " |" << endl;
    }
    cout << "========================================================================" << endl << endl;

    f.close();
}


void Search(const string file_name)
{
    ifstream f(file_name, ios::in);

    if (!f.is_open())
    {
        cout << "���� �� �������!" << endl;
        return;
    }

    int route_number;
    cout << "������ ����� ��������: ";
    cin >> route_number;

    cout << "==========================================================================" << endl;
    cout << "|  �  |   ���������� �����   |    ʳ������ �����    |   ����� ��������   |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    Route R;

    int i = 1;
    bool found = false;


    while (getline(f, R.start_point) && getline(f, R.end_point) && f >> R.route_number)
    {
        f.ignore();
        if (R.route_number == route_number)
        {
            cout << "|" << setw(4) << i << " |" << setw(21) << R.start_point
                << " |" << setw(21) << R.end_point
                << " |" << setw(19) << R.route_number << " |\n";
            i++;
            found = true;
        }
    }

    cout << "==========================================================================" << endl << endl;

    if (!found)
    {
        cout << "������� � ����� ������� �� ��������." << endl;
    }

    f.close();
}

void AddToFile(const string file_name)
{
    Create(file_name, 2);
}
