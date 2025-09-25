# WlxLoggedOnSAS function

## Description

[The WlxLoggedOnSAS function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxLoggedOnSAS** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when it receives a [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event while the user is logged on and the workstation is not locked.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `dwSasType` [in]

Specifies the type of SAS that occurred. Values from zero to WLX_SAS_TYPE_MAX_MSFT_VALUE are reserved to define standard Microsoft SAS types. GINA developers can define additional SAS types by using values greater than WLX_SAS_TYPE_MAX_MSFT_VALUE.

The following SAS types are predefined.

| Value | Meaning |
| --- | --- |
| **WLX_SAS_TYPE_TIMEOUT**<br><br>0 (0x0) | Indicates that no user input was received within the specified time-out period. |
| **WLX_SAS_TYPE_CTRL_ALT_DEL**<br><br>1 (0x1) | Indicates that a user has typed the standard CTRL+ALT+DEL [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS). |
| **WLX_SAS_TYPE_SC_INSERT**<br><br>5 (0x5) | Indicates that a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) has been inserted into a compatible device. |
| **WLX_SAS_TYPE_SC_REMOVE**<br><br>6 (0x6) | Indicates that a smart card has been removed from a compatible device. |

### `pReserved` [in]

This parameter is reserved and must be set to **NULL**.

## Return value

The **WlxLoggedOnSAS** function should return one of the following values.

| Return code | Description |
| --- | --- |
| **WLX_SAS_ACTION_NONE** | Returns to the default desktop. |
| **WLX_SAS_ACTION_LOCK_WKSTA** | Locks the workstation and waits for the next SAS. |
| **WLX_SAS_ACTION_LOGOFF** | Logs the user off the workstation. |
| **WLX_SAS_ACTION_SHUTDOWN** | Logs the user off and shuts down the computer. |
| **WLX_SAS_ACTION_SHUTDOWN_REBOOT** | Logs the user off, shuts down the computer, and then restarts the computer. |
| **WLX_SAS_ACTION_SHUTDOWN_POWER_OFF** | If hardware allows, logs the user off, shuts down the computer, and then turns off the computer. |
| **WLX_SAS_ACTION_PWD_CHANGED** | Notifies network providers that the user changed their password. Obsolete GINA DLLs should call [WlxChangePasswordNotify](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_change_password_notify) whenever a password is changed. |
| **WLX_SAS_ACTION_TASKLIST** | Invokes the task list. |
| **WLX_SAS_ACTION_FORCE_LOGOFF** | Forcibly logs off the user. |
| **WLX_SAS_ACTION_SHUTDOWN_SLEEP** | Puts the computer in suspend mode. |
| **WLX_SAS_ACTION_SHUTDOWN_SLEEP2** | Shuts down the system into an ACPI power-down state. If the computer is not an ACPI computer, this option will have no effect. |
| **WLX_SAS_ACTION_SHUTDOWN_HIBERNATE** | Shuts down the system into the hibernate mode. If the system was not configured for hibernation, this option will have no effect. |

## Remarks

Winlogon calls **WlxLoggedOnSAS** when the logged-on user wants to shut down, log out, or lock the workstation. The [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL can lock the workstation by returning WLX_SAS_ACTION_LOCK_WKSTA. When this value is returned, [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) locks the workstation and calls
[WlxWkstaLockedSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxwkstalockedsas) the next time it receives an SAS.

Before calling **WlxLoggedOnSAS**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxWkstaLockedSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxwkstalockedsas)