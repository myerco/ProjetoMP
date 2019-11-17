
// Fill out your copyright notice in the Description page of Project Settings.


#include "MPGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Plataforms/PlataformTrigger.h"
#include "Blueprint/UserWidget.h"
#include "../UI/MainMenu.h"

UMPGameInstance::UMPGameInstance(const FObjectInitializer& ObjectInitializer)
{
	/*
	//Exemplo da associação de classe Blueprint e c++
	ConstructorHelpers::FClassFinder<APlataformTrigger> PlataformTriggerBPClass(TEXT("/Game/Blueprints/Plataforms/BP_PlataformTrigger"));
	if (!ensure(PlataformTriggerBPClass.Class != nullptr)) return;
	UE_LOG(LogTemp, Warning, TEXT("Encontrei a classe %s"),*PlataformTriggerBPClass.Class->GetName());
	UE_LOG(LogTemp,Warning,TEXT("Game instance constructor..."));
	*/
	
	// Procura e instância a classe do Menu construido na IDE
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/UI/MainMenu/MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;
	UE_LOG(LogTemp, Warning, TEXT("Encontrei a classe BP do menu %s"), *MenuBPClass.Class->GetName());

	// Inicializa a variável MenuClass com a classe encontrada 
	MenuClass = MenuBPClass.Class;
	 
};

void UMPGameInstance::Init()
{
	//UE_LOG(LogTemp, Warning, TEXT("Game instance init..."));
	UE_LOG(LogTemp, Warning, TEXT("Classe do menu %s"),*MenuClass->GetName());
}
void UMPGameInstance::Host()
{
	UE_LOG(LogTemp, Warning, TEXT("Host..."));
	/*
	// Escreve mensagem na tela (Exemplo : PrintString)
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0,2,FColor::Green,TEXT("Host mensagem");
	*/
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/LevelTest?Listen");
}

void UMPGameInstance::Join(const FString& Address)
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ClientTravel(Address,ETravelType::TRAVEL_Absolute);
}

void UMPGameInstance::LoadMenu()
{
	// Prepara a variável Menu utilizando o Widget 
	if (!ensure(MenuClass != nullptr)) return;
	//UUserWidget *Menu =  CreateWidget<UUserWidget>(this, MenuClass);
	UMainMenu* Menu = CreateWidget<UMainMenu>(this, MenuClass);

	// Adiciona o menu na tela
	if (!ensure(Menu != nullptr)) return;
	Menu->AddToViewport();

	// Configurando os inputs do menu
	
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(Menu->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;

	Menu->SetMenuInterface(this);
}


