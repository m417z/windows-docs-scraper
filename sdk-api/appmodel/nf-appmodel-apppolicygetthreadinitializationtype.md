# AppPolicyGetThreadInitializationType function

## Description

Retrieves the kind of initialization that should be automatically performed for a process when beginthread[ex] creates a thread.

## Parameters

### `processToken` [in]

A handle that identifies the access token for a process.

### `policy` [out]

A pointer to a variable of the [AppPolicyThreadInitializationType](https://learn.microsoft.com/windows/desktop/api/appmodel/ne-appmodel-apppolicythreadinitializationtype) enumerated type. When the function returns successfully, the variable contains a value indicating the kind of initialization that should be automatically performed for the process when beginthread[ex] creates a thread.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If no known thread initialization policy was found for the process token, the function raises a STATUS_ASSERTION_FAILURE exception and returns ERROR_NOT_FOUND.

If either processToken or policy are null, the function returns ERROR_INVALID_PARAMETER.