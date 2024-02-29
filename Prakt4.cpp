#include <iostream>
#include <Windows.h>
#include <random> // рандом

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    string inputWord;
    int choice;

    cout << "Введите слово: ";
    cin >> inputWord;

    cout << "Выберите действие:\n1. Слово выводится задом наперед.\n2. Вывести слово без гласных.\n3. Вывести слово без согласных.\n4. Рандомно раскидывать буквы заданного слова.\n5. Выход из программы" << endl;
    cin >> choice;
        if (choice == 1) {
            reverse(inputWord.begin(), inputWord.end()); //слона задом наперёд в диапазоне 
            cout << "Слово задом наперёд: " << inputWord << "\n";
            system("pause");
            system("cls");
            main();
        }
        else if (choice == 2) {
            string vowels = "аеёиоуыэюя";
            for (char vowel : vowels) {
                inputWord.erase(remove(inputWord.begin(), inputWord.end(), vowel), inputWord.end());
            }
            cout << "Слово без гласных: " << inputWord << "\n";
            system("pause");
            system("cls");
            main();
        }
        else if (choice == 3) {
            string consonants = "бвгджзйклмнпрстфхцчшщ"; // константа со всеми согласными буквами
            for (char consonant : consonants) { // перебор согласных букв в слове
                inputWord.erase(remove(inputWord.begin(), inputWord.end(), consonant), inputWord.end());// для удаления всех вхождений этой буквы из строки
            }
            cout << "Cлово без согласных: " << inputWord << "\n";
            system("pause");
            system("cls");
            main();
        }
        else if (choice == 4) {
            random_device rd; //рандомайзер
            mt19937 g(rd()); //  Этот объект используется для генерации псевдослучайных чисел с помощью алгоритма Mersenne Twister.
            shuffle(inputWord.begin(), inputWord.end(), g);// диапазон, в котором надо перемешивать буквы в слове
            cout << "Результат рандома: " << inputWord <<"\n";
            system("pause");
            system("cls");
            main();
        }
        else if (choice == 5) {
            cout << "Программа завершает работу. До свидания!" << endl;
            return 0;
        }

        else  {
            cout << "Некорректный выбор. Повторите действие\n";
            system("pause");
            system("cls");
            main();
        }
   
}
