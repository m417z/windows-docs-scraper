# AppPolicyGetClrCompat function

## Description

Retrieves a value indicating the application type of a process so that you can determine whether to enable private reflection and/or make managed objects agile.

## Parameters

### `processToken` [in]

A handle that identifies the access token for a process.

### `policy` [out]

A pointer to a variable of the [AppPolicyClrCompat](https://learn.microsoft.com/windows/win32/api/appmodel/ne-appmodel-apppolicyclrcompat) enumerated type. When the function returns successfully, the variable contains an enumerated constant value indicating the application type of the identified process.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If no known application type was found for the process token, the function raises a STATUS_ASSERTION_FAILURE exception and returns ERROR_NOT_FOUND.

If either processToken or policy are null, the function returns ERROR_INVALID_PARAMETER.