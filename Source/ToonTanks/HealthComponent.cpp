// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"

UHealthComponent::UHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);

	ToonTankGameMode = Cast<AToonTanksGameMode>(UGameplayStatics::GetGameMode(this));
	
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* Instigator, AActor* DamageCauser)
{
	if (Damage <= 0.0f) return;
	Health -= Damage;
	
	if(Health <= 0.0f && ToonTankGameMode)
	{
		ToonTankGameMode->ActorDied(DamagedActor);
	}
}

