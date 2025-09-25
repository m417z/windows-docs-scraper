# WLX_DESKTOP structure

## Description

[The WLX_DESKTOP structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_DESKTOP** structure is used to pass desktop information between your [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL and [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly).

## Members

### `Size`

Specifies the size of the **WLX_DESKTOP** structure. Set to sizeof(WLX_DESKTOP).

### `Flags`

Specifies the valid fields. Specify one of the following.

| Value | Meaning |
| --- | --- |
| **WLX_DESKTOP_NAME** | Indicates that the name specified in **pszDesktopName** is valid. |
| **WLX_DESKTOP_HANDLE** | Indicates that the handle specified in **hDesktop** is valid. |

### `hDesktop`

A handle to the desktop returned by [CreateDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdesktopa) and [OpenDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-opendesktopa).

### `pszDesktopName`

Name of the desktop.

## See also

[WlxCreateUserDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_create_user_desktop)

[WlxGetSourceDesktop](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_get_source_desktop)