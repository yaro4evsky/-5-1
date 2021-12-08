#include <iostream>
#include <string>
using namespace std;

void func(string** str, int length_word, int fr, int tw)
{
    setlocale(LC_ALL, "RUSSIAN");
    int chet = 0;
    for (int i = 0; i < fr; i++)
    {
        for (int j = 0; j < tw; j++)
        {
            if (str[i][j].size() == length_word) {
                cout << str[i][j] << "\t";
                chet++;
            }
        }
    }
    if (chet == 0)
    {
        cout << endl << "Слов с заданной длинной нет, или введен неверый формат числа" << endl;
    }
}

void func_format(string** str, int length_str, int fr, int tw)
{
    setlocale(LC_ALL, "RUSSIAN");
    int chet = 0;
    for (int i = 0; i < fr; i++)
    {
        for (int j = 0; j < tw; j++)
        {
            for (int k = 0; k < str[i][j].size(); k++)
            {
                cout << str[i][j][k];
                chet++;
                if (chet == length_str)
                {
                    cout << endl;
                    chet = 0;
                }
            }
            cout << " ";

        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    bool k = true;
    int first = 0, twelve = 0;

    string** str = new string * [50];
    cout << "Введите строки" << endl;

    for (int i = 0; k == true; i++)
    {
        str[i] = new string[50];
        for (int i = 0; k == true; i++) {
            for (int j = 0; k == true; j++) {
                cin >> str[i][j];
                if (str[i][j] == "stop")
                {
                    k = false;
                }
                twelve++;
            }
            first++;
        }
    }

    int length;
    cout << "Введите длинну слова" << endl;
    cin >> length;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка, повторите ввод -  ";
        cin >> length;
    }

    cout << "Слова с введенной длинной:" << endl;
    func(str, length, first, twelve);
    cout << endl;
    int length_str;
    cout << "Введите длинну строки:" << endl;

    cin >> length_str;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка, повторите ввод -  ";
        cin >> length_str;
    }

    func_format(str, length_str, first, twelve);

    for (int i = 0; i < first; i++)
    {
        delete[] str[i];
    }
    delete[] str;
}
