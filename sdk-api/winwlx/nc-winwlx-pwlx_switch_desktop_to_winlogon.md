# PWLX_SWITCH_DESKTOP_TO_WINLOGON callback function

## Description

[The WlxSwitchDesktopToWinlogon function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Allows the [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL switch to the [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) desktop.This function is valid only for the currently operating thread.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

## Return value

The **WlxSwitchDesktopToWinlogon** function returns zero if the function call succeeds. Otherwise, it returns an error code.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)