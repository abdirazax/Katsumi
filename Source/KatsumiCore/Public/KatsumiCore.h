#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FKatsumiCore : public IModuleInterface
{
public:
	static inline FKatsumiCore& Get()
	{
		return FModuleManager::LoadModuleChecked<FKatsumiCore>("KatsumiCore");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("KatsumiCore");
	}

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
