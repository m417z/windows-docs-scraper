# IVirtualDesktopManager::MoveWindowToDesktop

## Description

Moves a window to the specified virtual desktop.

## Parameters

### `topLevelWindow` [in]

The window to move.

### `desktopId` [in]

The identifier of the virtual desktop to move the [GetWindowDesktopId](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-ivirtualdesktopmanager-getwindowdesktopid) to get a window's identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVirtualDesktopManager](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-ivirtualdesktopmanager)