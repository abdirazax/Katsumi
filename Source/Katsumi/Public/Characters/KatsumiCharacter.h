#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KatsumiCharacter.generated.h"

UCLASS()
class KATSUMI_API AKatsumiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AKatsumiCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
