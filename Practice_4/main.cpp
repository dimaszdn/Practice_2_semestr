#include <iostream>
#include<SmartHome.h>
#include<vector>

Device* Factory1(DeviceType deviceType, DeviceList deviceList)
{
    Device* device = nullptr;
    switch (deviceType)
    {
        case DeviceType::ELECTRIC:
        {
            switch (deviceList.electric)
            {
                case ELECTRIC::NEVA_MT314:
                    device = new Neva_MT314;
                    break;
            }
            break;
        }
        case DeviceType::SIGNAL:
            switch (deviceList.signal)
            {
                case SIGNAL::REALLAB_NL_16HV:
                    device = new Reallab_NL_16HV;
                    break;
            }
            break;
        case DeviceType::HEATING:
            switch (deviceList.heating)
            {
                case HEATING::Ouman_S203:
                    device = new Ouman_S203;
                    break;
            }
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
        devices.push_back(Factory1(DeviceType::ELECTRIC, {ELECTRIC::MERCURY_230}));

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
