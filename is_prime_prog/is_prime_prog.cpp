#include <iostream>
#include <string>


long long sqrt(long long k)
{
    long long j = 0;
    while (j * j < k)
    {
	j++;
    }
    return j;
}

void is_prime(long long k) {
    if (k <= 1) {
        std::cout << k << " is a prime: False" << std::endl;
        return;
    }
    //if (k <= 3) {
//	std::cout << k << " is a prime: True" << std::endl;
 //   	return;
   // }
   //
    //long long tmp = sqrt(k);
    for (long long i = 2; i < k/2; ++i) {
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

    for(long long k = 0; k < (long long) nums.length(); k++) {
        if (isdigit(nums[k])) {
            num += nums[k];
        }
        if (nums[k+1] == ' ' || nums[k+1] == '\0') {
            is_prime(std::stoll(num));
            num = "";
        }
    }
    return 0;


}
