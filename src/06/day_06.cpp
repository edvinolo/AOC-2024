#include "day_06.hpp"
namespace day_06{

struct past_visit
{
    std::vector<bool> dirs;
};

size_t dir_lookup(std::pair<int,int> dir)
{
    if (dir.first == 1 && dir.second == 0)
    {
        return 0;
    }

    else if (dir.first == -1 && dir.second == 0)
    {
        return 1;
    }

    else if (dir.first == 0 && dir.second == 1)
    {
        return 2;
    }

    else
    {
        return 3;
    }

}


void pad_map(std::vector<std::string>& map)
{
    for (size_t i = 0; i < map.size(); i++)
    {
        map[i].push_back('.');
        map[i].insert(map[i].begin(),'.');
    }

    std::string padding  = std::string(map[0].size(),'.');
    map.insert(map.begin(),padding);
    map.push_back(padding);
}

void rotate(std::pair<int,int>& dir)
{
    dir = {dir.second,-dir.first};
}

std::pair<size_t,size_t> find_start(const std::vector<std::string>& map)
{
    for (size_t k = 0; k < map.size(); k++)
    {
        for (size_t n = 0; n < map[0].size(); n++)
        {
            if (map[k][n] == '^')
            {
                return std::pair<size_t,size_t>(k,n);
            }
        }
    }

    return std::pair<size_t,size_t>(0,0);
}

std::vector<std::vector<bool>> traverse_map(const std::vector<std::string>& map)
{
    size_t i,j;
    std::pair<size_t,size_t> start;
    std::pair<int,int> dir = {-1,0};
    std::vector<bool> visit_row = std::vector<bool> (map[0].size(),false);
    std::vector<std::vector<bool>> visited = std::vector<std::vector<bool>> (map.size(),visit_row);

    start = find_start(map);
    i = start.first;
    j = start.second;

    while((0 < i && i < map.size()-1) && (0 < j && j < map[0].size()-1))
    {
        visited[i][j] = true;

        while (map[i+dir.first][j+dir.second] == '#')
        {
            rotate(dir);
        }

        i += dir.first;
        j += dir.second;
    }

    return visited;
}

bool traverse_map_part_two(const std::vector<std::string>& map,const std::pair<size_t,size_t> start, std::vector<std::vector<bool>>& visited, std::vector<std::vector<past_visit>>& past_visits)
{
    size_t i,j;
    std::pair<int,int> dir = {-1,0};
    size_t dir_index = 0;

    i = start.first;
    j = start.second;

    while((0 < i && i < map.size()-1) && (0 < j && j < map[0].size()-1))
    {
        visited[i][j] = true;
        dir_index = dir_lookup(dir);
        if (past_visits[i][j].dirs[dir_index])
        {
            return true;
        }
        past_visits[i][j].dirs[dir_index] = true;


        while (map[i+dir.first][j+dir.second] == '#')
        {
            rotate(dir);
        }

        i += dir.first;
        j += dir.second;
    }

    return false;
}

std::vector<std::vector<bool>> setup_visited(const std::vector<std::string>& map)
{
    std::vector<bool> visit_row = std::vector<bool> (map[0].size(),false);
    std::vector<std::vector<bool>> visited = std::vector<std::vector<bool>> (map.size(),visit_row);
    return visited;
}

std::vector<std::vector<past_visit>> setup_past_visits(const std::vector<std::string>& map)
{
    past_visit dummy;
    dummy.dirs = std::vector<bool> (4,false);
    std::vector<past_visit> past_row = std::vector<past_visit> (map[0].size(),dummy);
    std::vector<std::vector<past_visit>> past_visits = std::vector<std::vector<past_visit>>(map.size(),past_row);

    return past_visits;
}

void clear_visits(std::vector<std::vector<bool>>& visited, std::vector<std::vector<past_visit>>& past_visits)
{
    for (size_t i = 1; i < visited.size()-1; i++)
    {
        for (size_t j = 1; j < visited[0].size()-1; j++)
        {
            visited[i][j] = false;
            for (size_t k = 0; k < 4; k++)
            {
                past_visits[i][j].dirs[k] = false;
            }
        }
    }
}

void part_one(const std::vector<std::string>& map)
{
    int sum = 1;

    std::vector<std::vector<bool>> visited = traverse_map(map);

    for (size_t k = 0; k < visited.size(); k++)
    {
        for (size_t n = 0; n < visited[0].size(); n++)
        {
            sum += visited[k][n];
        }
    }

    std::cout << "Part one: " << sum << "\n";
}

void part_two(std::vector<std::string>& map)
{
    int sum = 0;
    bool loop;
    //Iterate over possible obstacle locations and detect loops
    //Construct array that for each location holds the previous dir values that this location was visited with.
    //If we visit the same location with the same direction then we are in a loop and can increment the counter and stop.
    //If we exit the boundary we are not in a loop.
    std::pair<size_t,size_t> start;
    start = find_start(map);

    std::vector<std::vector<bool>> visited = setup_visited(map);
    std::vector<std::vector<past_visit>> past_visits = setup_past_visits(map);

    std::vector<std::vector<bool>> visited_part_one = traverse_map(map);

    for (size_t i = 1; i < map.size()-1; i++)
    {
        for (size_t j = 1; j < map[0].size()-1; j++)
        {
            if (map[i][j] == '.' && visited_part_one[i][j])
            {
                map[i][j] = '#';
                loop = traverse_map_part_two(map,start,visited,past_visits);
                sum += loop;
                map[i][j] = '.';
                clear_visits(visited,past_visits);
            }
        }
    }

    std::cout << "Part two: " << sum << "\n";
}

void run()
{
    std::vector<std::string> lines = read_lines("../input/06/input_1.txt");

    pad_map(lines);

    part_one(lines);
    part_two(lines);
}

}