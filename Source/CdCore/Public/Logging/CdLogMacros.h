#pragma once

#include "CoreMinimal.h"

#pragma region Console Logging

/**
 * @def CD_LOG
 * @brief Core logging macro that wraps UE_LOG with function context.
 *
 * Prepends the calling function name to the log message for easier tracing.
 *
 * @param Category   Log category (e.g., LogTemp, LogCd)
 * @param Verbosity  Log verbosity level (e.g., Display, Warning, Error)
 * @param Format     printf-style format string
 * @param ...        Additional format arguments
 *
 * @note Uses Unreal's UE_LOG internally.
 * @see CD_LOG_INFO, CD_LOG_WARNING, CD_LOG_ERROR, CD_LOG_FATAL
 */
#define CD_LOG(Category, Verbosity, Format, ...) \
	UE_LOG(Category, Verbosity, TEXT("[%s] " Format), *FString(__FUNCTION__), ##__VA_ARGS__)


/**
 * @def CD_LOG_INFO
 * @brief Logs an informational message.
 *
 * Intended for general runtime information and flow tracking.
 *
 * @param Category Log category
 * @param Format   printf-style format string
 * @param ...      Additional format arguments
 */
#define CD_LOG_INFO(Category, Format, ...) \
	CD_LOG(Category, Display, Format, ##__VA_ARGS__)


/**
 * @def CD_LOG_WARNING
 * @brief Logs a warning message.
 *
 * Used for non-critical issues that may indicate unintended behavior.
 *
 * @param Category Log category
 * @param Format   printf-style format string
 * @param ...      Additional format arguments
 */
#define CD_LOG_WARNING(Category, Format, ...) \
	CD_LOG(Category, Warning, Format, ##__VA_ARGS__)


/**
 * @def CD_LOG_ERROR
 * @brief Logs an error message.
 *
 * Used for serious issues that may impact functionality but do not immediately terminate execution.
 *
 * @param Category Log category
 * @param Format   printf-style format string
 * @param ...      Additional format arguments
 */
#define CD_LOG_ERROR(Category, Format, ...) \
	CD_LOG(Category, Error, Format, ##__VA_ARGS__)


/**
 * @def CD_LOG_FATAL
 * @brief Logs a fatal error and immediately terminates the application.
 *
 * @warning This will crash the application after logging.
 * Use only for unrecoverable errors where continuing execution is unsafe.
 *
 * @param Category Log category
 * @param Format   printf-style format string
 * @param ...      Additional format arguments
 *
 * @note Internally uses UE_LOG with Fatal verbosity, which triggers a crash.
 */
#define CD_LOG_FATAL(Category, Format, ...) \
	CD_LOG(Category, Fatal, Format, ##__VA_ARGS__)

#pragma endregion Console Logging

#pragma region Screen Logging

/**
 * @def CD_SCREEN
 * @brief Displays a formatted debug message on screen.
 *
 * Wraps GEngine->AddOnScreenDebugMessage with printf-style formatting.
 *
 * @param Key      Unique message key (-1 = always new message)
 * @param Time     Duration in seconds
 * @param Color    Display color (FColor)
 * @param Format   printf-style format string
 * @param ...      Additional format arguments
 *
 * @note Only works when GEngine is valid (non-dedicated server).
 */
#define CD_SCREEN(Key, Time, Color, Format, ...) \
	if (GEngine) \
	{ \
		GEngine->AddOnScreenDebugMessage( \
		Key, \
		Time, \
		Color, \
		FString::Printf(TEXT("[%s] " Format), *FString(__FUNCTION__), ##__VA_ARGS__) \
		); \
	}

/**
 * @brief Green informational screen message.
 */
#define CD_SCREEN_INFO(Key, Time, Format, ...) \
	CD_SCREEN(Key, Time, FColor::Green, Format, ##__VA_ARGS__)

/**
 * @brief Yellow warning screen message.
 */
#define CD_SCREEN_WARNING(Key, Time, Format, ...) \
	CD_SCREEN(Key, Time, FColor::Yellow, Format, ##__VA_ARGS__)

/**
 * @brief Red error screen message.
 */
#define CD_SCREEN_ERROR(Key, Time, Format, ...) \
CD_SCREEN(Key, Time, FColor::Red, Format, ##__VA_ARGS__)

#pragma endregion Screen Logging