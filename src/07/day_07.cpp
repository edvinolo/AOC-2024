#include "day_07.hpp"

namespace day_07
{

bool is_valid(const std::vector<long>& numbers,long res,size_t i)
{
    bool valid_mul,valid_add;

    if (i == 1)
    {
        if (numbers[i] == res)
        {
            return true;
        }

        else
        {
            return false;
        }
    }


    if (res%numbers[i] == 0)
    {
        valid_mul = is_valid(numbers,res/numbers[i],i-1);
    }
    else
    {
        valid_mul = false;
    }

    valid_add = is_valid(numbers,res-numbers[i],i-1);

    if (valid_add || valid_mul)
    {
        return true;
    }

    return false;
}

bool is_valid_two(const std::vector<long>& numbers,long res,size_t i)
{
    bool valid_mul,valid_add,valid_con;

    if (i == 1)
    {
        if (numbers[i] == res)
        {
            return true;
        }

        else
        {
            return false;
        }
    }


    if (res%numbers[i] == 0)
    {
        valid_mul = is_valid_two(numbers,res/numbers[i],i-1);
    }
    else
    {
        valid_mul = false;
    }

    std::string temp = std::to_string(res);
    std::string temp_2 = std::to_string(numbers[i]);

    if (temp.size() > temp_2.size() && temp.substr(temp.size()-temp_2.size(),temp_2.size()) == temp_2)
    {
        temp.erase(temp.size()-temp_2.size(),temp_2.size());
        valid_con = is_valid_two(numbers,stol(temp),i-1);
    }
    else
    {
        valid_con = false;
    }

    if (res-numbers[i] >= 0)
    {
        valid_add = is_valid_two(numbers,res-numbers[i],i-1);
    }
    else
    {
        valid_add = false;
    }

    if (valid_add || valid_mul || valid_con)
    {
        return true;
    }

    return false;
}

void part_one(const std::vector<std::vector<long>>& numbers)
{
    long sum = 0;

    for (auto it = numbers.begin(); it < numbers.end(); it++)
    {
        if (is_valid(*it,(*it)[0],it->size()-1)) sum += (*it)[0];
    }

    std::cout << "Part one: " << sum << "\n";
}

void part_two(std::vector<std::vector<long>>& numbers)
{
    long sum = 0;

    for (auto it = numbers.begin(); it < numbers.end(); it++)
    {
        if (is_valid_two(*it,(*it)[0],it->size()-1)) sum += (*it)[0];
    }
    std::cout << "Part two: " << sum << "\n";
}

void run()
{
    std::vector<std::string> lines = read_lines("../input/07/input_1.txt");

    std::vector<std::vector<long>> numbers = extract_long_array(lines);

    part_one(numbers);
    part_two(numbers);
}

}