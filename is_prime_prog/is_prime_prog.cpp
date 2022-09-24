#include <iostream>
#include <string>

void is_prime(int k) {
    if (k == 1) {
        std::cout << k << " is a prime: False" << std::endl;
        return;
    }
    for (int i = 2; i < k/2; i++) {
        if (k%i == 0) {
            std::cout << k << " is a prime: False" << std::endl;
            return;
        }
    }
    std::cout << k << " is a prime: True" << std::endl;
}

int main() {
    std::string nums;
    std::getline(std::cin, nums);
    std::string num = "";

    for(long unsigned int k = 0; k < nums.length(); k++) {
        if (isdigit(nums[k])) {
            num += nums[k];
        }
        if (nums[k+1] == ' ' || nums[k+1] == '\0') {
            is_prime(stoi(num));
            num = "";
        }
    }
    return 0;


}