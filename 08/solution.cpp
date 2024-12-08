#include "aoc_utils.hpp"

struct node_array
{
    std::vector<std::vector<bool>> array;
    size_t i_max;
    size_t j_max;
};

void init_node_array(const std::vector<std::string>& map,node_array& nodes)
{
    std::vector<bool> row = std::vector<bool> (map[0].size(),false);
    nodes.array = std::vector<std::vector<bool>> (map.size(),row);
    nodes.i_max = map.size();
    nodes.j_max = map[0].size();
}

void new_node(node_array& nodes, int i, int j, int k, int n)
{
    int diff_i = k-i;
    int diff_j = n-j;
    int i_index,j_index,k_index,n_index;
    bool j_lt_n = j < n;
    bool ij_bounds,kn_bounds;

    i_index = i - diff_i;
    j_index = j - diff_j;
    k_index = k + diff_i;
    n_index = n + diff_j;

    if (j_lt_n)
    {
        ij_bounds = (i_index>=0) && (j_index>=0);
        kn_bounds = (k_index < nodes.i_max) && (n_index < nodes.j_max);

    }
    else
    {
        ij_bounds = (i_index>=0) && (j_index< nodes.j_max);
        kn_bounds = (k_index < nodes.i_max) && (n_index>=0);
    }

    if (ij_bounds)
    {
        nodes.array[i_index][j_index] = true;
    }

    if (kn_bounds)
    {
        nodes.array[k_index][n_index] = true;
    }
}

void new_node_two(node_array& nodes, int i, int j, int k, int n)
{
    int diff_i = k-i;
    int diff_j = n-j;

    int i_index,j_index,k_index,n_index;

    bool j_lt_n = j < n;

    bool ij_bounds,kn_bounds;

    int l_max = std::min(nodes.i_max,nodes.j_max);

    for (int l = 0; l < l_max; l++)
    {
        i_index = i - l*diff_i;
        j_index = j - l*diff_j;
        k_index = k + l*diff_i;
        n_index = n + l*diff_j;

        if (j_lt_n)
        {
            ij_bounds = (i_index>=0) && (j_index>=0);
            kn_bounds = (k_index < nodes.i_max) && (n_index < nodes.j_max);

        }
        else
        {
            ij_bounds = (i_index>=0) && (j_index< nodes.j_max);
            kn_bounds = (k_index < nodes.i_max) && (n_index>=0);
        }

        if (ij_bounds)
        {
            nodes.array[i_index][j_index] = true;
        }

        if (kn_bounds)
        {
            nodes.array[k_index][n_index] = true;
        }

        if (!(ij_bounds || kn_bounds)) break;
    }
}

void insert_nodes(const std::vector<std::string>& map, node_array& nodes, size_t i, size_t j,bool part_one)
{
    char antenna = map[i][j];
    size_t n_start = j+1;

    for (size_t k = i; k < nodes.i_max; k++)
    {
        for (size_t n = n_start; n < nodes.j_max; n++)
        {
            if (antenna == map[k][n])
            {
                if (part_one)
                {
                    new_node(nodes,i,j,k,n);
                }
                else
                {
                    new_node_two(nodes,i,j,k,n);
                }
            }
        }
        n_start = 0;
    }
}

void find_nodes(const std::vector<std::string>& map,node_array& nodes,bool part_one)
{
    for (size_t i = 0; i < map.size(); i++)
    {
        for (size_t j = 0; j < map.size(); j++)
        {
            if (map[i][j] != '.')
            {
                insert_nodes(map,nodes,i,j,part_one);
            }
        }
    }
}

void part_one(const std::vector<std::string>& map)
{
    long sum = 0;

    node_array nodes;
    init_node_array(map,nodes);

    find_nodes(map,nodes,true);

    for (size_t i = 0; i < nodes.i_max; i++)
    {
        for (size_t j = 0; j < nodes.j_max; j++)
        {
            sum += nodes.array[i][j];
        }
    }

    //print_array(nodes.array);

    std::cout << "Part one: " << sum << "\n";
}

void part_two(const std::vector<std::string>& map)
{
    long sum = 0;

    node_array nodes;
    init_node_array(map,nodes);

    find_nodes(map,nodes,false);

    for (size_t i = 0; i < nodes.i_max; i++)
    {
        for (size_t j = 0; j < nodes.j_max; j++)
        {
            sum += nodes.array[i][j];
        }
    }

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