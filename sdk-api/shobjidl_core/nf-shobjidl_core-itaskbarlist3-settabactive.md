# ITaskbarList3::SetTabActive

## Description

Informs the taskbar that a tab or document window has been made the active window.

## Parameters

### `hwndTab` [in]

Type: **HWND**

Handle of the active tab window. This handle must already be registered through [ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab). This value can be **NULL** if no tab is active.

### `hwndMDI` [in]

Type: **HWND**

Handle of the application's main window. This value tells the taskbar which group the thumbnail is a member of. This value is required and cannot be **NULL**.

### `dwReserved` [in]

Type: **DWORD**

Reserved; set to 0.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist)

[ITaskbarList2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist2)

[ITaskbarList3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist3)

[ITaskbarList3::RegisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-registertab)

[ITaskbarList3::SetTabOrder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-settaborder)

[ITaskbarList3::UnregisterTab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-unregistertab)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)