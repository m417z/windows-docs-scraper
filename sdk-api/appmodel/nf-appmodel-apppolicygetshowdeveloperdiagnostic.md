# AppPolicyGetShowDeveloperDiagnostic function

## Description

Retrieves the method used for a process to surface developer information, such as asserts, to the user.

## Parameters

### `processToken` [in]

A handle that identifies the access token for a process.

### `policy` [out]

A pointer to a variable of the [AppPolicyShowDeveloperDiagnostic](https://learn.microsoft.com/windows/desktop/api/appmodel/ne-appmodel-apppolicyshowdeveloperdiagnostic) enumerated type. When the function returns successfully, the variable contains a value indicating the method used for the process to surface developer information, such as asserts, to the user.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If no known developer information policy was found for the process token, the function raises a STATUS_ASSERTION_FAILURE exception and returns ERROR_NOT_FOUND.

If either processToken or policy are null, the function returns ERROR_INVALID_PARAMETER.