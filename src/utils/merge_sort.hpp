#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <stdio.h>
#include <memory>

template <typename T>
void top_down_merge(std::vector<T>& b,std::vector<T>& a,size_t begin,size_t middle,size_t end)
{
    size_t i = begin;
    size_t j = middle;

    for (size_t k=begin; k<end; k++)
    {
        if (i < middle && (j >= end || a[i] < a[j]))
        {
            b[k] = a[i];
            i++;
        }

        else
        {
            b[k] = a[j];
            j++;
        }
    }
};

template <typename T>
void top_down_split_merge(std::vector<T>& b,std::vector<T>& a,size_t begin,size_t end)
{
    if (end-begin <= 1)
    {
        return;
    }

    size_t middle = (end+begin)/2;

    top_down_split_merge(a,b,begin,middle);
    top_down_split_merge(a,b,middle,end);

    top_down_merge(b,a,begin,middle,end);
};

template <typename T>
void merge_sort(std::vector<T>& a)
{
    std::vector<T> b(a);
    top_down_split_merge(a,b,0,a.size());
};

template <typename T>
void top_down_merge_ptr(std::vector<std::shared_ptr<T>>& b,std::vector<std::shared_ptr<T>>& a,size_t begin,size_t middle,size_t end)
{
    size_t i = begin;
    size_t j = middle;

    for (size_t k=begin; k<end; k++)
    {
        if (i < middle && (j >= end || *a[i] < *a[j]))
        {
            b[k] = a[i];
            i++;
        }

        else
        {
            b[k] = a[j];
            j++;
        }
    }
};

template <typename T>
void top_down_split_merge_ptr(std::vector<std::shared_ptr<T>>& b,std::vector<std::shared_ptr<T>>& a,size_t begin,size_t end)
{
    if (end-begin <= 1)
    {
        return;
    }

    size_t middle = (end+begin)/2;

    top_down_split_merge_ptr(a,b,begin,middle);
    top_down_split_merge_ptr(a,b,middle,end);

    top_down_merge_ptr(b,a,begin,middle,end);
};

template <typename T>
void merge_sort_ptr(std::vector<std::shared_ptr<T>>& a)
{
    std::vector<std::shared_ptr<T>> b(a);
    top_down_split_merge_ptr(a,b,0,a.size());
};

#endif //MERGE_SORT_HPP