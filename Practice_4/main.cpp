#include <iostream>
#include<SmartHome.h>
#include<vector>

int main()
{
    std::vector<Device*> devices;
    Device* d1 = new Neva_MT314;
    Device* d2 = new Reallab_NL_16HV;
    Device* d3 = new Ouman_S203;
    devices.push_back(d1);
    devices.push_back(d2);
    devices.push_back(d3);

    for (Device* device : devices)
        device->poll();

    for (int i = 0; i < devices.size(); ++i)
        delete devices[i];

    return 0;
}
