#include "day_09.hpp"
namespace day_09
{

struct file
{
    size_t id;
    size_t len;
};

struct block
{
    std::shared_ptr<file> owner;
};

struct empty_block
{
    size_t loc;
    size_t capacity;
};

std::vector<empty_block> find_empty_blocks(const std::vector<block>& filesystem)
{
    std::vector<empty_block> empty_blocks;
    empty_block current_block;

    for (size_t i = 0; i < filesystem.size(); i++)
    {
        if (filesystem[i].owner == NULL)
        {
            current_block.loc = i;
            current_block.capacity = 0;
            while (i < filesystem.size() && filesystem[i].owner == NULL)
            {
                current_block.capacity++;
                i++;
            }
            empty_blocks.push_back(current_block);
        }
    }
    return empty_blocks;
}

std::vector<block> init_filesystem(const std::string& map)
{

    std::vector<block> file_system;
    block filled_block, null_block;
    std::shared_ptr<file> ptr;
    size_t id = 0;
    size_t len = 0;

    null_block.owner = NULL;

    for (size_t i = 0; i < map.size(); i++)
    {
        if (i%2 == 0)
        {
            ptr = std::shared_ptr<file> (new file);
            ptr->id = id;
            ptr->len = (long) (map[i] - '0');

            for (size_t j = 0; j < ptr->len; j++)
            {
                filled_block.owner = ptr;
                file_system.push_back(filled_block);
            }
            id++;
        }

        else
        {
            len = (long) (map[i] - '0');
            for (size_t j = 0; j < len; j++)
            {
                file_system.push_back(null_block);
            }
        }
    }

    return file_system;
}

void print_filesystem(const std::vector<block>& filesystem)
{
    for (size_t i = 0; i < filesystem.size(); i++)
    {
        if (filesystem[i].owner == NULL)
        {
            std::cout << ".";
        }
        else
        {
            std::cout << filesystem[i].owner->id;
        }
    }
    std::cout << "\n";
}

void fragment_filesystem(std::vector<block>& filesystem)
{
    size_t i,j;

    i = filesystem[0].owner->len; //know that first empty block starts here
    j = filesystem.size()-1;

    while (i<j)
    {
        if (filesystem[j].owner != NULL)
        {
            while(filesystem[i].owner != NULL)
            {
                i++;
            }

            if(i<j)
            {
                filesystem[i].owner = filesystem[j].owner;
                filesystem[j].owner = NULL;
            }
        }
        j--;
    }
}

void move_file(std::vector<block>& filesystem, size_t i_begin, size_t j_begin, size_t len)
{
    for (size_t l = 0; l < len; l++)
    {
        filesystem[i_begin + l].owner.swap(filesystem[j_begin + l].owner);
    }
}

void move_files(std::vector<block>& filesystem)
{
    size_t i_begin;
    size_t j_begin,j_end;
    size_t current_file_id;

    std::vector<empty_block> empty_blocks = find_empty_blocks(filesystem);

    j_end = filesystem.size()-1;

    while(!filesystem[j_end].owner)
    {
        j_end--;
    }

    current_file_id = filesystem[j_end].owner->id;

    while(current_file_id > 0)
    {
        if (filesystem[j_end].owner != NULL)
        {
            j_begin = j_end - filesystem[j_end].owner->len+1;
            current_file_id = filesystem[j_end].owner->id;

            for (size_t i = 0; i < empty_blocks.size(); i++)
            {
                if (j_begin <= empty_blocks[i].loc)
                {
                    break;
                }
                else if(empty_blocks[i].capacity >= filesystem[j_end].owner->len)
                {
                    i_begin = empty_blocks[i].loc;
                    move_file(filesystem,i_begin,j_begin,filesystem[j_end].owner->len);
                    empty_blocks[i].capacity -= filesystem[i_begin].owner->len;
                    empty_blocks[i].loc += filesystem[i_begin].owner->len;
                    break;
                    //In principle should also add a new empty block in the previous location of file, but not required by the problem.
                }
            }
            j_end = j_begin-1;
        }

        else
        {
            j_end--;
        }
    }
}

long checksum(const std::vector<block>& filesystem)
{
    long result = 0;

    for (size_t i = 0; i < filesystem.size(); i++)
    {
        if (filesystem[i].owner != NULL)
        {
            result += i*filesystem[i].owner->id;
        }
    }

    return result;
}

void part_one(std::vector<block>& filesystem)
{
    long sum = 0;
    fragment_filesystem(filesystem);

    sum = checksum(filesystem);

    std::cout << "Part one: " << sum << "\n";
}

void part_two(std::vector<block>& filesystem)
{
    long sum = 0;

    move_files(filesystem);
    sum = checksum(filesystem);

    std::cout << "Part two: " << sum << "\n";
}

void run()
{
    std::string line = read_lines("../input/09/input_1.txt")[0];

    std::vector<block> filesystem = init_filesystem(line);

    part_one(filesystem);

    std::vector<block> filesystem_2 = init_filesystem(line);
    part_two(filesystem_2);
}

}