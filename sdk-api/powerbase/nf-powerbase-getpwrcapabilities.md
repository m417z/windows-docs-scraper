# GetPwrCapabilities function

## Description

Retrieves information about the system power capabilities.

## Parameters

### `lpspc` [out]

A pointer to a
[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities) structure that receives the information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function retrieves detailed information about the current system power management hardware resources and capabilities. This includes information about the presence of hardware features such as power buttons, lid switches, and batteries. Other details returned include information about current power management capabilities and configurations that can change dynamically, such as the minimum sleep state currently supported, which may change as new drivers are introduced into the system, or the presence of the system hibernation file.

This information is also available through the
[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation) function, using the SystemPowerCapabilities level.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SYSTEM_POWER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_power_capabilities)