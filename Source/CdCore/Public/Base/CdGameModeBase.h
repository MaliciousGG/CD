#pragma once

#include "GameFramework/GameMode.h"

#include "CdGameModeBase.generated.h"

// UCLASS(Abstract)
UCLASS()
class CDCORE_API ACdGameModeBase : public AGameMode
{
	GENERATED_BODY()

public:
	ACdGameModeBase();
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	virtual void Tick(float DeltaTime) override;
	
private:
	int TickCounter;
};