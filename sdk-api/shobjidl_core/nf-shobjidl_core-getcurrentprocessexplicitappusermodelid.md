# GetCurrentProcessExplicitAppUserModelID function

## Description

Retrieves the application-defined, explicit Application User Model ID (AppUserModelID) for the current process.

## Parameters

### `AppID` [out]

Type: **PWSTR***

A pointer that receives the address of the AppUserModelID assigned to the process. The caller is responsible for freeing this string with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The AppUserModelID retrieved by this function was set earlier through [SetCurrentProcessExplicitAppUserModelID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-setcurrentprocessexplicitappusermodelid).

An application can only retrieve an AppUserModelID that has been explicitly set. System-assigned default AppUserModelIDs cannot be retrieved. If the application requires knowledge of its AppUserModelID it should set one explicitly.

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[IObjectWithAppUserModelID::GetAppID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iobjectwithappusermodelid-getappid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)