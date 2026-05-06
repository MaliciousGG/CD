#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "Types/CdResult.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FCdResultSuccessTest,
	"Cd.Result.Success",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FCdResultSuccessTest::RunTest(const FString& Parameters)
{
	const FCdResult Result = FCdResult::Success();

	TestTrue(TEXT("Result should succeed"), Result.bSuccess);
	TestEqual(TEXT("Result code should be Success"), Result.Code, ECdResultCode::Success);
	TestTrue(TEXT("Message should be empty"), Result.Message.IsEmpty());

	return true;
}

#endif