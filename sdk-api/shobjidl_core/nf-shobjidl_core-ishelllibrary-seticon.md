# IShellLibrary::SetIcon

## Description

Sets the default icon for the library.

## Parameters

### `pszIcon` [in]

Type: **LPCWSTR**

A null-terminated Unicode string that describes the location of the default icon. The string must be formatted as `ModuleFileName,ResourceIndex` or `ModuleFileName,-ResourceID`.

| Value | Description |
| --- | --- |
| ModuleFileName | The file name of the module file that contains the icon resource. |
| ResourceIndex | A positive decimal number that specifies the index of the icon resource in the module file. |
| -ResourceID | A negative decimal number whose absolute value is the resource ID of the icon resource in the module file. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information on the format of the *pszIcon* parameter, see [PathParseIconLocation](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathparseiconlocationa).

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[PathParseIconLocation](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathparseiconlocationa)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))