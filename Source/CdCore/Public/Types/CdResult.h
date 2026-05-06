#pragma once

#include "CoreMinimal.h"
#include "CdResult.generated.h"

/**
 * @enum ECdResultCode
 * @brief Represents standardized result codes for operations.
 *
 * Used to classify the outcome of an operation beyond simple success/failure.
 * Enables consistent error handling across systems such as networking,
 * backend communication, and gameplay logic.
 */
UENUM(BlueprintType)
enum class ECdResultCode : uint8
{
	/* Operation completed successfully */
	Success,

	/* Generic failure */
	Failed,

	/* Input validation failed */
	InvalidInput,

	/* Requested resource was not found */
	NotFound,

	/** Authorization failed */
	Unauthorized,

	/* Operation timed out */
	Timeout,

	/* Network-level failure */
	NetworkError,

	/* Backend service returned an error */
	BackendError,

	/* Internal system error */
	InternalError,

	/* Missing dependency */
	MissingDependency
};

/**
 * @struct FCdResult
 * @brief Represents the result of an operation.
 *
 * Encapsulates success state, result code, and optional message.
 * Designed to be returned from functions instead of raw booleans
 * to provide richer error context.
 *
 * Example usage:
 * @code
 * FCdResult Result = DoSomething();
 * if (!Result.bSuccess)
 * {
 *     UE_LOG(LogTemp, Error, TEXT("Failed: %s"), *Result.Message);
 * }
 * @endcode
 */
USTRUCT(BlueprintType)
struct FCdResult
{
	GENERATED_BODY()

	/**
	 * @brief Indicates whether the operation succeeded.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Result")
	bool bSuccess = false;

	/**
	 * @brief Result classification code.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Result")
	ECdResultCode Code = ECdResultCode::Failed;

	/**
	 * @brief Optional message describing the result.
	 *
	 * Typically used for error details or debugging context.
	 */
	UPROPERTY(BlueprintReadOnly, Category="Result")
	FString Message;
	
	/**
	 * @brief Creates a successful result.
	 *
	 * @return FCdResult representing success.
	 */
	static FCdResult Success()
	{
		FCdResult Result;
		Result.bSuccess = true;
		Result.Code = ECdResultCode::Success;
		return Result;
	}

	/**
	 * @brief Creates a failed result with a message.
	 *
	 * @param InCode Specific failure code.
	 * @param InMessage Descriptive message.
	 * @return FCdResult representing failure.
	 *
	 * @warning Do not pass ECdResultCode::Success to this function.
	 */
	static FCdResult Failed(const ECdResultCode InCode, const FString& InMessage)
	{
		FCdResult Result;
		Result.bSuccess = false;
		Result.Code = InCode;
		Result.Message = InMessage;
		return Result;
	}

	/**
	 * @brief Creates a failed result without a message.
	 *
	 * @param InCode Specific failure code.
	 * @return FCdResult representing failure.
	 *
	 * @warning Do not pass ECdResultCode::Success to this function.
	 * @warning Created for overload purposes. Will throw a warning message when used. 
	 *
	 * @code
	 * // Use this for most cases.
	 * FCdResult Failed(const ECdResultCode InCode, const FString& InMessage)
	 * @endcode
	 */
	 [[deprecated("FCdResult::Failed(const ECdResultCode InCode) called. Use FCdResult::Failed(const ECdResultCode, const FString& InMessage)")]]
	 static FCdResult Failed(const ECdResultCode InCode)
	{
		FCdResult Result;
		Result.bSuccess = false;
		Result.Code = InCode;
		return Result;
	}
};