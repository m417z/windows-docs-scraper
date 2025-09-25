# GetCurrentPowerPolicies function

## Description

Retrieves the current system power policy settings.

## Parameters

### `pGlobalPowerPolicy` [out]

A pointer to a
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure that receives the current global power policy settings.

### `pPowerPolicy` [out]

A pointer to a
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure that receives the power policy settings that are unique to the active power scheme.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To update the current power policy settings, call the
[WriteGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writeglobalpwrpolicy) or
[WritePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writepwrscheme) functions.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy)

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[WriteGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writeglobalpwrpolicy)

[WritePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writepwrscheme)