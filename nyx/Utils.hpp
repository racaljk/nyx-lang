#pragma once
#include <any>
#include <deque>
#include <string>
#include "Nyx.hpp"

std::string valueToStdString(const nyx::Value& v);

std::string repeatString(int count, const std::string& str);

template <typename _DesireType, typename... _ArgumentType>
inline bool anyone(_DesireType k, _ArgumentType... args) {
    return ((args == k) || ...);
}

[[noreturn]] void panic(char const* const format, ...);

bool equalValue(const nyx::Value& a, const nyx::Value& b);
