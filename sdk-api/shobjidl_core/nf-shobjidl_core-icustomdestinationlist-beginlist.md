# ICustomDestinationList::BeginList

## Description

Initiates a building session for a custom Jump List.

## Parameters

### `pcMinSlots` [out]

Type: **UINT***

A pointer that, when this method returns, points to the current user setting for the **Number of recent items to display in Jump Lists** option in the **Taskbar and Start Menu Properties** window. The default value is 10. This is the maximum number of destinations that will be shown, and it is a total of all destinations, regardless of category. More destinations can be added, but they will not be shown in the UI.

A Jump List will always show at least this many slots—destinations and, if there is room, tasks.

This number does not include separators and section headers as long as the total number of separators and headers does not exceed four. Separators and section headers beyond the first four might reduce the number of destinations displayed if space is constrained. This number does not affect the standard command entries for pinning or unpinning, closing the window, or launching a new instance. It also does not affect tasks or pinned items, the number of which that can be displayed is based on the space available to the Jump List.

### `riid` [in]

Type: **REFIID**

A reference to the IID of an interface to be retrieved in *ppv*, typically IID_IObjectArray, that will represent all items currently stored in the list of removed destinations for the application. This information is used to ensure that removed items are not part of the new Jump List.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically an [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray), which represents a collection of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) and [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) objects that represent the removed items.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If an application has an explicit Application User Model ID (AppUserModelID), you must call [ICustomDestinationList::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-setappid) before you call this method.

The [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) interface retrieved in the *ppv* parameter represents the same list of removed destinations that is retrieved through [GetRemovedDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-getremoveddestinations). When a new Jump List is being generated, applications must first process any removed destinations. Tracking data for any item in the removed list must be cleared. If an application attempts to include an item through [AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory) that is present in this removed destinations list, the **AppendCategory** call fails. This ensures that applications respect the user's choice of removed items. After a call to [CommitList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-commitlist) is made with no failed call to **AppendCategory** due to an attempt to re-add a removed item having been made since **BeginList**, the removed destinations list is cleared. After that time, a previously removed item can return to the destinations list if the user continues to use the item.

**BeginList** must be called to initiate the list before any calls are made to populate it through [AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory), [AppendKnownCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendknowncategory), or [AddUserTasks](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-addusertasks).

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)