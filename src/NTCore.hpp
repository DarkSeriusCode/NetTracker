#ifndef __NTCORE_HPP
#define __NTCORE_HPP

// ------------------------------------------------------------------------------

#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include "NTCoreTypes.hpp"

namespace NT 
{
    namespace Core
    {
        class NetInterface;
        class NetManager;
    } // namespace: Core
} // namespace: NT

// ------------------------------------------------------------------------------

// Represents network interface in /sys/class/net/...
class NT::Core::NetInterface
{
public:
    NetInterface();
    NetInterface(std::string name);

    NetTraffic getNetTraffic() const;
    std::string getPath() const { return path; }

    operator bool() const { return isValid; }

private:
    bool isValid;
    std::string path;

    std::string formatPath(std::string name);
};

// ------------------------------------------------------------------------------

// Class using for manage NetInterfaces
class NT::Core::NetManager
{
public:
    static std::vector<NetInterface>getInterfaces();

    static const std::string ITERFACES_PATH;
};

#endif // __NTCORE_HPP
