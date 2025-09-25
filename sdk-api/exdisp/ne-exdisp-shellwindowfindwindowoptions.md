# ShellWindowFindWindowOptions enumeration

## Description

Specifies options for finding window in the Shell windows collection.

## Constants

### `SWFO_NEEDDISPATCH:0x1`

The window must have an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface.

### `SWFO_INCLUDEPENDING:0x2`

Include windows that were registered with [IShellWindows::RegisterPending](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-registerpending).

### `SWFO_COOKIEPASSED:0x4`

Causes [IShellWindows::FindWindowSW](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-findwindowsw) to interpret *pvarLoc* as a cookie rather than a PIDL.

## See also

[IShellWindows](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-ishellwindows)

[IShellWindows::FindWindowSW](https://learn.microsoft.com/windows/desktop/api/exdisp/nf-exdisp-ishellwindows-findwindowsw)