#include "Characters/KatsumiCharacter.h"

#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GroomComponent.h"
#include "MetaHumanComponentUE.h"
#include "Components/LODSyncComponent.h"


// Sets default values
AKatsumiCharacter::AKatsumiCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;
	SpringArm->SetRelativeRotation(FRotator(-30.f, 0.f, 0.0f));

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);

	Face = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Face"));
	Face->SetupAttachment(GetMesh(), GetMesh()->GetFName());
	Face->bIncludeComponentLocationIntoBounds = true;
	Hair = CreateDefaultSubobject<UGroomComponent>(TEXT("Hair"));
	Hair->SetupAttachment(Face, "head");
	Hair->bUseAttachParentBound = true;
	Eyebrows = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyebrows"));
	Eyebrows->SetupAttachment(Face, "head");
	Eyebrows->bUseAttachParentBound = true;
	Eyelashes = CreateDefaultSubobject<UGroomComponent>(TEXT("Eyelashes"));
	Eyelashes->SetupAttachment(Face, "head");
	Eyelashes->bUseAttachParentBound = true;

	MetaHumanComponentUE = CreateDefaultSubobject<UMetaHumanComponentUE>(TEXT("MetaHumanComponentUE"));

	LODSync = CreateDefaultSubobject<ULODSyncComponent>(TEXT("LODSyncComponent"));
	LODSync->NumLODs = 8;
	LODSync->ComponentsToSync = {
		FComponentSync(GetMesh()->GetFName(), ESyncOption::Drive),
		FComponentSync(Face->GetFName(), ESyncOption::Drive),
		FComponentSync(Hair->GetFName(), ESyncOption::Passive),
		FComponentSync(Eyebrows->GetFName(), ESyncOption::Passive),
		FComponentSync(Eyelashes->GetFName(), ESyncOption::Passive),
	};
	{
		FLODMappingData& Map = LODSync->CustomLODMapping.Add(GetMesh()->GetFName());
		Map.Mapping = {0, 0, 1, 1, 2, 2, 3, 3};
	}

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void AKatsumiCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CharacterMappingContext, 0);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Enhanced Input Subsystem not found!"));
		}
	}
}

void AKatsumiCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (!Controller)
	{
		return;
	}
	const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
	if (MovementVector.Y != 0)
	{
		FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Forward, MovementVector.Y);
	}
	if (MovementVector.X != 0)
	{
		FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Right, MovementVector.X);
	}
}

void AKatsumiCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookVector = Value.Get<FVector2D>();
	if (!Controller)
	{
		return;
	}
	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void AKatsumiCharacter::Jump()
{
	Super::Jump();
}

void AKatsumiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKatsumiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKatsumiCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AKatsumiCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AKatsumiCharacter::Jump);
	}
}
