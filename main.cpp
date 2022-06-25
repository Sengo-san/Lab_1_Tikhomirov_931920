#include <QCoreApplication>

#include <string.h>
#include <iostream>
#include <QString>
using namespace std;

#include <PersonKeeper.h>

//Тестирование 2 части лабораторной
int main(int argc, char *argv[])
{
    while (1)
    {
        cout << "Read file or write to file? r/w: ";
        string rw;
        getline (cin, rw);
        if (rw == "r") {//считываем из файла в PersonKeeper
            string filename;
            cout << "Reading file name (path): ";
            getline (cin, filename);
            ifstream instr (filename);

            if (!instr || !QString::fromStdString(filename).endsWith(".txt")) //если файл не открылся или его расширение не .txt
                cout << "Opening file error (reading)" << endl;
            else
                PersonKeeper::Instance().readPersons(instr);//обращаемся к экземпляру класса-одиночки через Instance()
            instr.close();
        }
        else if (rw == "w") {//записываем из PersonKeeper в файл
            string filename;
            cout << "Writing file name (path): ";
            getline (cin, filename);
            ofstream outstr (filename);
            PersonKeeper::Instance().writePersons(outstr);
            outstr.close();
        }
    }

}
