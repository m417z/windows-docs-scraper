# IVirtualDesktopManager::IsWindowOnCurrentVirtualDesktop

## Description

Indicates whether the provided window is on the currently active virtual desktop.

## Parameters

### `topLevelWindow` [in]

The window of interest.

### `onCurrentDesktop` [out]

**True** if the *topLevelWindow* is on the currently active virtual desktop, otherwise **false**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVirtualDesktopManager](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-ivirtualdesktopmanager)