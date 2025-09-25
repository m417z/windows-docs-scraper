# IShellLinkW::SetShowCmd

## Description

Sets the show command for a Shell link object. The show command sets the initial show state of the window.

## Parameters

### `iShowCmd`

Type: **int**

Command. **SetShowCmd** accepts one of the following [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) commands.

#### SW_SHOWNORMAL

Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

#### SW_SHOWMAXIMIZED

Activates the window and displays it as a maximized window.

#### SW_SHOWMINNOACTIVE

Displays the window in its minimized state, leaving the currently active window as active.

##### - iShowCmd.SW_SHOWMAXIMIZED

Activates the window and displays it as a maximized window.

##### - iShowCmd.SW_SHOWMINNOACTIVE

Displays the window in its minimized state, leaving the currently active window as active.

##### - iShowCmd.SW_SHOWNORMAL

Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)

[IShellLink::GetShowCmd](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-getshowcmd)

**IShellLinkA**

**IShellLinkW**