# IShellLinkA::GetShowCmd

## Description

Gets the show command for a Shell link object.

## Parameters

### `piShowCmd`

Type: **int***

A pointer to the command. The following commands are supported.

#### SW_SHOWNORMAL

Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

#### SW_SHOWMAXIMIZED

Activates the window and displays it as a maximized window.

#### SW_SHOWMINIMIZED

Activates the window and displays it as a minimized window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The show command is used to set the initial show state of the corresponding object. This is one of the SW_xxx values described in [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow).

## See also

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)

[IShellLink::SetShowCmd](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setshowcmd)

**IShellLinkA**

**IShellLinkW**