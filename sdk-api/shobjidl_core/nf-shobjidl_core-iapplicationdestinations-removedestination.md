# IApplicationDestinations::RemoveDestination

## Description

Removes a single destination from the **Recent** and **Frequent** categories in a Jump List.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) that represents the destination to remove.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a standard COM error value otherwise. If the object pointed to by *punk* is not an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka), the method returns E_INVALIDARG.

## Remarks

A destination can appear in both the **Recent** and **Frequent** categories. If that is the case, this method removes the destination from both categories.

If the item is pinned to the list by the user, it is not removed but its usage data is cleared.

An application can call **RemoveDestination** without knowing if the item pointed to by *punk* is currently in the list. If there is no existing data on the item (in which case it is not in the **Recent** or **Frequent** list), this method does nothing and returns S_OK.

If the application has an explicit Application User Model ID (AppUserModelID), you must call [IApplicationDestinations::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-setappid) before you call this method.

## See also

[IApplicationDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdestinations)

[IApplicationDestinations::RemoveAllDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removealldestinations)

[IApplicationDestinations::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-setappid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)