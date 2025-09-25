# ITaskbarList3::RegisterTab

## Description

Informs the taskbar that a new tab or document thumbnail has been provided for display in an application's taskbar group flyout.

## Parameters

### `hwndTab` [in]

Type: **HWND**

Handle of the tab or document window. This value is required and cannot be **NULL**.

### `hwndMDI` [in]

Type: **HWND**

Handle of the application's main window. This value tells the taskbar which application's preview group to attach the new thumbnail to. This value is required and cannot be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If either parameter is **NULL**, this method returns an error.

## Remarks

By itself, registering a tab thumbnail alone will not result in its being displayed. You must also call [ITaskbarList3::SetTabOrder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settaborder) to instruct the group where to display it.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::SetTabActive](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settabactive)

[ITaskbarList3::SetTabOrder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settaborder)

[ITaskbarList3::UnregisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-unregistertab)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)