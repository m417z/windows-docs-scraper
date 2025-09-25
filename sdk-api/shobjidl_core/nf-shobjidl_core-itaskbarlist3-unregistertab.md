# ITaskbarList3::UnregisterTab

## Description

Removes a thumbnail from an application's preview group when that tab or document is closed in the application.

## Parameters

### `hwndTab` [in]

Type: **HWND**

The handle of the tab window whose thumbnail is being removed. This is the same value with which the thumbnail was registered as part the group through [ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab). This value is required and cannot be **NULL**.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or an error value otherwise. If *hwndTab* is **NULL**, this method returns an error.

## Remarks

It is the responsibility of the calling application to free *hwndTab* through [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow). **UnregisterTab** must be called before the handle is freed.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab)

[ITaskbarList3::SetTabActive](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settabactive)

[ITaskbarList3::SetTabOrder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settaborder)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)