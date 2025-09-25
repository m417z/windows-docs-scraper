# SetSystemPowerState function

## Description

[**SetSystemPowerState** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [SetSuspendState](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setsuspendstate) instead.]

Suspends the system by shutting power down. Depending on the *ForceFlag*
parameter, the function either suspends operation immediately or requests permission from all applications and
device drivers before doing so.

## Parameters

### `fSuspend` [in]

If this parameter is **TRUE**, the system is suspended. If the parameter is
**FALSE**, the system hibernates.

### `fForce` [in]

This parameter has no effect.

## Return value

If power has been suspended and subsequently restored, the return value is nonzero.

If the system was not suspended, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must have the **SE_SHUTDOWN_NAME** privilege. To enable the
**SE_SHUTDOWN_NAME** privilege, use the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function. For more
information, see [Changing Privileges in a
Token](https://learn.microsoft.com/windows/desktop/SecBP/changing-privileges-in-a-token).

If any application or driver denies permission to suspend operation, the function broadcasts a
[PBT_APMQUERYSUSPENDFAILED](https://learn.microsoft.com/windows/desktop/Power/pbt-apmquerysuspendfailed) event to each
application and driver. If power is suspended, this function returns only after system operation is resumed and
related [WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast) messages have been broadcast
to all applications and drivers.

This function is similar to the [SetSuspendState](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setsuspendstate)
function.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0400 or later. For more
information, see [Using the Windows
Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[PBT_APMQUERYSUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmquerysuspend)

[PBT_APMQUERYSUSPENDFAILED](https://learn.microsoft.com/windows/desktop/Power/pbt-apmquerysuspendfailed)

[PBT_APMSUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmsuspend)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SetSuspendState](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-setsuspendstate)

[WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast)