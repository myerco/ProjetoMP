// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJETOMP_API UMPGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UMPGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(BlueprintCallable, Category = Menu)
	void LoadMenu();

private:
	TSubclassOf<class UUserWidget> MenuClass;
	
};
