#include <iostream>
#include <unordered_map>
#include <cstdlib>


int
main(int argc, char **argv)
{
    using namespace std;

    unordered_map<string,string> to_blame;
    to_blame.insert(pair<string,string>("Stroustrup", "C++"));
    to_blame.insert(pair<string,string>("Wirth", "Modula"));

    for (auto &ents: to_blame) {
        cout << ents.first << ": " << ents.second << endl;
    }

    return EXIT_SUCCESS;

}

