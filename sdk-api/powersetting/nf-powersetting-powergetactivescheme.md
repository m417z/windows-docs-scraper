# PowerGetActiveScheme function

## Description

Retrieves the active power scheme and returns a **GUID** that identifies the
scheme.

## Parameters

### `UserRootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `ActivePolicyGuid` [out]

A pointer that receives a pointer to a **GUID** structure.
Use the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free this memory.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)