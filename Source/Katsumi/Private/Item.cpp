#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ASASA AAAAAA!!!!!!!!!!!! %s"), *GetName());

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, FString("Item OnScreen Message!"));
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
