# IsPwrSuspendAllowed function

## Description

[**IsPwrSuspendAllowed** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [GetPwrCapabilities](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-getpwrcapabilities) instead.]

Determines whether the computer supports the sleep states.

## Return value

If the computer supports the sleep states (S1, S2, and S3), the function returns **TRUE**. Otherwise, the function returns **FALSE**.

## Remarks

This information is also available through the
[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation) function. Check the **SystemS1**, **SystemS2**, and **SystemS3** members of the
[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities) structure.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities)