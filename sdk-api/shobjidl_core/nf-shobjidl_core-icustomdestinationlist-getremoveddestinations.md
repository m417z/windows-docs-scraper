# ICustomDestinationList::GetRemovedDestinations

## Description

Retrieves the current list of destinations that have been removed by the user from the existing Jump List that this custom Jump List is meant to replace.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IObjectArray.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically an [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray), which represents a collection of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) objects that represent the items in the list of removed destinations.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Items can be removed from the Jump List UI through user action. The item is then marked as removed and is no longer displayed. An application can use this method to tell which items the user has removed so that it knows not to show them in its custom list. For instance, this method should be called when an application is launched, if that application is not going to generate a new list through [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist).

It is strongly recommended that an application clear any destination tracking data when the user elects to remove that destination. If the user accesses that destination again in the future, it may be re-added to the Jump List and can again accumulate data. The same removed destinations list retrieved by this method is retrieved when [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) is called. In that case, the application must not immediately attempt to reinsert any removed item or that call to [AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory) will fail. This ensures that the application respects the user's intent to remove the item.

If the application has an explicit Application User Model ID (AppUserModelID), you must call [SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-setappid) before calling this method.

Even if an application calls **GetRemovedDestinations** and finds an item on the list that has a high probability to be restored to the Jump List sooner than a new custom Jump List is expected to be created, the application should write the Jump List without that item and re-add it to the list only after the user has again accessed it.

An application can add a **Recent** or **Frequent** [known category](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendknowncategory) to its custom Jump List. Items in that category might be in the removed items list even though they were not shown in any custom category. In that case, the application should still clear any usage data for that item if any had been stored.

A call to **GetRemovedDestinations** does not clear the removed destinations data. This data is needed by [BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) for its next list generation. The removed destinations data is no longer needed and is cleared after a list generation session is begun by **BeginList**, continued with no failed calls to **AppendCategory**, and completed by a call to [CommitList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-commitlist).

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)