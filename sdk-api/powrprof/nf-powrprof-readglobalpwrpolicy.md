# ReadGlobalPwrPolicy function

## Description

[**ReadGlobalPwrPolicy** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. See Remarks.]

Retrieves the current global power policy settings.

## Parameters

### `pGlobalPowerPolicy` [out]

A pointer to a
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure that receives the information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure contains policy settings that are common to all power schemes. This structure contains both user and computer policy settings.

Starting with Windows Vista, use the [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) function to enumerate power settings for a specified scheme and the power read functions to retrieve individual settings.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[WriteGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writeglobalpwrpolicy)