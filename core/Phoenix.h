#pragma once

class Phoenix
{
public:
    static Phoenix& Instance();

    bool Initialize();
    void Shutdown();

private:
    Phoenix() = default;
    ~Phoenix() = default;

    Phoenix(const Phoenix&) = delete;
    Phoenix& operator=(const Phoenix&) = delete;
};
