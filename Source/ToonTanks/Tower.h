// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();
protected:
	virtual void BeginPlay() override;

private:
	class ATank* Tank;
	FTimerHandle FireRateTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 300.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRate = 2.0f;

	void CheckFireCondition();

	bool InFireRange();
};
