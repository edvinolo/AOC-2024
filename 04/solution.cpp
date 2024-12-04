#include "aoc_utils.hpp"

int search(const std::vector<std::string>& lines,size_t i, size_t j)
{
    size_t max_i = lines.size()-1;
    size_t max_j = lines[0].size()-1;
    std::string cmp;

    int sum = 0;

    //Look left
    if (j >= 3)
    {
        if (std::string(lines[i].begin() + j-3, lines[i].begin() + j + 1) == "SAMX") sum++;
    }

    //Look right
    if (j <= max_j-3)
    {
        if (std::string(lines[i].begin() + j, lines[i].begin() + j + 4) == "XMAS") sum++;
    }

    //Look up
    if (i >= 3)
    {
        cmp = "";
        for (auto it = lines.begin() + i-3; it < lines.begin() + i+1; it++)
        {
            cmp += (*it)[j];
        }

        if (cmp == "SAMX") sum++;
    }

    //Look down
    if (i <= max_i-3)
    {
        cmp = "";
        for (auto it = lines.begin() + i; it < lines.begin() + i+4; it++)
        {
            cmp += (*it)[j];
        }

        if (cmp == "XMAS") sum++;
    }

    //Look left up
    if (i >=3 && j >= 3)
    {
        cmp = "";
        for (size_t k = 0; k < 4; k++)
        {
            cmp += lines[i-k][j-k];
        }

        if (cmp == "XMAS") sum++;
    }

    //Look right up
    if (i >=3 && j <= max_j-3)
    {
        cmp = "";
        for (size_t k = 0; k < 4; k++)
        {
            cmp += lines[i-k][j+k];
        }

        if (cmp == "XMAS") sum++;
    }

    //Look left down
    if (i <= max_i-3  && j >= 3)
    {
        cmp = "";
        for (size_t k = 0; k < 4; k++)
        {
            cmp += lines[i+k][j-k];
        }

        if (cmp == "XMAS") sum++;
    }


    //Look right down
    if (i <= max_i-3  && j <= max_j-3)
    {
        cmp = "";
        for (size_t k = 0; k < 4; k++)
        {
            cmp += lines[i+k][j+k];
        }

        if (cmp == "XMAS") sum++;
    }

    return sum;
}

int search_MAS(const std::vector<std::string>& lines,size_t i, size_t j)
{
    std::string diag_1 = "",diag_2 = "";

    int sum = 0;

    //Construct diags
    for (int k = -1; k<2; k++)
    {
        diag_1 += lines[i+k][j+k];
        diag_2 += lines[i+k][j-k];
    }

    if (diag_1 == "MAS" || diag_1 == "SAM")
    {
        if (diag_2 == "MAS" || diag_2 == "SAM")
        {
            sum++;
        }
    }

    return sum;
}


void part_one(const std::vector<std::string>& lines)
{
    int sum = 0;

    for (size_t i = 0; i < lines.size(); i++)
    {
        for (size_t j = 0; j < lines[0].size(); j++)
        {
            if (lines[i][j] == 'X')
            {
                sum += search(lines,i,j);
            }
        }
    }

    std::cout << "Part one: " << sum << "\n";
}

void part_two(const std::vector<std::string>& lines)
{
    int sum = 0;

    //Don't check for A's on the boundary
    for (size_t i = 1; i < lines.size()-1; i++)
    {
        for (size_t j = 1; j < lines[0].size()-1; j++)
        {
            if (lines[i][j] == 'A')
            {
                sum += search_MAS(lines,i,j);
            }
        }
    }

    std::cout << "Part two: " << sum << "\n";
}

int main()
{
    std::vector<std::string> lines = read_lines("input_1.txt");

    part_one(lines);
    part_two(lines);

    return 0;
}