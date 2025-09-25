# PWLX_CLOSE_USER_DESKTOP callback function

## Description

[The WlxCloseUserDesktop function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to close an alternate user desktop and clean up after the desktop is closed.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `pDesktop` [in]

Specifies a pointer to a
[WLX_DESKTOP](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_desktop) structure, obtained by calling the
[WlxCreateUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_create_user_desktop) function.

### `hToken` [in]

Specifies the handle to the token of the user whose desktop is to be closed.

## Return value

If the function successfully closes the desktop, the return value is **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

In addition to closing the desktop, this function will modify access to the parent window station to remove [ACEs](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) added during the creation of the user desktop.

## See also

[WLX_DESKTOP](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_desktop)

[WlxCreateUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_create_user_desktop)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)