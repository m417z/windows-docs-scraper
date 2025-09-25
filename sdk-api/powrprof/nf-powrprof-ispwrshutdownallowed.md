# IsPwrShutdownAllowed function

## Description

[**IsPwrShutdownAllowed** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. See Remarks.]

Determines whether the computer supports the soft off power state.

## Return value

If the computer supports soft off (power state S5), the function returns **TRUE**. Otherwise, the function returns **FALSE**.

## Remarks

This information is also available through the
[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation) function. The value is returned in the **SystemS5** member of the
[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities) structure.

Starting with Windows Vista, computers must support the soft off power state. Therefore, this function is relevant only to Windows Server 2003 and earlier operating systems.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities)