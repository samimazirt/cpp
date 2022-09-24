#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc == 3) {
        std::ifstream file;
        file.open(argv[1]);
        if (file.is_open()) {
            int k = 0;
            while (file) {
                std::string txt_file;

                getline(file, txt_file);
                if (txt_file.find(argv[2]) != std::string::npos)
                {
                    k += 1;
                }
            }
            std::cout << "The file " << argv[1] << " contains " << k << " words containing the motive " << argv[2] << std::endl;
            return 0;
        } else {
            std::cout << "The file " << argv[1] << " could not be opened." << std::endl;
            return 1;
        }
    } else {
        return 1;
    }

}