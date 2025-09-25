# ITaskbarList3::SetTabOrder

## Description

Inserts a new thumbnail into a tabbed-document interface (TDI) or multiple-document interface (MDI) application's group flyout or moves an existing thumbnail to a new position in the application's group.

## Parameters

### `hwndTab` [in]

Type: **HWND**

The handle of the tab window whose thumbnail is being placed. This value is required, must already be registered through [ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab), and cannot be **NULL**.

### `hwndInsertBefore` [in, optional]

Type: **HWND**

The handle of the tab window whose thumbnail that *hwndTab* is inserted to the left of. This handle must already be registered through [ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab). If this value is **NULL**, the new thumbnail is added to the end of the list.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method must be called for the thumbnail to be shown in the group. Call it after you have called [ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab).

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab)

[ITaskbarList3::SetTabActive](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settabactive)

[ITaskbarList3::UnregisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-unregistertab)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)