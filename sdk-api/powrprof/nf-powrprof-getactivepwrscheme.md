# GetActivePwrScheme function

## Description

[**GetActivePwrScheme** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [PowerGetActiveScheme](https://learn.microsoft.com/windows/desktop/api/powersetting/nf-powersetting-powergetactivescheme) instead.]

Retrieves the index of the active power scheme.

## Parameters

### `puiID` [out]

A pointer to a variable that receives the index of the active power scheme.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The active power scheme remains active until either the user sets a new power scheme using the Power Options control panel program, or an application calls the
[SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme) function.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme)