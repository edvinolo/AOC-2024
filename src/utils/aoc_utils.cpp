#include "aoc_utils.hpp"

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

std::vector<char> get_char_array(const std::vector<std::string>& lines)
{
    std::vector<char> result (lines[0].size()*lines.size());

    for (size_t i = 0; i < lines.size(); i++)
    {
        for (size_t j = 0; j < lines[0].size(); j++)
        {
            result[i*lines[0].size()+j] = lines[i][j];
        }
    }

    return result;
}

std::vector<int> extract_int(const std::string& input_line)
{
    std::string line = input_line;
    std::regex number ("\\d+");
    std::smatch number_match;

    std::vector<int> numbers;


    while(std::regex_search(line,number_match,number))
        {
            numbers.push_back(stoi(number_match[0]));
            line = number_match.suffix().str();
        }

    return numbers;
}

std::vector<std::vector<int>> extract_int_array(const std::vector<std::string>& lines)
{
    std::vector<std::vector<int>> results;

    for (size_t i = 0; i < lines.size(); i++)
    {
        results.push_back(extract_int(lines[i]));
    }
    return results;
}

std::vector<std::vector<int>> char_to_int(const std::vector<std::string>& lines)
{
    std::vector<std::vector<int>> results (lines.size());
    std::vector<int> line (lines[0].size());

    for (size_t i = 0; i < lines.size(); i++)
    {
        for (size_t j = 0; j < lines[0].size(); j++)
        {
            line[j] = (int) lines[i][j] -'0';
        }

        results[i] = line;
    }

    return results;
}

std::vector<long> extract_long(const std::string& input_line)
{
    std::string line = input_line;
    std::regex number ("\\d+");
    std::smatch number_match;

    std::vector<long> numbers;


    while(std::regex_search(line,number_match,number))
        {
            numbers.push_back(stol(number_match[0]));
            line = number_match.suffix().str();
        }

    return numbers;
}

std::vector<std::vector<long>> extract_long_array(const std::vector<std::string>& lines)
{
    std::vector<std::vector<long>> results;

    for (size_t i = 0; i < lines.size(); i++)
    {
        results.push_back(extract_long(lines[i]));
    }
    return results;
}

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