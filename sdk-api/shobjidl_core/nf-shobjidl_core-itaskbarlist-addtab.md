# ITaskbarList::AddTab

## Description

Adds an item to the taskbar.

## Parameters

### `hwnd`

Type: **HWND**

A handle to the window to be added to the taskbar.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Any type of window can be added to the taskbar, but it is recommended that the window at least have the [WS_CAPTION](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style.

Any window added with this method must be removed with the [DeleteTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist-deletetab) method when the added window is destroyed.