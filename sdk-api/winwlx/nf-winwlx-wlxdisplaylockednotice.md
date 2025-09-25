# WlxDisplayLockedNotice function

## Description

[The WlxDisplayLockedNotice function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Allows the GINA to display information about the lock, such as who locked the workstation and when it was locked.

The **WlxDisplayLockedNotice** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when the workstation is placed in the locked state.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

Pointer to the GINA context associated with this window station. This is the context value that the GINA returns when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

## Remarks

To display lock information, the GINA must display a dialog box that will be interrupted by a WLX_WM_SAS message. For more information, see
[Sending Messages to the GINA](https://learn.microsoft.com/windows/desktop/SecAuthN/sending-messages-to-the-gina).

Before calling **WlxDisplayLockedNotice**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxDisplaySASNotice](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxdisplaysasnotice)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)