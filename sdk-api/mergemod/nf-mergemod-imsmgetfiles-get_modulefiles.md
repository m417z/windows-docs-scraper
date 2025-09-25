# IMsmGetFiles::get_ModuleFiles

## Description

The
**get_ModuleFiles** method retrieves the
[ModuleFiles](https://learn.microsoft.com/windows/desktop/Msi/getfiles-modulefiles) property of the
[GetFiles](https://learn.microsoft.com/windows/desktop/Msi/getfiles-object) object. This method returns the primary keys in the
[File table](https://learn.microsoft.com/windows/desktop/Msi/file-table) of the currently open module. The primary keys are returned as a collection of strings. The module must be opened by a call to the
[OpenModule](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge-openmodule) function before calling
**get_ModuleFiles**.

## Parameters

### `Files` [out]

Collection of IMsmStrings that are the primary keys of the
[File table](https://learn.microsoft.com/windows/desktop/Msi/file-table) for the currently open module.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The function succeeded. |
| **E_FAIL** | No module is open. |
| **E_OUTOFMEMORY** | Out of memory. |
| **ERROR_FUNCTION_FAILED as HRESULT** | The function failed. |
| **ERROR_INVALID_HANDLE as HRESULT** | The function failed. |

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)