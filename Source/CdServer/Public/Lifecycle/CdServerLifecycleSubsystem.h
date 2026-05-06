#pragma once

#include "CdCoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Config/CdServerConfig.h"
#include "CdServerLifecycleSubsystem.generated.h"

/**
 * @class UCdServerLifecycleSubsystem
 * @brief Manages the lifecycle of the server instance.
 *
 * This subsystem is responsible for handling server startup, shutdown,
 * and runtime state tracking. It is initialized once per GameInstance
 * and persists for the duration of the application.
 *
 * Typical responsibilities include:
 * - Bootstrapping server state
 * - Managing lifecycle transitions (start/stop)
 * - Providing runtime state queries
 *
 * @note Designed for dedicated server usage but can run in listen environments.
 */
UCLASS()
class CDSERVER_API UCdServerLifecycleSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	

	/**
	 * @brief Initializes the subsystem.
	 *
	 * Called automatically by the engine during GameInstance startup.
	 *
	 * @param Collection Reference to subsystem collection.
	 */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
	 * @brief Deinitializes the subsystem.
	 *
	 * Called automatically during GameInstance shutdown.
	 * Ensures proper cleanup of server state.
	 */
	virtual void Deinitialize() override;
	

	/**
	 * @brief Starts the server lifecycle.
	 *
	 * Transitions the server into a running state and triggers
	 * any startup handlers.
	 *
	 * @warning Calling this while already running has no effect.
	 */
	FCdResult StartServer();

	/**
	 * @brief Shuts down the server lifecycle.
	 *
	 * Transitions the server into a stopped state and triggers
	 * shutdown handlers.
	 *
	 * @warning Safe to call multiple times; redundant calls are ignored.
	 */
	FCdResult ShutdownServer();

	/**
	 * @brief Checks if the server is currently running.
	 *
	 * @return True if the server is active, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category="CD|Server")
	bool IsServerRunning() const;
		
private:

	/**
	 * @brief Indicates whether the server is currently running.
	 */
	bool bIsRunning = false;

	/**
	 * @brief Handles internal server start logic.
	 *
	 * Called after the server transitions into a running state.
	 */
	FCdResult HandleServerStart();

	/**
	 * @brief Handles internal server shutdown logic.
	 *
	 * Called after the server transitions into a stopped state.
	 */
	FCdResult HandleServerShutdown();
};