// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintNodeHelpers.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);
	
private:
	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;
	
	float StartDelay = 3.0f;
	int32 TargetTowers = 0;

	int32 GetTargetCountNumber();
	void HandleGameStart();
	
};
