# IVirtualDesktopManager::GetWindowDesktopId

## Description

Gets the identifier for the virtual desktop hosting the provided top-level window.

## Parameters

### `topLevelWindow` [in]

The top level window for the virtual desktop you are interested in.

### `desktopId` [out]

The identifier for the virtual desktop hosting the *topLevelWindow*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IVirtualDesktopManager](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-ivirtualdesktopmanager)