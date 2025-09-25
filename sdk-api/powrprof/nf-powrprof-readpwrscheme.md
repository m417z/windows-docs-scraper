# ReadPwrScheme function

## Description

[**ReadPwrScheme** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. See Remarks.]

Retrieves the power policy settings that are unique to the specified power scheme.

## Parameters

### `uiID` [in]

The index of the power scheme to be read.

### `pPowerPolicy` [out]

A pointer to a
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure that receives the power policy settings.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the power scheme specified does not exist, the function returns **FALSE**.

To retrieve information about the power policy settings currently in use by the system, call the
[GetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getactivepwrscheme) function. To retrieve additional information about the current power policy settings, call the
[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation) function.

Starting with Windows Vista, use the [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) function to enumerate power settings for a specified scheme and the power read functions to retrieve individual settings.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[GetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getactivepwrscheme)

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[WritePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writepwrscheme)