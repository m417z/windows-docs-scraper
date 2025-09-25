# WriteGlobalPwrPolicy function

## Description

[**WriteGlobalPwrPolicy** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. See Remarks.]

Writes global power policy settings.

## Parameters

### `pGlobalPowerPolicy` [in]

A pointer to a
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure that contains the power policy settings to be written.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function replaces any existing global power policy settings. Each user has a separate global power scheme, which contains power policy settings that apply to all power schemes for that user.

Starting with Windows Vista, use the [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) function to enumerate power settings for a specified scheme and the power write functions to write individual settings.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[ReadGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readglobalpwrpolicy)