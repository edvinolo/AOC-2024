// #include "aoc_utils.hpp"
#include "src/lib_aoc.hpp"

int main(int argc, char** argv){

    std::string input(argv[1]);
    if (input == "all")
    {
        run_all();
    }
    else
    {
        run_single_day(input);
    }

    return 0;
}
