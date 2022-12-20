#include <string>
#include <vector>


struct Chore {
    std::string name;
};

class Person {
    Person();
    Person(std::string chore_name, std::string person_name);
    std::string get_name();
    int get_index_of_chore(std::string chore_name);
    void add_chore(std::string chore_name);
    std::string remove_chore(std::string chore_name);
    // Chore Status ... Enum?
    std::string person_name;
    std::vector<Chore> chores;
    int num_of_chores;
};

Person::Person() {
    this->person_name = "";
    this->chores = {};
    this->num_of_chores = 0;
}

Person::Person(std::string chore_name, std::string person_name) {
    Chore chore;
    chore.name = chore_name;

    this->chores.push_back(chore);
    this->num_of_chores = 1;
    this->person_name = person_name;
}

std::string Person::get_name() {
    return this->person_name;
}

void Person::add_chore(std::string chore_name) {
    Chore chore;
    chore.name = chore_name;

    this->chores.push_back(chore);
    this->num_of_chores++;  // Update number of chores
}

std::string Person::remove_chore(std::string chore_name) {
    int chore_idx = get_index_of_chore(chore_name);

    // Return if vector is empty
    if(chore_idx == -1) {
        return "No Chores stored!";
    }

    std::string chore_to_be_deleted = this->chores.at(chore_idx).name;
    this->chores.erase(this->chores.begin() + chore_idx);

    this->num_of_chores--;  // Update number of chores

    return chore_to_be_deleted;
}

int Person::get_index_of_chore(std::string chore_name) {
    for(int idx = 0; idx < this->chores.size(); idx++) {
        if(this->chores[idx].name.compare(chore_name) == 0) {
            return idx;
        }
    }

    return -1;  // If chore doesn't exist, return -1
}

int main() {
    
    return 0;
}