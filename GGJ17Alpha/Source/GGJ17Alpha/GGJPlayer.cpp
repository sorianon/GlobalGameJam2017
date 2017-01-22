// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ17Alpha.h"
#include "GGJPlayer.h"


// Sets default values
AGGJPlayer::AGGJPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxStamina = 100;
	Stamina = MaxStamina;
	WalkSpeed = 500;

	bUseSpecial = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeLocationAndRotation(FVector(0, 0, 50), FRotator(0, 0, 0));
	SpringArm->TargetArmLength = 500;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	StaticMesh->SetupAttachment(RootComponent);
	
	Particles = CreateDefaultSubobject<UParticleSystemComponent>("Particle System");
	Particles->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGGJPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGJPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//Rotate our actor's yaw, which will turn our camera because we're attached to it
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation);
	}

	//Rotate our camera's pitch, but limit it so we're always looking downward
	{
		FRotator NewRotation = SpringArm->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f, -15.0f);
		SpringArm->SetWorldRotation(NewRotation);
	}

	//Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!MovementInput.IsZero())
		{
			//Scale our movement input axis values by 100 units per second
			MovementInput = MovementInput.SafeNormal() * WalkSpeed;
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
			NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
			SetActorLocation(NewLocation);
		}
	}
}

// Called to bind functionality to input
void AGGJPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGGJPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGGJPlayer::MoveRight);

	PlayerInputComponent->BindAxis("CameraPitch", this, &AGGJPlayer::CameraPitch);
	PlayerInputComponent->BindAxis("CameraYaw", this, &AGGJPlayer::CameraYaw);
}

void AGGJPlayer::MoveForward(float value)
{
	MovementInput.X = FMath::Clamp(value, -1.0f, 1.0f);
}

void AGGJPlayer::MoveRight(float value)
{
	MovementInput.Y = FMath::Clamp(value, -1.0f, 1.0f);
}

void AGGJPlayer::CameraPitch(float value)
{
	CameraInput.Y = value;
}

void AGGJPlayer::CameraYaw(float value)
{
	CameraInput.X += value;
}

float AGGJPlayer::GetStamina()
{
	return Stamina;
}

float AGGJPlayer::GetStaminaPercent()
{
	float Result = Stamina / MaxStamina;
	return Result;
}

void AGGJPlayer::IncreaseStamina(float value)
{
	Stamina += value;
	Stamina = FMath::Clamp(Stamina, 0.0f, MaxStamina);
}

void AGGJPlayer::DecreaseStamina(float value)
{
	Stamina -= value;
	Stamina = FMath::Clamp(Stamina, 0.0f, MaxStamina);
}

float AGGJPlayer::GetMaxStamina()
{
	return MaxStamina;
}

bool AGGJPlayer::IsUsingSpecial()
{
	return bUseSpecial;
}

void AGGJPlayer::EnableSpecial(bool value)
{
	bUseSpecial = value;
}


