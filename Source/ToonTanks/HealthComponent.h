// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ToonTanksGameMode.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.0f;
	float Health = 0.0f;

	class AToonTanksGameMode* ToonTankGameMode;

	UFUNCTION()
	void DamageTaken(
		AActor* DamagedActor,
		float Damage,
		const UDamageType* DamageType,
		class AController* Instigator,
		AActor* DamageCauser);
};
