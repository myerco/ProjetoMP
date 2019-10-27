// Fill out your copyright notice in the Description page of Project Settings.


#include "MPGameInstance.h"
#include "Engine/Engine.h"

UMPGameInstance::UMPGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp,Warning,TEXT("Game instance constructor..."));
};

void UMPGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Game instance init..."));
}
void UMPGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0,2,FColor::Green,TEXT("Host mensagem");

}


