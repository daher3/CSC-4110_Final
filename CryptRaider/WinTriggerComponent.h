// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "CryptRaiderCharacter.h"
#include "WinTriggerComponent.generated.h"

/**
 * 
 */

class ACryptRaiderCharacter;
class ACryptRaiderGameMode;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UWinTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:	
	UWinTriggerComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Function to check if the player character is overlapping with the trigger
	UFUNCTION(BlueprintCallable, Category = "WinTrigger")
	bool IsPlayerOverlappingTrigger() const;

	ACryptRaiderCharacter* Character;
	ACryptRaiderGameMode* GameMode;

	bool bIsPlayerOverlapping;
private:
	
	
};
