# PowerDeleteScheme function

## Description

Deletes the specified power scheme from the database.

## Parameters

### `RootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `SchemeGuid` [in]

The identifier of the power scheme.

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)