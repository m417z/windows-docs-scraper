# IObjectWithAppUserModelID::SetAppID

## Description

Specifies a unique application-defined Application User Model ID (AppUserModelID) that identifies the object as a handler for a specific file type. This method is used by applications that require dynamic AppUserModelIDs.

## Parameters

### `pszAppID` [in]

Type: **LPCWSTR**

A pointer to the AppUserModelID string to assign to an application.

## Return value

Type: **HRESULT**

Custom implementations that do not require dynamic AppUserModelIDs can return E_NOTIMPL. Custom implementations that require dynamic AppUserModelIDs should return S_OK if successful, or an error value otherwise.

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[IObjectWithAppUserModelID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iobjectwithappusermodelid)

[IObjectWithAppUserModelID::GetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iobjectwithappusermodelid-getappid)

[SetCurrentProcessExplicitAppUserModelID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-setcurrentprocessexplicitappusermodelid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)