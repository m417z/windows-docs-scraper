# ICustomDestinationList::AbortList

## Description

Discontinues a Jump List building session initiated by [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) without committing any changes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method allows an application to use a single [ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist) object for many transactions, because a session can be terminated without committing any new data or destroying the previously stored list.

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)