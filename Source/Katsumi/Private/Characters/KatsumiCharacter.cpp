#include "Characters/KatsumiCharacter.h"


// Sets default values
AKatsumiCharacter::AKatsumiCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AKatsumiCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AKatsumiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKatsumiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
