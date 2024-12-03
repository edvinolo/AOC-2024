#include "aoc_utils.hpp"

int find_and_mul(const std::string& input_line)
{
    std::string line = input_line;
    std::regex mul_op ("mul[()]\\d{1,3},\\d{1,3}[)]");
    std::smatch mul_match;

    std::string match;
    std::regex number ("\\d{1,3}");
    std::smatch number_match;

    size_t i = 0;
    int numbers [2] = {0,0};
    int sum = 0;

    while(std::regex_search(line,mul_match,mul_op))
    {
        match  = mul_match[0];
        i = 0;
        while(std::regex_search(match,number_match,number))
        {
            numbers[i] = stoi(number_match[0]);
            i++;
            match = number_match.suffix().str();
        }

        sum += numbers[0]*numbers[1];
        line = mul_match.suffix().str();
    }

    return sum;
}

int find_and_mul_cond(const std::string& input_line)
{
    std::string line = input_line;
    std::regex op;
    std::regex mul_op ("mul[()]\\d{1,3},\\d{1,3}[)]|don't[(][)]");
    std::regex do_op("do[(][)]");
    std::smatch op_match;
    bool do_mul;

    std::string match;
    std::regex number ("\\d{1,3}");
    std::smatch number_match;

    size_t i = 0;
    int numbers [2] = {0,0};
    int sum = 0;

    op = mul_op;
    do_mul = true;
    while(std::regex_search(line,op_match,op))
    {
        match  = op_match[0];

        if (match == "don't()")
        {
            op = do_op;
            do_mul = false;
        }

        else if (match == "do()")
        {
            op = mul_op;
            do_mul = true;
        }

        else if (do_mul)
        {
            i = 0;
            while(std::regex_search(match,number_match,number))
            {
                numbers[i] = stoi(number_match[0]);
                i++;
                match = number_match.suffix().str();
            }

            sum += numbers[0]*numbers[1];
        }

        line = op_match.suffix().str();
    }

    return sum;
}

void part_one(const std::vector<std::string>& lines)
{
    int sum = 0;
    for (auto it = lines.begin(); it < lines.end(); it++)
    {
        sum += find_and_mul(*it);
    }

    std::cout << "Part one: " << sum << "\n";
}

void part_two(const std::vector<std::string>& lines)
{
    int sum = 0;
    std::string instructions = "";

    //Need to concatenate the lines otherwise to not reset the control flow in the instruction checker
    for (auto it = lines.begin(); it < lines.end(); it++)
    {
        instructions += *it;
    }

    sum = find_and_mul_cond(instructions);

    std::cout << "Part two: " << sum << "\n";
}

int main()
{
    std::vector<std::string> lines = read_lines("input_1.txt");

    //print_vec(lines);

    part_one(lines);
    part_two(lines);

    return 0;
}