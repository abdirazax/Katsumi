#include "Characters/KatsumiAnimInstance.h"
#include "Characters/KatsumiCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UKatsumiAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	KatsumiCharacter = Cast<AKatsumiCharacter>(TryGetPawnOwner());
	if (KatsumiCharacter)
	{
		KatsumiCharacterMovement = KatsumiCharacter->GetCharacterMovement();
	}
}

void UKatsumiAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (KatsumiCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(KatsumiCharacterMovement->Velocity);
		bIsFalling = KatsumiCharacterMovement->IsFalling();
	}
}
