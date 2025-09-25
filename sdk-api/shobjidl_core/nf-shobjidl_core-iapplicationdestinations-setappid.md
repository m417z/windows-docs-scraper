# IApplicationDestinations::SetAppID

## Description

Specifies a unique Application User Model ID (AppUserModelID) for the application from whose taskbar button's Jump List the methods of this interface will remove destinations. This method is optional.

## Parameters

### `pszAppID` [in]

Type: **LPCWSTR**

Pointer to the AppUserModelID of the process whose taskbar button representation receives the Jump List.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the application has an explicit AppUserModelID, this method must be called before you call [RemoveAllDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removealldestinations) or [RemoveDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removedestination).

After an AppUserModelID is specified through an object's **SetAppID** method, the AppUserModelID is saved in the object for that object's lifetime, providing that it is not overwritten by another call to **SetAppID**.

Some applications will not declare an explicit AppUserModelID and should not call this method. In that case, the application's identity is deduced when [IApplicationDestinations::RemoveDestination](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removedestination) or [IApplicationDestinations::RemoveAllDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iapplicationdestinations-removealldestinations) are called. However, there is a performance benefit in avoiding those calculations, so applications that provide custom Jump Lists are encouraged to use [explicit AppUserModelIDs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-setcurrentprocessexplicitappusermodelid).

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[IApplicationDestinations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdestinations)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)