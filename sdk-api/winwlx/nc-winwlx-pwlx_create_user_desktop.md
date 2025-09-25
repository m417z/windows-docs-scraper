# PWLX_CREATE_USER_DESKTOP callback function

## Description

[The WlxCreateUserDesktop function is no longer available for use as of Windows Server 2008 and Windows Vista.]

Called by [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) to create alternate application desktops for the user.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `hWlx` [in]

Specifies the Winlogon handle passed to GINA in the
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) call.

### `hToken` [in]

Specifies the handle to the token of the user for whom the desktop is being created.

### `Flags` [in]

Specifies access to the desktop. Specify one of the following.

| Value | Meaning |
| --- | --- |
| **WLX_CREATE_INSTANCE_ONLY** | Specifies that only this instance of the user has access. |
| **WLX_CREATE_USER** | Specifies that any instance of this user has access. |

### `pszDesktopName` [in]

Specifies the name of the desktop to be created.

### `ppDesktop` [out]

If the desktop is created, returns a pointer to a
[WLX_DESKTOP](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_desktop) structure for the new desktop. This pointer can be used in a call to
[WlxSetReturnDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_return_desktop) to make this the current desktop after a [SAS](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) event is processed.

## Return value

The **WlxCreateUserDesktop** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The desktop has been created. |
| **FALSE** | The desktop has not been created. |

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)

[WlxSetReturnDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_return_desktop)