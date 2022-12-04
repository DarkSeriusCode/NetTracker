#include "NTCoreTypes.hpp"
using namespace NT::Core;

// ------------------------------------------------------------------------------
// Data

Data::Data()
    : gb(0), mb(0), kb(0) {}

Data::Data(std::size_t bytes)
    : kb(0), mb(0), gb(0)
{
    kb = bytes / 1000;
    mb = kb / 1000;
    gb = mb / 1000;

    kb -= mb * 1000;
    mb -= gb * 1000;
}