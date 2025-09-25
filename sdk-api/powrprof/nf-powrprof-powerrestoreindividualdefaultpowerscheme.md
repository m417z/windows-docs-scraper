# PowerRestoreIndividualDefaultPowerScheme function

## Description

Replaces a specific power scheme for the current user with one from the default user (stored in
**HKEY_USERS**\**.Default**)

## Parameters

### `SchemeGuid` [in]

The identifier of the power scheme.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)