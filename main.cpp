#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include "src/NTCore.hpp"
using namespace NT::Core;

void printNetTraffic(std::ostream &stream, NetTraffic data);
std::string formatData(Data data);

int main()
{
    NetInterface wlp4s0("wlp4s0");
    printNetTraffic(std::cout, wlp4s0.getNetTraffic());
    return 0;
}

void printNetTraffic(std::ostream &stream, NetTraffic data)
{
    stream << "Input: " << formatData(data.input) << '\n'
           << "Output : " << formatData(data.output) << '\n';
}

std::string formatData(Data data)
{
    std::stringstream buffer;
    if (data.gb > 0)
        buffer << data.gb << '.' << std::round(data.mb / 10) << "gb";
    else if (data.mb > 0)
        buffer << data.mb << '.' << std::round(data.kb / 10) << "mb";
    else
        buffer << data.kb << "kb";
    return buffer.str();
}
