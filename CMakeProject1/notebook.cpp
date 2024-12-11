#include "notebook.h" 

void Notebook::add(const std::string& name, unsigned phone) {
    entries.push_back({ name, phone });
}

void Notebook::erase(const std::string& name) {
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        if (it->name == name) {
            entries.erase(it);
            return;
        }
    }
    std::cout << "Запись с таким именем не найдена.\n";
}

std::string& Notebook::find(unsigned phone) {
    for (auto& entry : entries) {
        if (entry.phone == phone) {
            return entry.name;
        }
    }
    throw std::runtime_error("Запись с таким номером не найдена.");
}

unsigned Notebook::find(const std::string& name) {
    for (const auto& entry : entries) {
        if (entry.name == name) {
            return entry.phone;
        }
    }
    throw std::runtime_error("Запись с таким именем не найдена.");
}
void Notebook::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string name;
    unsigned phone;
    while (file >> name >> phone) {
        add(name, phone);
    }
}

void Notebook::save(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    for (const auto& entry : entries) {
        file << entry.name << " " << entry.phone << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Notebook& notebook) {
    for (const auto& entry : notebook.entries) {
        out << entry.name << ": " << entry.phone << std::endl;
    }
    return out;
}