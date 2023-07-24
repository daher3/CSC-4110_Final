// Fill out your copyright notice in the Description page of Project Settings.


#include "NewArrowWallTrigger.h"
#include "TriggerComponent.h"
#include "ArrowWall.h"

// Sets default values for this component's properties
UNewArrowWallTrigger::UNewArrowWallTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UNewArrowWallTrigger::BeginPlay()
{
	Super::BeginPlay();

}


void UNewArrowWallTrigger::SetTriggerComponent(UTriggerComponent* Trigger)
{
	TriggerComponent = Trigger;
}


bool UNewArrowWallTrigger::ShouldArrowWallFire() const
{
	if (TriggerComponent == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("TriggerComponent is null"));
		return false;
	}
	if(!TriggerComponent->IsComponentTriggered)
	{
		
		return true;
	}
	else 
	return false;
}