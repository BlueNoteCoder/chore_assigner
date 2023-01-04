#include <limits>
#include <iostream>
#include <map>
#include <vector>
#include "lib/assignment.cpp"

int get_num_of_people() {
    int num_of_people = 0;

    std::cout << "How many people? " << std::endl;
    std::cin >> num_of_people;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return num_of_people;
}

std::vector<Chore> add_chores() {
    char selection = 'y';
    std::vector<std::string> chores;

    while(tolower(selection) == 'y') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string chore_name = " ";

        std::cout << "Chore name: " << std::endl;
        std::getline(std::cin, chore_name);
        chores.push_back(chore_name);

        std::cout << "Add another chore?(y/n) ";
        std::cin >> selection;
        // std::cout << std::endl;
    }

    return create_many_chores(chores);

}
// int get_num_of_chores() {
//     int num_of_chores = 0;

//     std::cout << "How many chores do you want to add?"
// }

int main() {
    int num_of_people = get_num_of_people();

    std::map<std::string, Person> people = create_many_people(num_of_people);
    std::vector<Chore> chores = add_chores();

    assign_chores_to_people(chores, people);

    write_to_txt_file(people);
    
    for (auto const& [key, val] : people) {
        std::cout << "Person's name : " << val.person_name << '\n';

        for(auto chore : val.chores) {
            std::cout << "\tChore: " << chore.name << '\n';
        }
        std::cout << std::endl;
 
    }

    return 0;
}