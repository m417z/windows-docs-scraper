# ICustomDestinationList::SetAppID

## Description

Specifies a unique Application User Model ID (AppUserModelID) for the application whose taskbar button will hold the custom Jump List built through the methods of this interface. This method is optional.

## Parameters

### `pszAppID` [in]

Type: **LPCWSTR**

A pointer to the AppUserModelID of the process or application whose taskbar representation receives the Jump List.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | This method was called after [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist). The list-building process is already running with a particular AppUserModelID, either inferred by the system or set through a call to [SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-setappid) before the call to **BeginList**. After a list-building operation is in progress, the AppUserModelID cannot be changed until after [CommitList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-commitlist) or [AbortList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-abortlist) has been called. |

## Remarks

If an application has an explicit AppUserModelID, you must call **SetAppID** before you call [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) or [ICustomDestinationList::GetRemovedDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-getremoveddestinations).

After an AppUserModelID is specified through an object's **SetAppID** method, the AppUserModelID is saved in the object for that object's lifetime, providing that it is not overwritten by another call to **SetAppID**.

Some applications will not declare an explicit AppUserModelID and should not call this method. In that case, the application's identity is deduced when [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) or [ICustomDestinationList::GetRemovedDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-getremoveddestinations) are called. However, there is a performance benefit in avoiding those calculations, so applications that provide custom Jump Lists are encouraged to use [explicit AppUserModelIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-setcurrentprocessexplicitappusermodelid).

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[SetCurrentProcessExplicitAppUserModelID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-setcurrentprocessexplicitappusermodelid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)