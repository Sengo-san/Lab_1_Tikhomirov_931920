#include <QCoreApplication>

#include <string.h>
#include <iostream>

using namespace std;

#include <EStackEmpty.h>
#include <Stack.h>


int main(int argc, char *argv[])
{

       string str1 = "Ivan";
       string str2 = "Igor";

       Stack <string> names;  //создаем стек строк

       names.push(str1);//кладем строки в стек
       names.push(str2);

       cout << names.getSize() << endl; //получаем размер

       cout << names.pop() << endl;  //извлекаем элеленты
       cout << names.pop() << endl;

       cout << names.pop() << endl;   //пытаемся извлечь из пустого стека, получаем ошибку

       return 0;
}
