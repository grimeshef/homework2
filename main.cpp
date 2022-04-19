//
// Created by Alexandr on 15.04.22.
//
#include "iostream"
#include "ip_filter.h"



int main(int argc, char const *argv[])
{
    try
    {
        std::vector<std::vector<std::string>> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            if (line.empty()) break;
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort
        decltype(ip_pool) ip_sorted = filter(ip_pool);
        decltype(ip_pool) ip_filtered_first_ip_part = filter(ip_pool, 1);
        decltype(ip_pool) ip_filtered_first_and_second_ip_parts = filter(ip_pool, 46, 70);
        decltype(ip_pool) ip_filtered_any_ip_part = filter_any(ip_pool, 46);

        for(const auto & ip : ip_sorted)
        {
            for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
            {
                if (ip_part != ip.cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        for(const auto & ip : ip_filtered_first_ip_part)
        {
            for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
            {
                if (ip_part != ip.cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        for(const auto & ip : ip_filtered_first_and_second_ip_parts)
        {
            for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
            {
                if (ip_part != ip.cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        for(const auto & ip : ip_filtered_any_ip_part)
        {
            for(auto ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part)
            {
                if (ip_part != ip.cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
