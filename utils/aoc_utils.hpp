#ifndef AOC_UTILS_HPP
#define AOC_UTILS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <math.h>
#include <regex>

template <typename T>
void print_vec(const std::vector<T> & vec)
{
    std::cout << "\n";
    for (auto it = vec.begin(); it < vec.end(); it++)
    {
        std::cout << *it << std::endl;
    }
};

std::vector<std::string> read_input(const std::string& input)
{
    std::ifstream file(input);
    std::vector<std::string> values;
    std::string value;

    while (file >> value)
    {
        values.push_back(value);
    }

    file.close();

    return values;
}

std::vector<std::string> read_lines(const std::string& input)
{
    std::ifstream file(input);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file,line))
    {
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> split_space(const std::string& string)
{
    std::vector<std::string> result;
    std::istringstream iss(string);
    std::string substring;

    while(iss >> substring)
    {
        result.push_back(substring);
    }

    return result;
}

template <typename T>
struct columns
{
    size_t size;
    std::vector<T> left;
    std::vector<T> right;
};


columns<int> read_col_int(const std::string& input)
{
    std::vector<std::string> numbers = read_input(input);
    columns<int> cols;

    cols.size = numbers.size()/2;
    cols.left = std::vector<int> (cols.size);
    cols.right = std::vector<int> (cols.size);

    for (size_t i = 0; i < numbers.size(); i += 2)
    {
        cols.left[i/2] = std::stoi(numbers[i]);
        cols.right[i/2] = std::stoi(numbers[i+1]);
    }

    return cols;
};

template <typename T,typename Op>
std::vector<T> vec_op(const std::vector<T>& a, const std::vector<T>& b)
{
    Op o;
    std::vector<T> result = std::vector<T> (a.size());
    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = o(a[i],b[i]);
    }

    return result;
};

template <typename T>
T sum(const std::vector<T>& a)
{
    T result = 0;

    for (size_t i = 0; i < a.size(); i++)
    {
        result += a[i];
    }

    return result;
}

template <typename T>
T abs_sum(const std::vector<T>& a)
{
    T result = 0;

    for (size_t i = 0; i < a.size(); i++)
    {
        result += abs(a[i]);
    }

    return result;
}


#endif //AOC_UTILS_HPP