// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformTrigger.h"
#include "Components/BoxComponent.h"
#include "SMPlataform.h"

// Sets default values
APlataformTrigger::APlataformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr ))  return;
	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this,&APlataformTrigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlataformTrigger::OnOverlapEnd);

	//StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Static Mesh"));
	//StaticMesh->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void APlataformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlataformTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp,Warning,TEXT("Trigger ativada"));
	for (ASMPlataform* Plataform : PlataformsTriggers) 
	{
		Plataform->AddActiceTrigger();
	}
}

void APlataformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Trigger desativada"));
	for (ASMPlataform* Plataform : PlataformsTriggers)
	{
		Plataform->RemoveActiceTrigger();
	}
}

