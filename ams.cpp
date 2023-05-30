#include <iostream>
#include <string>
#include "VariadicTable.h"
using namespace std;
class Subject
{
public:
    int id;
    string subjectName;
    float credits;
    float CAT1 = 0, CAT2 = 0, FAT = 0, DA1 = 0, DA2 = 0, DA3 = 0;
    void create(int &globalID)
    {
        cout << "Enter subject code\tcredits\tDA1\tDA2\tDA3\tmarks in CAT1\tCAT2\tFAT" << endl;
        cin >> subjectName >> credits >> CAT1 >> CAT2 >> FAT >> DA1 >> DA2 >> DA3;
        id = globalID;
        globalID++;
    }
    Subject *del(Subject s[])
    {
        Subject *s2 = new Subject[sizeof(*s) - 1];
        for (int i = 0, y = 0; i < sizeof(*s); i++, y++)
        {
            if ((s[i]).id != id)
                s2[y] = s[i];
            if ((s[i]).id == id)
                y--;
        }
        return s2;
    }

    void read()
    {
        cout << "\tid\t|\tSubject Code\t|\tCredits\t|\tDA1\t|\tDA2\t|\tDA3\t|\tCAT1\t|\tCAT2\t|\tFAT" << endl;
        cout << "\t" << id << "\t|\t" << subjectName << "\t|\t" << credits << "\t|\t" << DA1 << "\t|\t" << DA2 << "\t|\t" << DA3 << "\t|\t" << CAT1 << "\t|\t" << CAT2 << "\t|\t" << FAT << endl;
    }
    void update()
    {
        int f;
        cout << "Choose the field to be updated\t1 - Subject Code\t2 - Credits\t3 - DA1\t4 - DA2\t5 - DA3\t6 - CAT1\t7 - CAT2\t - FAT";
        cin >> f;
        cout << "Enter the new data : ";
        switch (f)
        {
        case 1:
            cin >> subjectName;
            break;
        case 2:
            cin >> credits;
            break;
        case 3:
            cin >> DA1;
            break;
        case 4:
            cin >> DA2;
            break;
        case 5:
            cin >> DA3;
            break;
        case 6:
            cin >> CAT1;
            break;
        case 7:
            cin >> CAT2;
            break;
        case 8:
            cin >> FAT;
            break;
        default:
            cout << "Wrong Input";
        }
    }
};
/*
        if= -1)
        {
            cout << "Given id does not exist in the table";
            exit(0);
        }
*/
bool read(Subject &s)
{
    // cout << "------------SubjectManagementSystem------------" << endl;
    // cout << "-------------------------------------------------------------------------------------" << endl;
    VariadicTable<int, string, float, float, float, float, float, float, float> vt({"id", "Subject Code", "Credits", "DA1", "DA2", "DA3", "CAT1", "CAT2", "FAT"}, 10);
    for (int i = 0; i < sizeof(s) - 1; i++)
    {
        vt.addRow((&s + i)->id, (&s + i)->subjectName, (&s + i)->credits, (&s + i)->DA1, (&s + i)->DA2, (&s + i)->DA3, (&s + i)->CAT1, (&s + i)->CAT2, (&s + i)->FAT);
        vt.print(cout);
    }
    return true;
}

int main()
{
    int globalID = 1, c, n = 0, id, i;
    Subject *arr = new Subject[0];
    Subject *newArr;
    while (1)
    {
        cout << "-------MENU--------" << endl;
        cout << "1 - Create new Subject" << endl
             << "2 - Read data of all subjects" << endl
             << "3 - Read data of a particular subject" << endl
             << "4 - Update data of a particular subject" << endl
             << "5 - Delete a particular subject" << endl
             << "6 - Exit program" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            n++;
            newArr = new Subject[n];
            copy(arr, arr + (n - 1), newArr);
            delete[] arr;
            arr = new Subject[n];
            copy(newArr, newArr + n, arr);
            delete[] newArr;
            arr[n - 1].create(globalID);
            break;
        case 2:
            read(*arr);
            break;
        case 3:
            cout << "Enter the Subject ID" << endl;
            cin >> id;
            for (i = 0; i < sizeof(*arr); i++)
            {
                if (id == arr[i].id)
                    break;
            }
            arr[i].read();
            break;
        case 4:
            cout << "Enter the Subject ID" << endl;
            cin >> id;
            for (i = 0; i < sizeof(*arr); i++)
            {
                if (id == arr[i].id)
                    break;
            }
            arr[i].update();
            break;
        case 5:
            cout << "Enter the Subject ID" << endl;
            cin >> id;
            for (i = 0; i < sizeof(*arr); i++)
            {
                if (id == arr[i].id)
                    break;
            }
            n--;
            newArr = new Subject[n];
            newArr = arr[i].del(arr);
            delete[] arr;
            arr = new Subject[n];
            copy(newArr, newArr + n, arr);
            delete[] newArr;
            break;
        default:
            exit(0);
        }
    }
    return 0;
}