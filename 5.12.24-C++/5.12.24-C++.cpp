// 5.12.24-C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


class Book {
    char* aut;
    char* text;
    int pages;
    int year;
    public:
        Book() = default;
        Book(const char* _aut, const char* _text, int _pg,int _y)
        {
            aut = new char[strlen(_aut) + 1];
            strcpy_s(aut, strlen(_aut) + 1, _aut);
            text = new char[strlen(_text) + 1];
            strcpy_s(text, strlen(_text) + 1, _text);
            pages = _pg;
            year = _y;
        }
        Book& operator=(const Book& obj) = delete;
        Book(Book& obj) = delete;
        Book& operator=(Book&& obj) 
        {
            aut = obj.aut;
            text = obj.text;
            pages = obj.pages;
            year = obj.year;
            obj.aut = nullptr;
            obj.text = nullptr;
            obj.pages = 0;
            obj.year = 0;
            return*this;
        }
        Book(Book&& obj) 
        {
            aut = obj.aut;
            text = obj.text;
            pages = obj.pages;
            year = obj.year;
            obj.aut = nullptr;
            obj.text = nullptr;
            obj.pages = 0;
            obj.year = 0;
        }

        void Print() {
            cout << aut << endl << text << endl << pages<<endl << year<<endl;
        }
};


int main()
{
    Book a("hello", "he", 1, 2);

    Book d = move(a);
    d.Print();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
