#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int side1, side2;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {

        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...) {
        return false; 
    }
    return true;
}


void enterNumber(int& varLink, string label) {
    string str_input;
    cout << label << " - ";
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << label << " - ";
        getline(cin, str_input);
    }
    varLink = stoi(str_input);
}

void enterSide1(){
//разрабатывается Developer1 - ветка branch_fun_1
}

void enterSide2(){
//разрабатывается Developer2 - ветка branch_fun_2
}

void calcArea(){
//разрабатывается Developer3 - ветка branch_fun_3
}


struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод 1-й стороны прямоугольника", enterSide1}},
        {2, {"Ввод 2-й стороны прямоугольника", enterSide2}},
        {3, {"Calculate of Area", calcArea}},
        {4, {"Calculate of Perimetr",}},
    };

    int choice = 0;

    while(true){
        cout << "Menu: " << endl;
        for(const auto& item : menu){
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Exit" << endl;
        enterNumber(choice, "Input number of menu: ");
        if (choice == 0){
            cout << "@ 2025 Kiselev Fedor" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()){
            menu[choice].action();
        } else{
            cout << "Uncorrent enter.";
        }
        cout << endl;
    }
    return 0;
}
