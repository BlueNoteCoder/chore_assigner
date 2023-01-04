#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Chore {
    std::string name;
};

Chore create_chore(int num_of_chores = 1) {
    Chore chore;
    std::string chore_name = "";

    std::cout << "Chore name: ";
    std::getline(std::cin, chore_name);

    chore.name = chore_name;

    return chore;
}

std::vector<Chore> create_many_chores(std::vector<std::string> chores) {
    std::vector<Chore> list_of_chores = {};

    for(auto chore_name : chores) {
        Chore new_chore;
        new_chore.name = chore_name;

        list_of_chores.push_back(new_chore);
    }
    
    return list_of_chores;
}

class Person {
	public:
		Person();
    	Person(std::string chore_name, std::string person_name);
        Person(std::string person_name);
    	std::string get_name();
        std::vector<std::string> get_names();
    	int get_index_of_chore(std::string chore_name);
    	void add_chore(std::string chore_name);
    	std::string remove_chore(std::string chore_name);
    // Chore Status ... Enum?
    std::string person_name;
    std::vector<Chore> chores;
    static std::vector<std::string> people_names;
    static int num_of_chores;

};

int Person::num_of_chores = 0;
std::vector<std::string> Person::people_names = {};

Person::Person() {
    this->person_name = "";
    this->chores = {};
    num_of_chores = 0;
}

Person::Person(std::string chore_name, std::string person_name) {
    Chore chore;
    chore.name = chore_name;

    this->chores.push_back(chore);
    num_of_chores = 1;
    this->person_name = person_name;
    people_names.push_back(person_name);
}

Person::Person(std::string person_name) {
    this->person_name = person_name;
    this->chores = {};
    num_of_chores = 0;
    people_names.push_back(person_name);
}

std::vector<std::string> Person::get_names() {
    return people_names;
}

std::string Person::get_name() {
    return this->person_name;
}

void Person::add_chore(std::string chore_name) {
    Chore chore;
    chore.name = chore_name;

    this->chores.push_back(chore);
    num_of_chores++;  // Update number of chores
}

std::string Person::remove_chore(std::string chore_name) {
    int chore_idx = get_index_of_chore(chore_name);
    
    // Return if vector is empty
    if(chore_idx == -1) {
        return "No Chores stored!";
    }

    std::string chore_to_be_deleted = this->chores.at(chore_idx).name;
    this->chores.erase(this->chores.begin() + chore_idx);

    num_of_chores--;  // Update number of chores

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

Person create_person(std::string person_name) {
    return Person(person_name);
}

std::map<std::string, Person> create_many_people(int num_of_people) {
    std::map<std::string, Person> people;

    for(int idx = 0; idx < num_of_people; idx++) {
        std::string name;

        std::cout << "Name of Person: " << std::endl;
        std::cin >> name;

        Person person(name);

        people[name] = person;
    }

    return people;
}

std::map<std::string, Person> create_many_people(std::vector<std::string> peoples_names) {
    std::map<std::string, Person> people;

    for(auto name : peoples_names) {
        Person person(name);

        people[name] = person;
    }

    return people;
}

void assign_chores_to_people(std::vector<Chore> chores, std::map<std::string, Person>& people, char output='n') {
    // Copy chore vector
    std::vector<Chore> temp_chores;

    for(auto chore : chores) {
        temp_chores.push_back(chore);
    }

    std::vector<std::string> people_names;

    for (auto const& [key, val] : people) {
        people_names.push_back(key);
    }

    int idx = 0;
    int temp_size = temp_chores.size();
    
    while(temp_size > 0) {
 
        int rand_idx = rand() % (temp_chores.size());
        std::string chore = temp_chores.at(rand_idx).name;
        
        people[people_names.at(idx)].add_chore(chore);

        if(tolower(output) == 'y') {
            std::cout << "\nChore: " << chore << "\nAssigned to: " << people[people_names.at(idx)].get_name() << std::endl;
        }
        
        temp_chores.erase(temp_chores.begin() + rand_idx);
        
        if(idx >= people_names.size() - 1) {
            idx = 0;
        } else {
            idx++;
        }
        temp_size--;
    }
}