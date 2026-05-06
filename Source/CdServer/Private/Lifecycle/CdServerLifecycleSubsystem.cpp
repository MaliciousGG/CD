#include "Lifecycle/CdServerLifecycleSubsystem.h"
#include "Engine/Engine.h"

void UCdServerLifecycleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (IsRunningDedicatedServer())
	{
		StartServer();
	}
}


void UCdServerLifecycleSubsystem::Deinitialize()
{
	ShutdownServer();

	Super::Deinitialize();
}


FCdResult UCdServerLifecycleSubsystem::StartServer()
{
	if (bIsRunning)
	{
		return FCdResult({
			false,
			ECdResultCode::Failed,
			TEXT("Server Start called after it's already running")
		});
	}

	bIsRunning = true;

	FCdResult Result = HandleServerStart();
	
	return Result;
}


FCdResult UCdServerLifecycleSubsystem::ShutdownServer()
{
	if (!bIsRunning)
	{
		return FCdResult({
			false,
			ECdResultCode::Failed,
			TEXT("Server Shutdown called while not running")
		});
	}

	bIsRunning = false;
	
	FCdResult Result = HandleServerShutdown();
	
	return Result;
}

bool UCdServerLifecycleSubsystem::IsServerRunning() const
{
	return bIsRunning;
}

FCdResult UCdServerLifecycleSubsystem::HandleServerStart()
{
	return FCdResult({true, ECdResultCode::Success});
}

FCdResult UCdServerLifecycleSubsystem::HandleServerShutdown()
{
	return FCdResult({true, ECdResultCode::Success});
}