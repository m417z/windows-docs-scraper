# SHAppBarMessage function

## Description

Sends an appbar message to the system.

## Parameters

### `dwMessage` [in]

Type: **DWORD**

Appbar message value to send. This parameter can be one of the following values.

#### ABM_NEW (0x00000000)

Registers a new appbar and specifies the message identifier that the system should use to send notification messages to the appbar.

#### ABM_REMOVE (0x00000001)

Unregisters an appbar, removing the bar from the system's internal list.

#### ABM_QUERYPOS (0x00000002)

Requests a size and screen position for an appbar.

#### ABM_SETPOS (0x00000003)

Sets the size and screen position of an appbar.

#### ABM_GETSTATE (0x00000004)

Retrieves the autohide and always-on-top states of the Windows taskbar.

#### ABM_GETTASKBARPOS (0x00000005)

Retrieves the bounding rectangle of the Windows taskbar. Note that this applies only to the system taskbar. Other objects, particularly toolbars supplied with third-party software, also can be present. As a result, some of the screen area not covered by the Windows taskbar might not be visible to the user. To retrieve the area of the screen not covered by both the taskbar and other app bars—the working area available to your application—, use the [GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) function.

#### ABM_ACTIVATE (0x00000006)

Notifies the system to activate or deactivate an appbar. The **lParam** member of the [APPBARDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-appbardata) pointed to by *pData* is set to **TRUE** to activate or **FALSE** to deactivate.

#### ABM_GETAUTOHIDEBAR (0x00000007)

Retrieves the handle to the autohide appbar associated with a particular edge of the screen.

#### ABM_SETAUTOHIDEBAR (0x00000008)

Registers or unregisters an autohide appbar for an edge of the screen.

#### ABM_WINDOWPOSCHANGED (0x00000009)

Notifies the system when an appbar's position has changed.

#### ABM_SETSTATE (0x0000000A)

**Windows XP and later:** Sets the state of the appbar's autohide and always-on-top attributes.

#### ABM_GETAUTOHIDEBAREX (0x0000000B)

**Windows XP and later:** Retrieves the handle to the autohide appbar associated with a particular edge of a particular monitor.

#### ABM_SETAUTOHIDEBAREX (0x0000000C)

**Windows XP and later:** Registers or unregisters an autohide appbar for an edge of a particular monitor.

### `pData` [in, out]

Type: **PAPPBARDATA**

A pointer to an [APPBARDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-appbardata) structure. The content of the structure on entry and on exit depends on the value set in the *dwMessage* parameter. See the individual message pages for specifics.

## Return value

Type: **UINT_PTR**

This function returns a message-dependent value. For more information, see the Windows SDK documentation for the specific appbar message sent. Links to those documents are given in the See Also section.

## See also

[ABM_ACTIVATE](https://learn.microsoft.com/windows/desktop/shell/abm-activate)

[ABM_GETAUTOHIDEBAR](https://learn.microsoft.com/windows/desktop/shell/abm-getautohidebar)

[ABM_GETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-getautohidebarex)

[ABM_GETSTATE](https://learn.microsoft.com/windows/desktop/shell/abm-getstate)

[ABM_GETTASKBARPOS](https://learn.microsoft.com/windows/desktop/shell/abm-gettaskbarpos)

[ABM_NEW](https://learn.microsoft.com/windows/desktop/shell/abm-new)

[ABM_QUERYPOS](https://learn.microsoft.com/windows/desktop/shell/abm-querypos)

[ABM_REMOVE](https://learn.microsoft.com/windows/desktop/shell/abm-remove)

[ABM_SETAUTOHIDEBAR](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebar)

[ABM_SETAUTOHIDEBAREX](https://learn.microsoft.com/windows/desktop/shell/abm-setautohidebarex)

[ABM_SETPOS](https://learn.microsoft.com/windows/desktop/shell/abm-setpos)

[ABM_SETSTATE](https://learn.microsoft.com/windows/desktop/shell/abm-setstate)

[ABM_WINDOWPOSCHANGED](https://learn.microsoft.com/windows/desktop/shell/abm-windowposchanged)