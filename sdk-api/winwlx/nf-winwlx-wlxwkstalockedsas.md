# WlxWkstaLockedSAS function

## Description

The **WlxWkstaLockedSAS** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when it receives a [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) and the workstation is locked. The GINA should return a value that indicates the workstation is to remain locked, the workstation is to be unlocked, or the logged-on user is to be logged off (which leaves the workstation locked until the logoff is completed).

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `dwSasType` [in]

Specifies the type of SAS that occurred. Values from zero to WLX_SAS_TYPE_MAX_MSFT_VALUE are reserved for standard Microsoft SAS types. GINA developers can use values greater than WLX_SAS_TYPE_MAX_MSFT_VALUE to define additional SAS types.

The following SAS types are predefined.

| Value | Meaning |
| --- | --- |
| **WLX_SAS_TYPE_CTRL_ALT_DEL** | Indicates a user has typed the standard CTRL+ALT+DEL [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS). |
| **WLX_SAS_TYPE_SC_INSERT** | Indicates that a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) has been inserted into a compatible device. |
| **WLX_SAS_TYPE_SC_REMOVE** | Indicates that a smart card has been removed from a compatible device. |
| **WLX_SAS_TYPE_TIMEOUT** | Indicates that no user input was received within the specified time-out period. |

## Return value

The **WlxWkstaLockedSAS** function should return the following values.

| Return code | Description |
| --- | --- |
| **WLX_SAS_ACTION_NONE** | Tells [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) to keep the workstation locked. |
| **WLX_SAS_ACTION_FORCE_LOGOFF** | Tells Winlogon to forcibly log the user off. |
| **WLX_SAS_ACTION_LOGOFF** | Tells Winlogon to log the current user off. |
| **WLX_SAS_ACTION_UNLOCK_WKSTA** | Tells Winlogon to unlock the workstation. |

## Remarks

Before calling **WlxWkstaLockedSAS**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)