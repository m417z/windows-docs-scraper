# WlxDisplaySASNotice function

## Description

[The WlxDisplaySASNotice function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxDisplaySASNotice** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when no user is logged on.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. This is the context value that the GINA returns when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

## Remarks

Before calling **WlxDisplaySASNotice**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)