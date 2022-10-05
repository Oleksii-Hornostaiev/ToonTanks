// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();
	APlayerController* GetTankPlayerController() const{return TankPlayerController;}

	bool bAlive = true;
	
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movements", meta = (AllowPrivateAccess = true))
	float Speed = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movements", meta = (AllowPrivateAccess = true))
	float TurnRate = 200.0f;

	void Move(float Value);
	void Turn(float Value);

	UPROPERTY()
	APlayerController* TankPlayerController;
};
