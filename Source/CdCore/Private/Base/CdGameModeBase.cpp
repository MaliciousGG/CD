#include "Base/CdGameModeBase.h"

#include "Logging/CdLogCategories.h"
#include "Logging/CdLogMacros.h"

ACdGameModeBase::ACdGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	TickCounter = 0;
}

void ACdGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACdGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

}

void ACdGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

