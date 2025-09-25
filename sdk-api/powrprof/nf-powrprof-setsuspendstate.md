# SetSuspendState function

## Description

Suspends the system by shutting power down. Depending on the *Hibernate*
parameter, the system either enters a suspend (sleep) state or hibernation (S4).

## Parameters

### `bHibernate` [in]

If this parameter is **TRUE**, the system hibernates. If the parameter is
**FALSE**, the system is suspended.

### `bForce` [in]

This parameter has no effect.

### `bWakeupEventsDisabled` [in]

If this parameter is **TRUE**, the system disables all wake events. If the parameter
is **FALSE**, any system wake events remain enabled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must have the **SE_SHUTDOWN_NAME** privilege. To enable the
**SE_SHUTDOWN_NAME** privilege, use the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function. For more
information, see [Changing Privileges in a
Token](https://learn.microsoft.com/windows/desktop/SecBP/changing-privileges-in-a-token).

An application may use **SetSuspendState** to
transition the system from the working state to the standby (sleep), or optionally, hibernate (S4) state. This
function is similar to the [SetSystemPowerState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setsystempowerstate)
function.

For more information on using PowrProf.h, see
[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes). For information about events that can wake the system, see [System Wake-up Events](https://learn.microsoft.com/windows/desktop/Power/system-wake-up-events).

## See also

[PBT_APMQUERYSUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmquerysuspend)

[PBT_APMSUSPEND](https://learn.microsoft.com/windows/desktop/Power/pbt-apmsuspend)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)