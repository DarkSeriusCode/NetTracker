#ifndef __NTCORE_TYPES_HPP
#define __NTCORE_TYPES_HPP

// ------------------------------------------------------------------------------

#include <cstdlib>

namespace NT
{
    namespace Core
    {
        struct Data;
        struct NetTraffic;
    }
}

// ------------------------------------------------------------------------------

struct NT::Core::Data
{
    Data();
    Data(std::size_t bytes);

    std::size_t gb;
    std::size_t mb;
    std::size_t kb;
};

// ------------------------------------------------------------------------------

struct NT::Core::NetTraffic
{    
    Data input;
    Data output;
};

#endif // __NTCORE_TYPES_HPP