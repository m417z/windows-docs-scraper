# PWLX_SET_RETURN_DESKTOP callback function

## Description

[The WlxSetReturnDesktop function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to specify the alternate application desktop that [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) will switch to when the current [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event processing function is complete.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `pDesktop` [in]

Pointer to desktop information about the alternate desktop. This desktop is created by calling the
[WlxCreateUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_create_user_desktop) function.

## Return value

The **WlxSetReturnDesktop** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The function call was successful. |
| **FALSE** | The function call failed to set the return desktop. |

## Remarks

**WlxSetReturnDesktop** can be called only within
[WlxLoggedOnSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedonsas) or
[WlxWkstaLockedSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxwkstalockedsas) routines. Attempts to call this function at other times will fail.

If a handle to the desktop is provided, Winlogon will duplicate the handle. If no handle is provided, Winlogon will attempt to open the desktop named in the *pDesktop* parameter. If the provided desktop is not valid or is the Winlogon or screen saver desktop, the call will fail.

## See also

[WlxCreateUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_create_user_desktop)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxLoggedOnSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxloggedonsas)

[WlxWkstaLockedSAS](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxwkstalockedsas)