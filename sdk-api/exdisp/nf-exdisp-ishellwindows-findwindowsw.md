# IShellWindows::FindWindowSW

## Description

Finds a window in the Shell windows collection and returns the window's handle and [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface.

## Parameters

### `pvarLoc` [in]

Type: **VARIANT***

A [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) of type VT_VARIANT | VT_BYREF. Set the value of *pvarLoc* to an absolute [PIDL](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (PIDLIST_ABSOLUTE) that specifies the window to find. (See remarks.)

### `pvarLocRoot` [in]

Type: **VARIANT***

Must be **NULL** or of type VT_EMPTY.

### `swClass` [in]

Type: **int**

One or more [ShellWindowTypeConstants](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowtypeconstants) flags that specify window types to include in the search.

### `phwnd` [out]

Type: **long***

A handle for the window matching the specified search criteria, or **NULL** if no such window was found.

### `swfwOptions`

Type: **int**

One or more [ShellWindowFindWindowOptions](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowfindwindowoptions) flags that specify search options.

### `ppdispOut` [out, retval]

Type: **[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)****

A reference to the window's [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface, or **NULL** if no such window was found.

## Return value

Type: **HRESULT**

One of the following values, or a standard result code.

| Return code | Description |
| --- | --- |
| **S_OK** | A window matching the specified search criteria was found. |
| **S_FALSE** | A window matching the specified search criteria was not found. |
| **E_NOINTERFACE** | A window was found, but a reference to the window's [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface could not be obtained. Only occurs if the [SWFO_NEEDDISPATCH](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowfindwindowoptions) flag is set. |
| **E_PENDING** | A window was found, but the window is pending open. Only occurs if the [SWFO_INCLUDEPENDING](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowfindwindowoptions) flag is set. |

## Remarks

If the [SWFO_COOKIEPASSED](https://learn.microsoft.com/windows/desktop/api/exdisp/ne-exdisp-shellwindowfindwindowoptions) flag is set, *pvarLoc* is interpreted as a cookie instead of a PIDL.