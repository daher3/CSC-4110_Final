// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"


UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
 
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
   Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }

        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
        IsComponentTriggered = true;
    }
    else
    {
        Mover->SetShouldMove(false);
        IsComponentTriggered = false;
    }
}


void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

AActor* UTriggerComponent::GetAcceptableActor() const
{   
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for (AActor* Actor : Actors)
    {
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");
        if (Actor->ActorHasTag(UnlockTag) && !IsGrabbed)
        {
            return Actor;
        }
    }

    return nullptr;
}

	