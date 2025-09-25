# SetCurrentProcessExplicitAppUserModelID function

## Description

Specifies a unique application-defined Application User Model ID (AppUserModelID) that identifies the current process to the taskbar. This identifier allows an application to group its associated processes and windows under a single taskbar button.

## Parameters

### `AppID` [in]

Type: **PCWSTR**

Pointer to the AppUserModelID to assign to the current process.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method must be called during an application's initial startup routine before the application presents any UI or makes any manipulation of its Jump Lists. This includes any call to [SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs).

## See also

[Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids)

[GetCurrentProcessExplicitAppUserModelID](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-getcurrentprocessexplicitappusermodelid)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)