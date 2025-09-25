# IApplicationDestinations::RemoveAllDestinations

## Description

Clears all destination entries from the **Recent** and **Frequent** categories in an application's Jump List.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not remove items that the user has pinned to the Jump List. Those items cannot be removed programmatically; only the user can remove them. However, it does remove usage data for those pinned items. It also cannot remove items from custom categories or the task list.

If the application has an explicit Application User Model ID (AppUserModelID), you must call [IApplicationDestinations::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-setappid) before you call this method.

## See also

[IApplicationDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdestinations)

[IApplicationDestinations::RemoveDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removedestination)

[IApplicationDestinations::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-setappid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)