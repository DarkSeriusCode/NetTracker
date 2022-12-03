#ifndef __NTCORE_HPP
#define __NTCORE_HPP

// ------------------------------------------------------------------------------

#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <cstring>

namespace NT {
    namespace Core
    {
        struct Data;
        struct NetTraffic;
        class NetInterface;
        class NetManager;
    } // namespace: Core
} // namespace: NT

// ------------------------------------------------------------------------------

struct NT::Core::Data
{
    Data()
        : gb(0), mb(0), kb(0) {}
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
