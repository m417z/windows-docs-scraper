# PowerDuplicateScheme function

## Description

Duplicates an existing power scheme.

## Parameters

### `RootPowerKey` [in, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `SourceSchemeGuid` [in]

The identifier of the power scheme that is to be duplicated.

### `DestinationSchemeGuid` [in]

The address of a pointer to a **GUID**. If the pointer contains
**NULL**, the function allocates memory for a new
**GUID** and puts the address of this memory in the pointer. The caller can free this
memory using [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## Return value

Returns **ERROR_SUCCESS** (zero) if the call was successful, and a nonzero value if
the call failed.

| Return code/value | Description |
| --- | --- |
| ****ERROR_SUCCESS****<br><br>0 (0x0) | The power scheme was successfully duplicated. |
| ****ERROR_INVALID_PARAMETER****<br><br>87 (0x57) | One of the parameters is not valid. |
| ****ERROR_ALREADY_EXISTS****<br><br>183 (0xB7) | The *DestinationSchemeGuid* parameter refers to an existing power scheme. [PowerDeleteScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerdeletescheme) can be used to delete this scheme. |

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)