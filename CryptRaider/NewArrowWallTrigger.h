// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "NewArrowWallTrigger.generated.h"

class UTriggerComponent;
class AArrowWall;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UNewArrowWallTrigger : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNewArrowWallTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	// AArrowWall* ArrowWall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	UTriggerComponent* TriggerComponent;

public:	

	// UFUNCTION(BlueprintCallable)
	// void SetArrowWall(AArrowWall* Wall);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTriggerComponent(UTriggerComponent* Trigger);

	bool ShouldArrowWallFire() const;

private:

};
