// Fill out your copyright notice in the Description page of Project Settings.


#include "PitfallTriggerComponent.h"
#include "Windows.h"

UPitfallTriggerComponent::UPitfallTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
    bIsPlayerOverlapping = false; // Initialize the flag to false
}

void UPitfallTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
    Character = Cast<ACryptRaiderCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());	
}

void UPitfallTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

void UPitfallTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Character)
	{
		if (IsOverlappingActor(Character))
		{
			// The player character is overlapping with the trigger
			// Set Mover->SetShouldMove to true if you want to activate the Mover component
			if (Mover && !bIsPlayerOverlapping)
			{
				Mover->SetShouldMove(true);
                bIsPlayerOverlapping = true; // Set the flag to true to indicate player is overlapping
			}

			// Log a message to see the trigger is activated when the player is overlapping
			//UE_LOG(LogTemp, Warning, TEXT("Player is overlapping with the trigger!"));
		}
		else
		{
			if (bIsPlayerOverlapping) // Check if the player was previously overlapping
			{
				// The player character is not overlapping with the trigger
				// Set Mover->SetShouldMove to false after a delay of 2 seconds (you can change the delay as needed)
				if (Mover)
				{
					FTimerHandle TimerHandle;
					GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() { Mover->SetShouldMove(false); }, 5.0f, false);
				}

				// Log a message to see when the trigger is deactivated
				//UE_LOG(LogTemp, Warning, TEXT("Player is not overlapping with the trigger!"));

				bIsPlayerOverlapping = false; // Reset the flag when the player stops overlapping

            }
		}
	}
	else
	{
		// Log a message to see if the Character reference is null
		UE_LOG(LogTemp, Warning, TEXT("Character reference is null!"));
	}
}

bool UPitfallTriggerComponent::IsPlayerOverlappingTrigger() const
{
	return Character && IsOverlappingActor(Character);
}