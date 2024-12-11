#include <iostream> 
#include "notebook.h" 

int main() {
    setlocale(LC_ALL, "RUS");
    Notebook notebook;

    notebook.load("data.txt");

    std::cout << "Записная книжка:\n\n" << notebook;

    notebook.add("Иван Иванов", 1234567);
    notebook.add("Петр Петров", 2345678);
    notebook.add("Дмитрий Сидоров", 3456789);
    notebook.add("Валерия Алексеева", 4567890);
    std::cout << "Поиск по телефону:" << std::endl;
    try {
        std::string name = notebook.find(1234567);
        std::cout << "Имя по телефону 1234567: " << name << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        std::string name = notebook.find(3456789);
        std::cout << "Имя по телефону 3456789: " << name << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    std::cout << "\nПоиск по имени:" << std::endl;
    try {
        unsigned phone = notebook.find("Петр Петров");
        std::cout << "Телефон по имени Петр Петров: " << phone << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        unsigned phone = notebook.find("Валерия Алексеева");
        std::cout << "Телефон по имени Валерия Алексеева: " << phone << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    notebook.erase("Иван Иванов");
    notebook.save("data.txt");

    std::cout << "\nЗаписная книжка после изменений:\n" << notebook;

    return 0;
}
