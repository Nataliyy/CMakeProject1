#ifndef NOTEBOOK_H 
#define NOTEBOOK_H 

#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 

struct Entry {
    std::string name;
    unsigned phone;
};

class Notebook {
public:
    void add(const std::string& name, unsigned phone);
    void erase(const std::string& name);
    std::string& find(unsigned phone);
    unsigned find(const std::string& name);
    void load(const std::string& filename);
    void save(const std::string& filename);

    friend std::ostream& operator<<(std::ostream& out, const Notebook& notebook);

private:
    std::vector<Entry> entries;
};

#endif 
