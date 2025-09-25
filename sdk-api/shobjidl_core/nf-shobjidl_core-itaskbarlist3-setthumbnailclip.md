# ITaskbarList3::SetThumbnailClip

## Description

Selects a portion of a window's client area to display as that window's thumbnail in the taskbar.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle to a window represented in the taskbar.

### `prcClip` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies a selection within the window's client area, relative to the upper-left corner of that client area. To clear a clip that is already in place and return to the default display of the thumbnail, set this parameter to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)