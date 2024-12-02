#include "aoc_utils.hpp"

struct report
{
    size_t size;
    std::vector<int> levels;
};

std::vector<report> construct_reports(const std::vector<std::string>& lines)
{
    std::vector<std::string> line;
    std::vector<report> reports;
    report rep;

    for (auto it = lines.begin(); it < lines.end(); it++)
    {
        line = split_space(*it);
        rep.size = line.size();
        rep.levels = std::vector<int> (rep.size);

        for (size_t i = 0; i < rep.size; i++)
        {
            rep.levels[i] = stoi(line[i]);
        }

        reports.push_back(rep);
    }

    return reports;
}

void part_one(const std::vector<report>& reports)
{
    int diff = 0;
    int prev_diff = 0;
    bool unsafe;
    size_t n_safe = 0;

    for (auto it = reports.begin(); it < reports.end(); it++)
    {
        unsafe = false;
        prev_diff = 0;

        for (size_t i = 0 ; i < it->size-1; i++)
        {
            diff = it->levels[i+1]-it->levels[i];
            if(diff*prev_diff < 0 || !( 1 <= abs(diff) && abs(diff) <= 3))
            {
                unsafe = true;
                break;
            }
            prev_diff = diff;
        }

        if (!unsafe)
        {
            n_safe++;
        }
    }

    std::cout << "Number of safe reports: " << n_safe << "\n";
}

void part_two(const std::vector<report>& reports)
{
    int diff = 0;
    int prev_diff = 0;
    bool unsafe;
    size_t n_safe = 0;
    size_t index;
    std::vector<int> ptr;


    for (auto it = reports.begin(); it < reports.end(); it++)
    {

        ptr = std::vector<int> (it->size-1);
        for (size_t j = 0; j < it->size; j++)
        {
            index = 0;
            for (size_t i = 0; i < it->size; i++)
            {
                if (i != j)
                {
                    ptr[index] = i;
                    index++;
                }
            }

            unsafe = false;
            prev_diff = 0;

            for (size_t i = 0 ; i < it->size-2; i++)
            {
                diff = it->levels[ptr[i+1]]-it->levels[ptr[i]];
                if(diff*prev_diff < 0 || !( 1 <= abs(diff) && abs(diff) <= 3))
                {
                    unsafe = true;
                    break;
                }
                prev_diff = diff;
            }

            if (!unsafe)
            {
                n_safe++;
                break;
            }
        }
    }

    std::cout << "Number of safe reports: " << n_safe << "\n";
}

int main()
{
    std::vector<std::string> lines = read_lines("input_1.txt");

    std::vector<report> reports = construct_reports(lines);
    part_one(reports);
    part_two(reports);

    return 0;
}