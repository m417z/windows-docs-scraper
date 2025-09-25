# DdQueryDisplaySettingsUniqueness function

## Description

[This function is subject to change with each operating system revision. Instead, use
the Microsoft DirectDraw and Microsoft Direct3DAPIs; these
APIs insulate applications from such operating system changes, and hide many other
difficulties involved in interacting directly with display drivers.]

Returns the current value of an integer that is incremented whenever a mode switch occurs, such as when there
is a desktop switch, a Fast User Switch, or a full-screen Microsoft MS-DOS box. The application can call
this function repeatedly and compare the old and new values of the return value to determine whether display
settings have changed.

**GdiEntry13** is defined as an alias for this function.

## Return value

The current value of the mode switch integer is returned.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)