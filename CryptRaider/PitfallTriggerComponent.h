// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "CryptRaiderCharacter.h"
#include "Mover.h"
#include "PitfallTriggerComponent.generated.h"

/**
 * 
 */

class ACryptRaiderCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UPitfallTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:	
	UPitfallTriggerComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* Mover);	
	
	// Function to check if the player character is overlapping with the trigger
	UFUNCTION(BlueprintCallable, Category = "PitfallTrigger")
	bool IsPlayerOverlappingTrigger() const;

	class UMover* Mover;

	ACryptRaiderCharacter* Character;

	bool bIsPlayerOverlapping;
private:
	
		
};
