#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "KatsumiCharacter.generated.h"

class UMetaHumanComponentUE;
class ULODSyncComponent;
class UGroomComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class KATSUMI_API AKatsumiCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AKatsumiCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool bCanMove = true;	

protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputMappingContext> CharacterMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MetaHuman)
	TObjectPtr<USkeletalMeshComponent> ClassyClothes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MetaHuman)
	TObjectPtr<USkeletalMeshComponent> Shoes;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void Jump() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> ViewCamera;
	UPROPERTY(VisibleAnywhere, Category = Hair)
	TObjectPtr<UGroomComponent> Hair;
	UPROPERTY(VisibleAnywhere, Category = Hair)
	TObjectPtr<UGroomComponent> Eyebrows;
	UPROPERTY(VisibleAnywhere, Category = Hair)
	TObjectPtr<UGroomComponent> Eyelashes;
	UPROPERTY(VisibleAnywhere, Category = MetaHuman)
	TObjectPtr<USkeletalMeshComponent> Face;
	
	UPROPERTY(VisibleAnywhere, Category = MetaHuman)
	TObjectPtr<UMetaHumanComponentUE> MetaHumanComponentUE;
	UPROPERTY(VisibleAnywhere, Category = MetaHuman)
	TObjectPtr<ULODSyncComponent> LODSync;
};
