// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"


void AToonTanksPlayerController::SetPlayerEnableState(bool bPlayerEnabled)
{
	if(bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;
}
