# IAccessibilityDockingService::DockWindow

## Description

Docks the specified window handle to the specified monitor handle.

## Parameters

### `hwnd` [in]

The accessibility application window that will be docked on the passed monitor handle.

### `hMonitor` [in]

The monitor on which the accessibility application window will be docked.

### `cyRequested`

TBD

### `pCallback` [in]

The callback pointer on which the accessibility application will receive the [Undock](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iaccessibilitydockingservice-undockwindow) notification.

#### - uHeight [in]

The height at which the window will be docked, in pixels, if this function is successful. Must be less than or equal to the *puMaxHeight* variable retrieved from a call to the [GetAvailableSize](https://learn.microsoft.com/windows/desktop/com/iaccessibilitydockingservice-getavailablesize) method.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The window handle or monitor handle is not valid. |
| **E_ACCESSDENIED** | The calling process is not a UIAcess accessibility application or the calling process does not own the window. |
| **IMM_E_DOCKOCCUPIED** | There is already another window occupying the docking space. Only one window can be docked at a time. |
| **IMM_E_INSUFFICIENTHEIGHT** | The requested *uHeight* is larger than the maximum allowed docking height for the specified monitor. However, if this error code is being returned, it means that this monitor does support docking, though at a height indicated by a call to the [GetAvailableSize](https://learn.microsoft.com/windows/desktop/com/iaccessibilitydockingservice-getavailablesize) method. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_MONITOR_HANDLE)** | The monitor specified by the monitor handle does not support docking. |

## See also

[IAccessibilityDockingService](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iaccessibilitydockingservice)