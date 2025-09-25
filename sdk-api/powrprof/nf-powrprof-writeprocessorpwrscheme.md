# WriteProcessorPwrScheme function

## Description

[**WriteProcessorPwrScheme** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. See Remarks.]

Writes processor power policy settings for the specified power scheme.

## Parameters

### `uiID` [in]

The index of the power scheme to be written.

### `pMachineProcessorPowerPolicy` [in]

A pointer to a
[MACHINE_PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-machine_processor_power_policy) structure that contains the power policy settings to be written.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This change does not affect the current system power policy. To apply this change to the current system power policy, call the
[SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme) function, using the index of this power scheme.

Starting with Windows Vista, power management configuration of the system's processor is controlled through the GUID_PROCESSOR_SETTINGS_SUBGROUP power settings subgroup. Use the [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) function to enumerate individual settings.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[MACHINE_PROCESSOR_POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-machine_processor_power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[ReadProcessorPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readprocessorpwrscheme)