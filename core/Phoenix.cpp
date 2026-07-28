#include "Phoenix.h"

#include <mod/logger.h>

Phoenix& Phoenix::Instance()
{
    static Phoenix instance;
    return instance;
}

bool Phoenix::Initialize()
{
    logger->Info("====================================");
    logger->Info(" Phoenix Engine ARM64 Initializing");
    logger->Info("====================================");

    return true;
}

void Phoenix::Shutdown()
{
    logger->Info("Phoenix Engine Shutdown");
}
