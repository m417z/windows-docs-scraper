# CM_WaitNoPendingInstallEvents function

## Description

The **CMP_WaitNoPendingInstallEvents** (CM_WaitNoPendingInstallEvents) function waits until there are no pending device installation activities for the PnP manager to perform.

## Parameters

### `dwTimeout` [in]

Specifies a time-out interval, in milliseconds.

* If *dwTimeout* is set to zero, the function tests whether there are pending installation events and returns immediately.
* If *dwTimeout* is set to INFINITE (defined in *Winbase.h*), the function's time-out interval never elapses.
* For all other *dwTimeout* values, the function returns when the specified interval elapses, even if there are still pending installation events.

## Return value

The function returns one of the following values (defined in *Winbase.h*):

| Return code | Description |
| --- | --- |
| **WAIT_OBJECT_0** | There are no pending installation activities. |
| **WAIT_TIMEOUT** | The time-out interval elapsed, and installation activities are still pending. |
| **WAIT_FAILED** | The function failed. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) for additional error information. |

## Remarks

The function waits for an internal event object, which the PnP manager sets when it determines that no installation activities are pending.

If a non-zero time-out value is specified, then **CMP_WaitNoPendingInstallEvents** will return either when no installation events are pending or when the time-out period has expired, whichever comes first.

New installation events can occur at any time. This function just indicates that there are no pending installation activities at the moment it is called.

This function is typically used by [device installation applications](https://learn.microsoft.com/windows-hardware/drivers/). For more information, see [Writing a Device Installation Application](https://learn.microsoft.com/windows-hardware/drivers/install/writing-a-device-installation-application).

Do not call this function while processing any events inside of a system-initiated callback function that is expected to return within a short amount of time. This includes service startup (for example in the **ServiceMain** callback function) or while processing any control in the service handler (for example, the **Handler** callback function), or from installation components such as class-installers or co-installers.

For Windows XP (with no service pack installed), this function must be called from [session zero](https://learn.microsoft.com/windows-hardware/drivers/), with administrator privileges. For Windows XP with Service Pack 1 (SP1) and later versions of Windows, the function can be called from any session, and administrator privileges are not required.

## See also

[CM_WaitNoPendingInstallEvents](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_waitnopendinginstallevents)

[How a Device Installation Application checks for in-progress device installations](https://learn.microsoft.com/windows-hardware/drivers/install/checking-for-in-progress-installations)