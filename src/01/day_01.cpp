#include "day_01.hpp"

namespace day_01
{

void part_one(const columns<int>& input_cols)
{
    std::vector<int> diff =  vec_op<int,std::minus<int>>(input_cols.right,input_cols.left);
    int result = abs_sum(diff);
    std::cout << "Part one: " << result << std::endl;
}

int similarity_score(const columns<int>& input_cols)
{
    int score = 0;

    for (size_t i = 0; i < input_cols.size; i++)
    {
        for (size_t j = 0; j < input_cols.size; j++)
        {
            if (input_cols.left[i] == input_cols.right[j])
            {
                score += input_cols.left[i];
            }
        }
    }

    return score;
}

void part_two(const columns<int>& input_cols)
{
    int result = similarity_score(input_cols);
    std::cout << "Part two: " << result << std::endl;
}

void run()
{
    columns<int> input_cols = read_col_int("../input/01/input_1.txt");

    merge_sort(input_cols.left);
    merge_sort(input_cols.right);

    part_one(input_cols);
    part_two(input_cols);
}

}