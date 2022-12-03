#include "NTCore.hpp"
using namespace NT::Core;

// ------------------------------------------------------------------------------
// Data

Data::Data(std::size_t bytes)
    : kb(0), mb(0), gb(0)
{
    kb = bytes / 1000;
    mb = kb / 1000;
    gb = mb / 1000;

    kb -= mb * 1000;
    mb -= gb * 1000;
}


// ------------------------------------------------------------------------------
// NetInterface

NetInterface::NetInterface()
    : isValid(false) {}

NetInterface::NetInterface(std::string name)
    : path(formatPath(name)), isValid(true)
{
    // Checking for valid by opening any file
    std::ifstream temp{path + "tx_bytes"};
    if (!temp)
        isValid = false;
}

NetTraffic NetInterface::getNetTraffic() const
{
    std::ifstream rx_bytes{path + "rx_bytes"}; // input bytes
    std::ifstream tx_bytes{path + "tx_bytes"}; // output bytes
    std::size_t input_bytes, output_bytes;

    if (!tx_bytes || !rx_bytes)
        return NetTraffic{0, 0};

    rx_bytes >> input_bytes;
    tx_bytes >> output_bytes;

    rx_bytes.close();
    tx_bytes.close();

    return NetTraffic{Data{input_bytes}, Data{output_bytes}};
}

std::string NetInterface::formatPath(std::string name)
{
    std::string buffer = NetManager::ITERFACES_PATH;
    buffer += ("/" + name + "/statistics/"); 
    return buffer;
}

// ------------------------------------------------------------------------------
// NetManager

const std::string NetManager::ITERFACES_PATH = "/sys/class/net";

std::vector<NetInterface> NetManager::getInterfaces()
{
    std::vector<NetInterface> interfs;
    DIR *interf_dir = opendir(ITERFACES_PATH.c_str());
    struct dirent *entry;

    if (!interf_dir) return interfs;

    while ( (entry = readdir(interf_dir)) != NULL )
    {
        if (std::string(entry->d_name).at(0) == '.') continue;
        interfs.push_back(NetInterface(entry->d_name));
    }

    closedir(interf_dir);
    return interfs;
}

