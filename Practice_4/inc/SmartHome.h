#pragma once
#include<string>

class Device
{
protected:
    std::string m_name = "Device";

public:
    Device() = default;

    virtual ~Device() = default;

    void poll()
    {
        std::cout << m_name << "\n";
    }
};

class Electric : public Device
{
public:
    Electric() : Device() {}

    ~Electric() override = default;
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