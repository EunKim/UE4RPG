// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <Blueprint/UserWidget.h>
#include <Templates/SubclassOf.h>
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPG716_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    
	//Reference to UMG asset
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> HUDOverlayAsset;

	//위젯 생성후 변수 담을곳
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* HUDOverlay;

	// 몬스터 HP 표헌
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> WEnemyHealthBar;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* EnemyHealthBar;

	bool bEnemyHealthBarVisible;

	void DisplayEnemyHealthBar();
	void RemoveEnemyHealthBar();

	FVector EnemyLocation;

protected:

    virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
