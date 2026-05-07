#pragma once

#include "CoreMinimal.h"

/**
 * @namespace CdBuild
 * @brief Utility helpers for querying Unreal build configuration state.
 *
 * This namespace centralizes Unreal build macros behind a consistent API layer.
 * Instead of scattering UE_BUILD_* and WITH_* macros throughout gameplay code,
 * systems should query build state through these helpers.
 *
 * Example:
 * @code
 * if (CdBuild::IsServerBuild())
 * {
 *     // Dedicated server logic
 * }
 * @endcode
 */
namespace CdBuild
{
    /**
     * @brief Returns true if this is a dedicated server build.
     */
    FORCEINLINE bool IsServerBuild()
    {
        return IsRunningDedicatedServer();
    }

    /**
     * @brief Returns true if this build includes editor functionality.
     */
    FORCEINLINE constexpr bool IsEditorBuild()
    {
    #if WITH_EDITOR
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if this is a shipping build.
     */
    FORCEINLINE constexpr bool IsShippingBuild()
    {
    #if UE_BUILD_SHIPPING
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if this is a development build.
     */
    FORCEINLINE constexpr bool IsDevelopmentBuild()
    {
    #if UE_BUILD_DEVELOPMENT
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if this is a debug build.
     */
    FORCEINLINE constexpr bool IsDebugBuild()
    {
    #if UE_BUILD_DEBUG
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if this is a test build.
     */
    FORCEINLINE constexpr bool IsTestBuild()
    {
    #if UE_BUILD_TEST
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if runtime checks should be enabled.
     *
     * Typically disabled in shipping builds.
     */
    FORCEINLINE constexpr bool IsRuntimeChecksEnabled()
    {
    #if !UE_BUILD_SHIPPING
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if logging should be enabled.
     */
    FORCEINLINE constexpr bool IsLoggingEnabled()
    {
    #if NO_LOGGING
        return false;
    #else
        return true;
    #endif
    }

    /**
     * @brief Returns true if assertions/checks are enabled.
     */
    FORCEINLINE constexpr bool IsCheckEnabled()
    {
    #if DO_CHECK
        return true;
    #else
        return false;
    #endif
    }

    /**
     * @brief Returns true if ensure macros are enabled.
     */
    FORCEINLINE constexpr bool IsEnsureEnabled()
    {
    #if DO_ENSURE
        return true;
    #else
        return false;
    #endif
    }
}