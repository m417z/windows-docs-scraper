# ITaskbarList3::SetThumbnailTooltip

## Description

Specifies or updates the text of the tooltip that is displayed when the mouse pointer rests on an individual preview thumbnail in a taskbar button flyout.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle to the window whose thumbnail displays the tooltip. This handle must belong to the calling process.

### `pszTip` [in]

Type: **LPCWSTR**

The pointer to the text to be displayed in the tooltip. This value can be **NULL**, in which case the title of the window specified by *hwnd* is used as the tooltip.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)