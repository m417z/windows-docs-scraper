# ILaunchSourceAppUserModelId::GetAppUserModelId

## Description

Retrieves an [AppUserModelId](https://learn.microsoft.com/windows/desktop/shell/appids) from the source application.

## Parameters

### `launchingApp` [out]

Type: **LPWSTR***

Contains a pointer to a string that contains the [AppUserModelId](https://learn.microsoft.com/windows/desktop/shell/appids).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[AppUserModelId](https://learn.microsoft.com/windows/desktop/shell/appids)

[ILaunchSourceAppUserModelId](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ilaunchsourceappusermodelid)