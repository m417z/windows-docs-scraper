# AuthzInitializeCompoundContext function

## Description

The **AuthzInitializeCompoundContext** function creates a user-mode context from the given user and device security contexts.

## Parameters

### `UserContext` [in]

User context to create the compound context from.

### `DeviceContext` [in]

Device context to create the compound context from. This must not be the same as the user context.

### `phCompoundContext` [out]

Used to return the resultant compound context.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).