# ITaskbarList2::MarkFullscreenWindow

## Description

Marks a window as full-screen.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the window to be marked.

### `fFullscreen` [in]

Type: **BOOL**

A Boolean value marking the desired full-screen status of the window.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Setting the value of *fFullscreen* to **TRUE**, the Shell treats this window as a full-screen window, and the taskbar is moved to the bottom of the z-order when this window is active. Setting the value of *fFullscreen* to **FALSE** removes the full-screen marking, but *does not* cause the Shell to treat the window as though it were definitely not full-screen. With a **FALSE** *fFullscreen* value, the Shell depends on its automatic detection facility to specify how the window should be treated, possibly still flagging the window as full-screen.

**Since Windows 7,** call `SetProp(hwnd, L”NonRudeHWND”, reinterpret_cast(TRUE))` before showing a window to indicate to the Shell that the window should not be treated as full-screen. This ensures the taskbar does not adjust itself to be below the window in z-order. This is similar to `ITaskbarList2::MarkFullscreenWindow(FALSE)` except the Shell will not fallback to its automatic detection facility and will not treat the window as full-screen.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[SetPropA](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setpropa)

[SetPropW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setpropw)