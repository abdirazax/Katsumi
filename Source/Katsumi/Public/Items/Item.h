#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class KATSUMI_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigonometry Parameters")
	float Amplitude = 0.25f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trigonometry Parameters")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure, Category = "Trigonometry Parameters")
	float TransformedSin() const;

	UFUNCTION(BlueprintPure, Category = "Trigonometry Parameters")
	float TransformedCos() const;

	template <typename T>
	T Avg(T A, T B);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	float RunningTime = 0.f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;
};

template <typename T>
T AItem::Avg(T A, T B)
{
	return (A + B) / 2;
}
