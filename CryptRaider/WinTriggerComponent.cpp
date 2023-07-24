// Fill out your copyright notice in the Description page of Project Settings.


#include "WinTriggerComponent.h"
#include "CryptRaiderGameMode.h"
#include "Kismet/GameplayStatics.h"


UWinTriggerComponent::UWinTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
    bIsPlayerOverlapping = false; // Initialize the flag to false
}

void UWinTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
    Character = Cast<ACryptRaiderCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());	

    // Get a reference to the CryptRaiderGameMode
    UWorld* World = GetWorld();
    if (World)
    {
        AGameModeBase* GameModeBase = UGameplayStatics::GetGameMode(World);
        if (GameModeBase)
        {
            GameMode = Cast<ACryptRaiderGameMode>(GameModeBase);
        }
    }
}


void UWinTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Character)
	{
		if (IsOverlappingActor(Character))
		{
            //UE_LOG(LogTemp, Warning, TEXT("Player is Overlapping!"));
            bIsPlayerOverlapping = true;
            GameMode->GameOver();
		}
		else
        {
           // UE_LOG(LogTemp, Warning, TEXT("Player is no longer overlapping!"));
			bIsPlayerOverlapping = false; // Reset the flag when the player stops overlapping
        }
	}
	else
	{
		// Log a message to see if the Character reference is null
		UE_LOG(LogTemp, Warning, TEXT("Character reference is null!"));
	}
}

bool UWinTriggerComponent::IsPlayerOverlappingTrigger() const
{
	return Character && IsOverlappingActor(Character);
}