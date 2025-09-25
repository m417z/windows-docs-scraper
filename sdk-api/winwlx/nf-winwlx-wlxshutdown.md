# WlxShutdown function

## Description

[The WlxShutdown function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxShutdown** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function just before shutting down, allowing the GINA to perform any shutdown tasks, such as ejecting a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from a [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `ShutdownType` [in]

Specifies the type of shutdown. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WLX_SAS_ACTION_SHUTDOWN**<br><br>5 (0x5) | Logs the user off and shuts down the computer. |
| **WLX_SAS_ACTION_SHUTDOWN_REBOOT**<br><br>11 (0xB) | Shuts down and restarts the computer. |
| **WLX_SAS_ACTION_SHUTDOWN_POWER_OFF**<br><br>10 (0xA) | Shuts down and turns off the computer, if the hardware allows. |

## Remarks

Winlogon calls **WlxShutdown** after the user has logged off and the
[WlxLogoff](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxlogoff) function has been called.

Before calling **WlxShutdown**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxLogoff](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxlogoff)