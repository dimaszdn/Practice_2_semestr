#pragma once
#include<string>

enum class ElectricList
{
    NEVA_MT314,
    MERCURY_230,
    ENERGOMERA_CE308
};
enum class SignalList
{
    REALLAB_NL_16HV,
    PRIBORELECTRO_PRE_16,
    ENERGOSERVIS_EHMB_1_24
};
enum class HeatingList
{
    Ouman_S203,
    OVEN_TPM232
};

class Device
{
protected:
    std::string m_name = "Device";

public:
    Device() = default;

    virtual ~Device() = default;

    virtual void poll()
    {
        std::cout << m_name << "\n";
    }
};

class Electric : public Device
{
public:
    Electric() : Device() {}

    ~Electric() override = default;

    void poll() override
    {
        std::cout << m_name << " " << 1 << "\n";
    }
};

class Neva_MT314 : public Electric
{
public:
    Neva_MT314() : Electric()
    {
        m_name = "Neva_MT314";
    }
    ~Neva_MT314() override = default;
};

class Signal : public Device
{
public:
    Signal() : Device() {}

    ~Signal() override = default;

    void poll() override
    {
        std::cout << m_name << " " << 2 << "\n";
    }
};

class Reallab_NL_16HV : public Signal
{
public:
    Reallab_NL_16HV() : Signal()
    {
        m_name = "Reallab_NL_16HV";
    }
    ~Reallab_NL_16HV() override = default;
};

class Heating : public Device
{
public:
    Heating() : Device() {}

    ~Heating() override = default;

    void poll() override
    {
        std::cout << m_name << " " << 3 << "\n";
    }
};

class Ouman_S203 : public Heating
{
public:
    Ouman_S203() : Heating()
    {
        m_name = "Ouman_S203";
    }
    ~Ouman_S203() override = default;
};