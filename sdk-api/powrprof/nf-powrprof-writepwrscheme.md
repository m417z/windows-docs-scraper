# WritePwrScheme function

## Description

[**WritePwrScheme** is no longer available for use as of Windows Vista. Instead, use the [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) function to enumerate power settings for a specified scheme, and the power write functions to write individual settings.]

Writes policy settings that are unique to the specified power scheme.

## Parameters

### `puiID` [in]

The index of the power scheme to be written. If a power scheme with the same index already exists, it is replaced. Otherwise, a new power scheme is created.

### `lpszSchemeName` [in]

The name of the power scheme.

### `lpszDescription` [in, optional]

The description of the power scheme.

### `lpScheme` [in]

A pointer to a
[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy) structure that contains the power policy settings to be written.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This change does not affect the current system power policy. To apply this change to the current system power policy, call the
[SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme) function with the index of this power scheme.

Power policy schemes written using
**WritePwrScheme** are permanently stored in the system registry hives, and remain available for use in the Power Options control panel program, or by subsequent calls to the power scheme API. To permanently remove a power scheme from the system, call the
[DeletePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-deletepwrscheme) function.

For more information about using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[DeletePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-deletepwrscheme)

[POWER_POLICY](https://learn.microsoft.com/windows/desktop/api/powrprof/ns-powrprof-power_policy)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[ReadPwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-readpwrscheme)

[SetActivePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setactivepwrscheme)