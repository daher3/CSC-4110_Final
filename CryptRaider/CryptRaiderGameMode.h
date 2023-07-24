// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CryptRaiderGameMode.generated.h"

UCLASS(minimalapi)
class ACryptRaiderGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACryptRaiderGameMode();

	void ActorDied(AActor* DeadActor);
//	void PlayerOverlap();

//	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver();

protected:

	virtual void BeginPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	

	UFUNCTION(BlueprintImplementableEvent)
	void DeadCharacter();


private:

	class ACryptRaiderCharacter* Character;

	class UWinTriggerComponent* WinTrigger;
	
};



