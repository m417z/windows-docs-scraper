# DeletePwrScheme function

## Description

[**DeletePwrScheme** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [PowerDeleteScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerdeletescheme) instead.]

Deletes the specified power scheme.

## Parameters

### `uiID` [in]

The index of the power scheme to be deleted.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications can call
**DeletePwrScheme** to permanently delete a power scheme. An attempt to delete the currently active power scheme fails with the last error set to ERROR_ACCESS_DENIED.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[WritePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writepwrscheme)