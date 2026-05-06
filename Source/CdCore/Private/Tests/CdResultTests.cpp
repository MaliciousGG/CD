#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "Types/CdResult.h"

#pragma region FCdResultSuccesTests

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCdResultSuccessTestI,
	"Cd.Result.Success.I",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FCdResultSuccessTestI::RunTest(const FString& Parameters)
{
	const FCdResult Result = FCdResult::Success();

	TestTrue(TEXT("Result should succeed"), Result.bSuccess);
	TestEqual(TEXT("Result code should be Success"), Result.Code, ECdResultCode::Success);
	TestTrue(TEXT("Message should be empty"), Result.Message.IsEmpty());

	return true;
}

#pragma endregion FCdResultSuccesTests

// Test for ECdResultCode::Failed
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCdResultFailedTestI,
	"Cd.Result.Failed.I",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FCdResultFailedTestI::RunTest(const FString& Parameters)
{
	const FCdResult Result = FCdResult::Failed(
		ECdResultCode::Failed, 
		TEXT("ECdResultCode::Failed Test")
	);

	// Test for bSuccess == false
	TestFalse(TEXT("bSuccess should be false"), Result.bSuccess);

	// Test for Failed Code being ECdResultCode::Failed
	TestTrue(TEXT("Result Code is Failed"), Result.Code == ECdResultCode::Failed);

	// Testing to ensure Result.Message contains a message
	TestTrue(TEXT(""), !Result.Message.IsEmpty());

	return true;
}

#endif