# ICustomDestinationList::CommitList

## Description

Declares that the Jump List initiated by a call to [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) is complete and ready for display.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As long as no call to [AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory) in this session failed for attempting to include a removed item, calling **CommitList** causes the stored list of removed items to be cleared and a new list of removed items to begin.

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)