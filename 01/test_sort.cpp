#include <stdio.h>
#include "merge_sort.hpp"
#include <vector>
#include "aoc_utils.hpp"


int main()
{
    std::vector<int> a = {1,5,2,4,3};

    print_vec(a);
    merge_sort(a);
    print_vec(a);

    return 0;
}