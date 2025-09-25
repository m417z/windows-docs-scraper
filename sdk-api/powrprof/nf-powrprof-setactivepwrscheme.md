# SetActivePwrScheme function

## Description

[**SetActivePwrScheme** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use
[PowerSetActiveScheme](https://learn.microsoft.com/windows/desktop/api/powersetting/nf-powersetting-powersetactivescheme) instead.]

Sets the active power scheme.

## Parameters

### `uiID` [in]

The index of the power scheme to be activated.

### `pGlobalPowerPolicy` [in, optional]

A pointer to an optional
[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy) structure, which provides global power policy settings to be merged with the power scheme when it becomes active.

### `pPowerPolicy` [in, optional]

A pointer to an optional
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure, which provides power policy settings to be merged with the power scheme when it becomes active.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use this function to make long-term changes to the system configuration. To temporarily keep the system running while an application is performing a task, use the [SetThreadExecutionState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadexecutionstate) function.

If the power scheme specified by *uiID* does not exist, the function returns zero.

If *lpGlobalPowerPolicy* is **NULL**, the function uses the current global power policy settings set by
[WriteGlobalPwrPolicy](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writeglobalpwrpolicy). Otherwise, the settings in the specified structure replace the current global power policy settings.

If *lpPowerPolicy* is **NULL**, the function uses the current power policy settings for the power scheme. Otherwise, the settings in the specified structure replace the current power policy settings.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[GLOBAL_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-global_power_policy)

[GetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-getactivepwrscheme)

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)