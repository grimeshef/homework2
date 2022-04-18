//
// Created by ars on 15.04.22.
//

#include "vector"
#include "string"


#pragma once

std::vector<std::string> split(const std::string &str, char d);

//std::vector<std::vector<std::string>> filter(const std::vector<std::vector<std::string>>& ip_pool,
//                                             const int &filter_number1,
//                                             const int &filter_number2,
//                                             const int &filter_number3,
//                                             const int &filter_number4);
//
//std::vector<std::vector<std::string>> filter(std::vector<std::vector<std::string>> ip_pool,
//                                             const int &filter_number1,
//                                             const int &filter_number2,
//                                             const int &filter_number3);
//
//std::vector<std::vector<std::string>> filter(std::vector<std::vector<std::string>> ip_pool,
//                                             const int &filter_number1,
//                                             const int &filter_number2);
//
//std::vector<std::vector<std::string>> filter(std::vector<std::vector<std::string>> ip_pool,
//                                             const int &filter_number);

std::vector<std::vector<std::string>> filter(const std::vector<std::vector<std::string>>& ip_pool);