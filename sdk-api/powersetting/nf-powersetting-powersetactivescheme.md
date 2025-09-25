# PowerSetActiveScheme function

## Description

Sets the active power scheme for the current user.

## Parameters

### `UserRootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `SchemeGuid` [in]

The identifier of the power scheme.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)