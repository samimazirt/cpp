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

bool is_prime(long long t)
{
    if (t < 2){
	    return false;
    }
    else if (t <= 3){
	    return true;
    }
    if (t % 2 == 0 || t % 3 == 0)
    {
	    return false;
    }
    long long i = 5;
    while (i * i <= t)    
    {
        if (0 == t % i)
        {
            return false;
        }
	i += 1;
    }
    return true;
}

int main()
{
    long long number;
    while(std::cin >> number)
    {
        if(is_prime(number) == false)
	{
		std::cout << number << " is a prime: False\n";
	}
	else
	{
		std::cout << number << " is a prime: True\n";
	}
    }
    return 0;
}
