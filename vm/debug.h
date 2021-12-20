#pragma once

#define IS_DEBUG true

#if IS_DEBUG
#define DEBUG(str) \
    std::cout << str << "\n";
#else
#define DEBUG(str)
#endif