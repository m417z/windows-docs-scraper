# PowerImportPowerScheme function

## Description

Imports a power scheme from a file.

## Parameters

### `RootPowerKey` [in]

This parameter is reserved for future use and must be set to **NULL**.

### `ImportFileNamePath` [in]

The path to a power scheme backup file created by **PowerCfg.Exe /Export**.

### `DestinationSchemeGuid` [in, out]

A pointer to a pointer to a **GUID**. If the pointer contains
**NULL**, the function allocates memory for a new
**GUID** and puts the address of this memory in the pointer. The caller can free this
memory using [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)