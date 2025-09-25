# IObjectWithAppUserModelID::GetAppID

## Description

Retrieves a file type handler's explicit Application User Model ID (AppUserModelID), if one has been declared.

## Parameters

### `ppszAppID` [out]

Type: **LPWSTR***

When this method returns, contains the address of the AppUserModelID string assigned to the object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can only retrieve an AppUserModelID explicitly set for the handler. If the handler did not register an explicit AppUserModelID and is relying on a system-assigned AppUserModelID, this method will not retrieve the AppUserModelID. For more information, see [Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids).

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[IObjectWithAppUserModelID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iobjectwithappusermodelid)

[IObjectWithAppUserModelID::SetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iobjectwithappusermodelid-setappid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)