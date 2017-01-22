// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GGJPlayer.generated.h"

UCLASS()
class GGJ17ALPHA_API AGGJPlayer : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(Category = Mesh, EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(Category = Camera, EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(Category = Camera, EditAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(Category = VFX, EditAnywhere)
	class UParticleSystemComponent* Particles;

	FVector2D MovementInput;
	FVector2D CameraInput;

	UPROPERTY(Category=Movement, EditAnywhere)
	float WalkSpeed;

	UPROPERTY(Category = Stamina, EditAnywhere)
	float Stamina;

	UPROPERTY(Category = Stamina, EditAnywhere)
	float MaxStamina;

	UPROPERTY(Category = Stamina, EditAnywhere)
	bool bUseSpecial;

public:
	// Sets default values for this character's properties
	AGGJPlayer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);

	void CameraPitch(float value);
	void CameraYaw(float value);

	UFUNCTION(Category = Stamina, BlueprintCallable)
	float GetStamina();

	UFUNCTION(Category = Stamina, BlueprintCallable)
	float GetStaminaPercent();

	UFUNCTION(Category = Stamina, BlueprintCallable)
	void IncreaseStamina(float value);

	UFUNCTION(Category = Stamina, BlueprintCallable)
	void DecreaseStamina(float value);

	UFUNCTION(Category = Stamina, BlueprintCallable)
	float GetMaxStamina();

	UFUNCTION(Category = Stamina, BlueprintCallable)
	bool IsUsingSpecial();

	UFUNCTION(Category = Stamina, BlueprintCallable)
	void EnableSpecial(bool value);

};
