#include "day_10.hpp"
namespace day_10
{

struct pos
{
    size_t i;
    size_t j;

    friend bool operator==(const pos& left, const pos& right)
    {
        if (left.i == right.i && left.j == right.j)
        {
            return true;
        }

        return false;
    }
};

void pad_map(std::vector<std::vector<int>>& map)
{
    for (size_t i = 0; i < map.size(); i++)
    {
        map[i].push_back(0);
        map[i].insert(map[i].begin(),0);
    }

    std::vector<int> padding  = std::vector<int>(map[0].size(),0);
    map.insert(map.begin(),padding);
    map.push_back(padding);
}


void search(const std::vector<std::vector<int>>& map,size_t i, size_t j, std::vector<pos>& ends)
{
    if (map[i][j] == 9)
    {
        pos p ;
        p.i = i;
        p.j = j;

        for (size_t i = 0; i < ends.size(); i++)
        {
            if (p == ends[i])
            {
                return;
            }
        }

        ends.push_back(p);
        return;
    }

    if (map[i-1][j]-1 == map[i][j])
    {
        search(map,i-1,j,ends);
    }

    if (map[i][j-1]-1 == map[i][j])
    {
        search(map,i,j-1,ends);
    }

    if (map[i+1][j]-1 == map[i][j])
    {
        search(map,i+1,j,ends);
    }

    if (map[i][j+1]-1 == map[i][j])
    {
        search(map,i,j+1,ends);
    }

    return;
}


void search_2(const std::vector<std::vector<int>>& map,size_t i, size_t j, long& ends)
{
    if (map[i][j] == 9)
    {
        ends++;
        return;
    }

    if (map[i-1][j]-1 == map[i][j])
    {
        search_2(map,i-1,j,ends);
    }

    if (map[i][j-1]-1 == map[i][j])
    {
        search_2(map,i,j-1,ends);
    }

    if (map[i+1][j]-1 == map[i][j])
    {
        search_2(map,i+1,j,ends);
    }

    if (map[i][j+1]-1 == map[i][j])
    {
        search_2(map,i,j+1,ends);
    }

    return;
}

long find_trails(const std::vector<std::vector<int>>& map)
{
    std::vector<pos> ends;
    long scores = 0;

    for (size_t i = 1; i < map.size()-1; i++)
    {
        for (size_t j = 1; j < map[0].size()-1; j++)
        {
            if (map[i][j] == 0)
            {
                search(map,i,j,ends);
                scores += ends.size();
                ends.clear();
            }
        }
    }

    return scores;
}

long find_trails_2(const std::vector<std::vector<int>>& map)
{
    long scores = 0;

    for (size_t i = 1; i < map.size()-1; i++)
    {
        for (size_t j = 1; j < map[0].size()-1; j++)
        {
            if (map[i][j] == 0)
            {
                search_2(map,i,j,scores);
            }
        }
    }

    return scores;
}

void part_one(const std::vector<std::vector<int>>& map)
{
    long sum = 0;

    sum = find_trails(map);

    std::cout << "Part one: " << sum << "\n";
}

void part_two(const std::vector<std::vector<int>>& map)
{
    long sum = 0;

    sum = find_trails_2(map);

    std::cout << "Part two: " << sum << "\n";
}

void run()
{
    std::vector<std::string> lines = read_lines("../input/10/input_1.txt");
    std::vector<std::vector<int>> map = char_to_int(lines);

    pad_map(map);

    part_one(map);
    part_two(map);
}

}