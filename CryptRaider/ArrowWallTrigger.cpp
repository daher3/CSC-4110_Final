// // Fill out your copyright notice in the Description page of Project Settings.


// #include "ArrowWallTrigger.h"
// #include "TriggerComponent.h"

// // Sets default values for this component's properties
// UArrowWallTrigger::UArrowWallTrigger()
// {
// 	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
// 	// off to improve performance if you don't need them.
// 	PrimaryComponentTick.bCanEverTick = true;

// }


// // Called when the game starts
// void UArrowWallTrigger::BeginPlay()
// {
//     Super::BeginPlay();

	
// }


// // Called every frame
// void UArrowWallTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
// {
// 	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

// 	// ...
// }

// bool UArrowWallTrigger::ShouldArrowWallFire() const
// {
// // Ensure that the owning actor (AArrowWall) is valid
//     AActor* Owner = GetOwner();
//     if (!Owner)
//     {
//         UE_LOG(LogTemp, Warning, TEXT("ArrowWallTrigger has no owning actor."));
//         return false;
//     }

//     // Check if the TriggerComponent is attached to the owning actor (AArrowWall)
//     UTriggerComponent* FoundTriggerComponent = Owner->FindComponentByClass<UTriggerComponent>();
//     if (!FoundTriggerComponent)
//     {
//         UE_LOG(LogTemp, Warning, TEXT("Trigger component not found in AArrowWall."));
//         return false;
//     }

//     // Check if the TriggerComponent has the acceptable actor with the specific unlock tag
//     bool bHasAcceptableActor = FoundTriggerComponent->GetAcceptableActor() != nullptr;
//     if (bHasAcceptableActor && FoundTriggerComponent->HasUnlockTag("Unlock1"))
//     {
//         return true;
//     }

//     return false;

// }

