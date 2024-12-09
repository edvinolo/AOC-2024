#include "day_05.hpp"

namespace day_05
{

struct page
{
    int number;
    std::vector<int> less_than;

    friend bool operator<(const page& left, const page& right)
    {
        for (size_t i = 0; i < left.less_than.size(); i++)
        {
            if(right.number == left.less_than[i])
            {
                return true;
            }
        }

        for (size_t i = 0; i < right.less_than.size(); i++)
        {
            if (left.number == right.less_than[i])
            {
                return false;
            }
        }

        return false; // If none of the pages appears in the other's less_than, then consider them equal.
    }
};

struct update
{
    std::vector<std::shared_ptr<page>> pages;
};

bool sorted(const update& update)
{
    for (size_t i = 0; i < update.pages.size()-1; i++)
    {
        for (size_t j = i+1; j < update.pages.size(); j++)
        {
            if (!(*update.pages[i] < *update.pages[j]))
            {
                return false;
            }
        }
    }

    return true;
}

std::vector<std::shared_ptr<page>> construct_pages(const std::vector<std::string>& rules)
{
    int max_size = 100;
    std::vector<std::shared_ptr<page>> pages (max_size); //Page limit is 100;
    std::vector<int> numbers;

    for (int i = 0; i < max_size; i++)
    {
        pages[i] = std::shared_ptr<page> (new page);
        pages[i]->number = i;
    }

    for (auto it = rules.begin(); it < rules.end(); it++)
    {
        numbers = extract_int(*it);
        pages[numbers[0]]->less_than.push_back(numbers[1]);
    }

    return pages;
}

std::vector<update> construct_sorted_updates(const std::vector<std::shared_ptr<page>>& pages, const std::vector<std::string>& updates)
{
    std::vector<update> sorted_updates;
    std::vector<int> numbers;
    update current_update;

    for (auto it = updates.begin(); it < updates.end(); it++)
    {
        current_update = {};
        numbers = extract_int(*it);
        for (size_t i = 0; i < numbers.size(); i++)
        {
            current_update.pages.push_back(pages[numbers[i]]);
        }

        if (!sorted(current_update))
        {
            merge_sort_ptr(current_update.pages);
            sorted_updates.push_back(current_update);
        }
    }

    return sorted_updates;
}

std::vector<update> find_sorted_updates(const std::vector<std::shared_ptr<page>>& pages, const std::vector<std::string>& updates)
{
    std::vector<update> sorted_updates;
    std::vector<int> numbers;
    update current_update;

    for (auto it = updates.begin(); it < updates.end(); it++)
    {
        current_update = {};
        numbers = extract_int(*it);
        for (size_t i = 0; i < numbers.size(); i++)
        {
            current_update.pages.push_back(pages[numbers[i]]);
        }

        if(sorted(current_update))
        {
            sorted_updates.push_back(current_update);
        }
    }

    return sorted_updates;
}

void separate_parts(const std::vector<std::string>& lines, std::vector<std::string>& rules, std::vector<std::string>& updates)
{
    size_t split_index = 0;
    for (size_t i = 0; i < lines.size(); i++)
    {
        if (lines[i] == "")
        {
            split_index = i;
            break;
        }
    }

    rules = std::vector<std::string> (lines.begin(),lines.begin() + split_index);
    updates = std::vector<std::string> (lines.begin() + split_index + 1,lines.end());
}

void part_one(const std::vector<update>& updates)
{
    int sum = 0;
    size_t middle;
    for (auto it = updates.begin(); it < updates.end(); it++)
    {
        middle = it->pages.size()/2;
        sum += it->pages[middle]->number;
    }

    std::cout << "Part one: " << sum << "\n";
}

void part_two(const std::vector<update>& updates)
{
    int sum = 0;

    size_t middle;
    for (auto it = updates.begin(); it < updates.end(); it++)
    {
        middle = it->pages.size()/2;
        sum += it->pages[middle]->number;
    }

    std::cout << "Part two: " << sum << "\n";
}

void run()
{
    std::vector<std::string> lines = read_lines("../input/05/input_1.txt");
    std::vector<std::string> rules,updates;

    separate_parts(lines,rules,updates);

    std::vector<std::shared_ptr<page>> pages = construct_pages(rules);
    std::vector<update> sorted_updates = find_sorted_updates(pages,updates);
    std::vector<update> fixed_updates = construct_sorted_updates(pages,updates);

    part_one(sorted_updates);
    part_two(fixed_updates);
}

}