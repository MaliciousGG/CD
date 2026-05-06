#pragma once

#include "CoreMinimal.h"
#include "Misc/AssertionMacros.h"

/**
 * @brief Centralized assertion and validation helpers for CdCore.
 *
 * These macros wrap Unreal assertion systems behind a project-specific API layer.
 * This allows assertion behavior to evolve later without rewriting gameplay code.
 *
 * Current backend:
 * - check()
 * - checkf()
 * - ensure()
 * - ensureMsgf()
 *
 * Future possibilities:
 * - Crash reporting
 * - Telemetry integration
 * - Dedicated server diagnostics
 * - Custom assertion handlers
 * - Stack trace logging
 */

/**
 * @brief Verifies that an expression is true.
 *
 * Crashes immediately if the condition fails.
 *
 * Use for:
 * - Critical invariants
 * - Invalid program states
 * - Impossible execution paths
 *
 * Example:
 * @code
 * CD_ASSERT(PlayerState != nullptr);
 * @endcode
 */
#define CD_ASSERT(Expression) \
    check(Expression)

/**
 * @brief Verifies that an expression is true with a formatted message.
 *
 * Crashes immediately if the condition fails.
 *
 * Example:
 * @code
 * CD_ASSERTF(Index >= 0, TEXT("Index cannot be negative"));
 * @endcode
 */
#define CD_ASSERTF(Expression, Format, ...) \
    checkf(Expression, TEXT(Format), ##__VA_ARGS__)

/**
 * @brief Non-fatal runtime validation.
 *
 * Logs an error if the condition fails but does not crash execution.
 *
 * Useful for:
 * - Recoverable runtime issues
 * - Network validation
 * - Asset validation
 * - Defensive programming
 *
 * Example:
 * @code
 * if (!CD_ENSURE(InventoryComponent))
 * {
 *     return;
 * }
 * @endcode
 */
#define CD_ENSURE(Expression) \
    ensure(Expression)

/**
 * @brief Non-fatal runtime validation with formatted logging.
 *
 * Example:
 * @code
 * CD_ENSUREF(
 *     AmmoCount > 0,
 *     "Weapon [%s] has invalid ammo count",
 *     *WeaponName
 * );
 * @endcode
 */
#define CD_ENSUREF(Expression, Format, ...) \
    ensureMsgf(Expression, TEXT(Format), ##__VA_ARGS__)

/**
 * @brief Marks unreachable code paths.
 *
 * Crashes if execution reaches this point.
 *
 * Example:
 * @code
 * switch (State)
 * {
 *     case EState::Idle:
 *         break;
 *
 *     default:
 *         CD_UNREACHABLE();
 *         break;
 * }
 * @endcode
 */
#define CD_UNREACHABLE() \
    checkNoEntry()

/**
 * @brief Explicit fatal assertion with formatted message.
 *
 * Always crashes execution immediately.
 *
 * Intended for catastrophic unrecoverable states.
 *
 * WARNING:
 * This should be used sparingly.
 *
 * Example:
 * @code
 * CD_FATAL("Failed to initialize server backend");
 * @endcode
 */
#define CD_FATAL(Format, ...) \
    checkf(false, TEXT(Format), ##__VA_ARGS__)

/**
 * @brief Runtime verification that always evaluates the expression.
 *
 * Unlike check(), verify() still evaluates in shipping builds.
 *
 * Useful when the expression has side effects.
 *
 * Example:
 * @code
 * CD_VERIFY(SaveGame());
 * @endcode
 */
#define CD_VERIFY(Expression) \
    verify(Expression)

/**
 * @brief Runtime verification with formatted message.
 */
#define CD_VERIFYF(Expression, Format, ...) \
    verifyf(Expression, TEXT(Format), ##__VA_ARGS__)