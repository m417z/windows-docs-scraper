# IsPwrHibernateAllowed function

## Description

[**IsPwrHibernateAllowed** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [GetPwrCapabilities](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-getpwrcapabilities) instead.]

Determines whether the computer supports hibernation.

## Return value

If the computer supports hibernation (power state S4) and the file Hiberfil.sys is present on the system, the function returns **TRUE**. Otherwise, the function returns **FALSE**.

## Remarks

This information is also available through the
[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation) function. The value is returned in the **SystemS4** member of the
[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities) structure.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities)