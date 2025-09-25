# ITaskbarList4::SetTabProperties

## Description

Allows a tab to specify whether the main application frame window or the tab window should be used as a thumbnail or in the peek feature under certain circumstances.

## Parameters

### `hwndTab` [in]

Type: **HWND**

The handle of the tab window that is to have properties set. This handle must already be registered through [RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab).

### `stpFlags` [in]

Type: **[STPFLAG](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-stpflag)**

One or more members of the [STPFLAG](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-stpflag) enumeration that specify the displayed thumbnail and peek image source of the tab thumbnail.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application might want to use the thumbnail or peek representation of its associated parent window if the application cannot generate its own thumbnail for a tab or for its active tab content (such as an animation) to appear live.

## See also

[ITaskbarList4](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist4)