# AppPolicyGetProcessTerminationMethod function

## Description

Retrieves the method used to end a process.

## Parameters

### `processToken` [in]

A handle that identifies the access token for a process.

### `policy` [out]

A pointer to a variable of the [AppPolicyProcessTerminationMethod](https://learn.microsoft.com/windows/desktop/api/appmodel/ne-appmodel-apppolicyprocessterminationmethod) enumerated type. When the function returns successfully, the variable contains a value indicating the method used to end the process.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If no known process termination policy was found for the process token, the function raises a STATUS_ASSERTION_FAILURE exception and returns ERROR_NOT_FOUND.

If either processToken or policy are null, the function returns ERROR_INVALID_PARAMETER.