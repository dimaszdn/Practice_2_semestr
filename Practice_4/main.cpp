#include <iostream>
#include<SmartHome.h>
#include<vector>

Device* Factory(ElectricList electricList)
{
    Device* device = nullptr;
    switch (electricList)
    {
        case ElectricList::NEVA_MT314:
            device = new Neva_MT314;
            break;
    }
    if (device != nullptr)
        return device;
    throw std::logic_error("There is no such device!");
}

Device* Factory(SignalList signalList)
{
    Device* device = nullptr;
    switch (signalList)
    {
        case SignalList::REALLAB_NL_16HV:
            device = new Reallab_NL_16HV;
            break;
    }
    if (device != nullptr)
        return device;
    throw std::logic_error("There is no such device!");
}

Device* Factory(HeatingList heatingList)
{
    Device* device = nullptr;
    switch (heatingList)
    {
        case HeatingList::Ouman_S203:
            device = new Ouman_S203;
            break;
    }
    if (device != nullptr)
        return device;
    throw std::logic_error("There is no such device!");
}

int main()
{
    try
    {
        std::vector<Device*> devices;
        devices.push_back(Factory(ElectricList::NEVA_MT314));
        devices.push_back(Factory(SignalList::REALLAB_NL_16HV));
        devices.push_back(Factory(HeatingList::Ouman_S203));

        for (Device* device : devices)
            device->poll();

        for (int i = 0; i < devices.size(); ++i)
            delete devices[i];
    }
    catch(std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
