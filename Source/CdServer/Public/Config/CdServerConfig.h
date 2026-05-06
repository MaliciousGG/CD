#pragma once

#include "CoreMinimal.h"
#include "Types/CdIds.h"
#include "CdServerConfig.generated.h"

/**
 * @struct FCdServerConfig
 * @brief Represents runtime configuration for a server instance.
 *
 * This struct contains identifying and networking information required
 * to initialize and register a server with backend services.
 *
 * @note This is a pure data container. Access should be handled externally
 *       (e.g., via a subsystem or config manager).
 */
USTRUCT(BlueprintType)
struct FCdServerConfig
{
	GENERATED_BODY()
	/**
	 * @brief IP address the server is bound to.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Server")
	FString IpAddress = TEXT("127.0.0.1");

	/**
	 * @brief Port the server is listening on.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Server")
	FString Port = TEXT("7777");

	/**
	 * @brief Unique identifier for this server instance.
	 * 
	 * @note Replace later with FCdGuid
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Server")
	FCdGuid ServerId = FCdGuid::New();
	
	/**
	 * @brief Generates a new unique server ID.
	 */
	void RegenerateServerId()
	{
		ServerId = FCdGuid::New();
	}
};