#pragma once

#include "CoreMinimal.h"
#include "CdIds.generated.h"

/**
 * @struct FCdGuid
 * @brief Strong wrapper around FGuid with validation and utility helpers.
 *
 * Provides a consistent interface for working with globally unique identifiers
 * across systems such as servers, sessions, and backend entities.
 *
 * Includes comparison operators, hashing support, and conversion utilities
 * for seamless integration with Unreal containers and APIs.
 *
 * @note Uses EGuidFormats::DigitsWithHyphens for string serialization.
 */
USTRUCT(BlueprintType)
struct FCdGuid
{
	GENERATED_BODY()

	/**
	 * @brief Underlying GUID value.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Id")
	FGuid Value;
	
	/**
	 * @brief Checks whether the GUID is valid.
	 *
	 * @return True if the GUID is valid, false otherwise.
	 */
	bool IsValid() const
	{
		return Value.IsValid();
	}

	/**
	 * @brief Converts the GUID to a string representation.
	 *
	 * @return FString formatted as DigitsWithHyphens.
	 */
	FString ToString() const
	{
		return Value.ToString(EGuidFormats::DigitsWithHyphens);
	}

	/**
	 * @brief Generates a new GUID instance.
	 *
	 * @return FCdGuid containing a newly generated GUID.
	 */
	static FCdGuid New()
	{
		FCdGuid Id;
		Id.Value = FGuid::NewGuid();
		return Id;
	}

	// =====================================================
	// Comparison Operators
	// =====================================================

	/**
	 * @brief Equality operator.
	 *
	 * @param Other The GUID to compare against.
	 * @return True if both GUIDs are equal.
	 */
	bool operator==(const FCdGuid& Other) const
	{
		return Value == Other.Value;
	}

	/**
	 * @brief Inequality operator.
	 *
	 * @param Other The GUID to compare against.
	 * @return True if GUIDs are not equal.
	 */
	bool operator!=(const FCdGuid& Other) const
	{
		return !(*this == Other);
	}

	/**
	 * @brief Less-than operator for ordering.
	 *
	 * Enables sorting and ordered container usage.
	 *
	 * @param Other The GUID to compare against.
	 * @return True if this GUID is less than the other.
	 */
	bool operator<(const FCdGuid& Other) const
	{
		return Value < Other.Value;
	}

	// =====================================================
	// Hashing
	// =====================================================

	/**
	 * @brief Hash function for use with TMap and TSet.
	 *
	 * @param Id The GUID to hash.
	 * @return Hash value.
	 */
	friend uint32 GetTypeHash(const FCdGuid& Id)
	{
		return GetTypeHash(Id.Value);
	}

	// =====================================================
	// Conversions
	// =====================================================

	/**
	 * @brief Explicit conversion to underlying FGuid.
	 *
	 * @return Const reference to the internal FGuid.
	 *
	 * @note Explicit to preserve type safety.
	 */
	operator const FGuid&() const
	{
		return Value;
	}

	/**
	 * @brief Creates a GUID from a string.
	 *
	 * @param InString String representation of a GUID.
	 * @return Parsed FCdGuid (invalid if parsing fails).
	 */
	static FCdGuid FromString(const FString& InString)
	{
		FCdGuid Id;
		FGuid::Parse(InString, Id.Value);
		return Id;
	}

	// =====================================================
	// Utilities
	// =====================================================

	/**
	 * @brief Resets the GUID to an invalid state.
	 */
	void Reset()
	{
		Value.Invalidate();
	}
};


/**
 * @struct FCdStringId
 * @brief Strong wrapper for string-based identifiers.
 *
 * Used for identifiers that originate outside the system or are not
 * GUID-based, such as usernames, external service IDs, or database keys.
 *
 * Provides validation, comparison, hashing, and conversion utilities.
 */
USTRUCT(BlueprintType)
struct FCdStringId
{
	GENERATED_BODY()


	/**
	 * @brief Underlying string identifier.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Id")
	FString Value;

	/**
	 * @brief Checks whether the string ID is valid.
	 *
	 * A valid ID is defined as a non-empty string.
	 *
	 * @return True if the ID is valid, false otherwise.
	 */
	bool IsValid() const
	{
		return !Value.IsEmpty();
	}

	// =====================================================
	// Comparison Operators
	// =====================================================

	/**
	 * @brief Equality operator.
	 *
	 * @param Other The ID to compare against.
	 * @return True if both IDs are equal.
	 */
	bool operator==(const FCdStringId& Other) const
	{
		return Value == Other.Value;
	}

	/**
	 * @brief Inequality operator.
	 *
	 * @param Other The ID to compare against.
	 * @return True if IDs are not equal.
	 */
	bool operator!=(const FCdStringId& Other) const
	{
		return !(*this == Other);
	}

	/**
	 * @brief Less-than operator for ordering.
	 *
	 * Enables sorting and ordered container usage.
	 *
	 * @param Other The ID to compare against.
	 * @return True if this ID is less than the other.
	 */
	bool operator<(const FCdStringId& Other) const
	{
		return Value < Other.Value;
	}

	// =====================================================
	// Hashing
	// =====================================================

	/**
	 * @brief Hash function for use with TMap and TSet.
	 *
	 * @param Id The ID to hash.
	 * @return Hash value.
	 */
	friend uint32 GetTypeHash(const FCdStringId& Id)
	{
		return GetTypeHash(Id.Value);
	}

	// =====================================================
	// Conversions
	// =====================================================

	/**
	 * @brief Explicit conversion to FString.
	 *
	 * @return Const reference to the internal string.
	 *
	 * @note Explicit to maintain type safety.
	 */
	explicit operator const FString&() const
	{
		return Value;
	}

	/**
	 * @brief Creates an ID from a string.
	 *
	 * @param InString Input string.
	 * @return FCdStringId containing the provided value.
	 */
	static FCdStringId FromString(const FString& InString)
	{
		FCdStringId Id;
		Id.Value = InString;
		return Id;
	}

	// =====================================================
	// Utilities
	// =====================================================

	/**
	 * @brief Resets the ID to an empty state.
	 */
	void Reset()
	{
		Value.Empty();
	}
};