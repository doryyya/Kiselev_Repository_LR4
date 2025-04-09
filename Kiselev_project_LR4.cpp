#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;



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

void dr(int& x,int& y, int&z ){
    double sum = x + y + z;
    int sumi = sum;
    sum -= sumi;
    cout << "Дробная часть суммы чисел равна: " << sum << endl;
}

void okrugl(){
//разрабатывается Developer2 - ветка branch_fun_2
}




struct MenuItem {
    string title;
    function<void()> action;
};



int main() {
    int x, y, z;
    
    map<int, MenuItem> menu = {
        {1, {"Ввести x: ", [&](){ enterNumber(x, "Введите x: "); }}},
        {2, {"Ввести y: ", [&](){ enterNumber(y, "Введите y: "); }}},
        {3, {"Ввести z: ", [&](){ enterNumber(z, "Введите z: "); }}},
        {4, {"Дробная часть: ", [](){ /* логика для дробной части */ }}},
        {5, {"Округлить: ", [](){ /* логика округления */ }}},
        {6, {"Выход: ", [](){ exit(0); }}}
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
    
