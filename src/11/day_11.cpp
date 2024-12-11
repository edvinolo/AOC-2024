#include "day_11.hpp"
namespace day_11
{

void trim_string(std::string& str)
{
    size_t i = 0;

    while(str[i] == '0' && i <str.size()-1)
    {
        i++;
    }

    str = str.substr(i);
}

long update_recur(std::string number,size_t i,size_t i_max,std::map<std::string,long>& cache)
{
    std::string first;
    std::string second;
    long res;
    std::string str_i = std::to_string(i); 
    std::string hash = str_i + "_" + number;

    if (cache.contains(hash))
    {
        return cache[hash];
    }

    if (i==i_max)
    {
        return 1;
    }

    if (number == "0")
    {
        res = update_recur("1",i+1,i_max,cache);
    }

    else if (number.size()%2 == 0)
    {
        first = number.substr(0,number.size()/2);
        second = number.substr(number.size()/2);
        trim_string(second);
        res = update_recur(first,i+1,i_max,cache);
        res += update_recur(second,i+1,i_max,cache);
    }

    else
    {
        res = update_recur(std::to_string(2024*stol(number)),i+1,i_max,cache);
    }

    cache.emplace(hash,res);
    return res;

}

void part_one(std::vector<std::string>& numbers)
{
    long sum = 0;
    std::map<std::string,long> cache;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        sum += update_recur(numbers[i],0,25,cache);
    }

    std::cout << "Part one: " << sum << "\n";
}

void part_two(std::vector<std::string>& numbers)
{
    long sum = 0;
    std::map<std::string,long> cache;

    for (size_t i = 0; i < numbers.size(); i++)
    {
        sum += update_recur(numbers[i],0,75,cache);
    }

    std::cout << "Part two: " << sum << "\n";
}

void run()
{
    std::string line = read_lines("../input/11/input_1.txt")[0];
    std::vector<std::string> numbers = split_space(line);

    part_one(numbers);
    part_two(numbers);
}

}