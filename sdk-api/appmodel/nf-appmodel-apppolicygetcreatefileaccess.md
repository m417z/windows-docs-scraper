# AppPolicyGetCreateFileAccess function

## Description

Retrieves a value indicating whether a process has full or restricted access to the IO devices (file, file stream, directory, physical disk, volume, console buffer, tape drive, communications resource, mailslot, and pipe).

## Parameters

### `processToken` [in]

A handle that identifies the access token for a process.

### `policy` [out]

A pointer to a variable of the [AppPolicyCreateFileAccess](https://learn.microsoft.com/windows/desktop/api/appmodel/ne-appmodel-apppolicycreatefileaccess) enumerated type. When the function returns successfully, the variable contains an enumerated constant value indicating whether the process has full or restricted access to the IO devices.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If no known create file access policy was found for the process token, the function raises a STATUS_ASSERTION_FAILURE exception and returns ERROR_NOT_FOUND.

If either processToken or policy are null, the function returns ERROR_INVALID_PARAMETER.