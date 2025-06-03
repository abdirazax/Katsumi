#include "KatsumiCore.h"
#include "Modules/ModuleManager.h"

#include "Log.h"

void FKatsumiCore::StartupModule()
{
	UE_LOG(LogKatsumiCore, Log, TEXT("KatsumiCore module starting up"));
}

void FKatsumiCore::ShutdownModule()
{
	UE_LOG(LogKatsumiCore, Log, TEXT("KatsumiCore module shutting down"));
}

IMPLEMENT_PRIMARY_GAME_MODULE(FKatsumiCore, KatsumiCore, "KatsumiCore");
