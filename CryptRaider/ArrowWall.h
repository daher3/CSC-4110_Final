// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTrap.h"
#include "TriggerComponent.h"
#include "NewArrowWallTrigger.h"
#include "ArrowWall.generated.h"


/**
 * 
 * 
 */


UCLASS()

class CRYPTRAIDER_API AArrowWall : public ABaseTrap
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;	

protected: 
// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	
	class UNewArrowWallTrigger* NewTrigger; 

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 300.f; 

	FTimerHandle FireRateTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRate = 2.f;

	void CheckFireCondition();
	class ACryptRaiderCharacter* Character = nullptr;

	bool InFireRange();	
};
