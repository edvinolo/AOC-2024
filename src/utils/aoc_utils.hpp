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
#include <memory>
#include <filesystem>
#include <map>

template <typename T>
void print_vec(const std::vector<T> & vec)
{
    std::cout << "\n";
    for (auto it = vec.begin(); it < vec.end(); it++)
    {
        std::cout << *it << std::endl;
    }
};

template <typename T>
void print_array(const std::vector<std::vector<T>> & arr)
{
    std::cout << "\n";
    for (auto it = arr.begin(); it < arr.end(); it++)
    {
        for (auto id = it->begin(); id < it->end(); id++)
        {
            std::cout << *id;
        }
        std::cout << "\n";
    }
};

std::vector<std::string> read_input(const std::string&);

std::vector<std::string> read_lines(const std::string&);

std::vector<std::string> split_space(const std::string&);

std::vector<char> get_char_array(const std::vector<std::string>&);

std::vector<int> extract_int(const std::string&);

std::vector<std::vector<int>> extract_int_array(const std::vector<std::string>&);

std::vector<std::vector<int>> char_to_int(const std::vector<std::string>&);

std::vector<long> extract_long(const std::string&);

std::vector<std::vector<long>> extract_long_array(const std::vector<std::string>&);

template <typename T>
struct columns
{
    size_t size;
    std::vector<T> left;
    std::vector<T> right;
};


columns<int> read_col_int(const std::string& );

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