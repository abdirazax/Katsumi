#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "KatsumiAnimInstance.generated.h"


class UCharacterMovementComponent;
class AKatsumiCharacter;

UCLASS()
class KATSUMI_API UKatsumiAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly, Category = "Character")
	TObjectPtr<AKatsumiCharacter> KatsumiCharacter;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	TObjectPtr<UCharacterMovementComponent> KatsumiCharacterMovement;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed = 0.0f;
};
