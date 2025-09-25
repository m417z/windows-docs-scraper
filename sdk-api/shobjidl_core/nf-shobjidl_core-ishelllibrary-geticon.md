# IShellLibrary::GetIcon

## Description

Gets the default icon for the library.

## Parameters

### `ppszIcon` [out]

Type: **LPWSTR***

A null-terminated Unicode string that describes the location of the default icon. The string is returned as `ModuleFileName,ResourceIndex` or `ModuleFileName,-ResourceID`.

| Value | Description |
| --- | --- |
| ModuleFileName | The file name of the module file that contains the icon resource. |
| ResourceIndex | If the number that follows the comma is positive, the index of the resource in the module file. |
| -ResourceID | If the number that follows the comma is negative, the absolute value of the number is the resource ID of the icon in the module file. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For additional information on parsing the string returned in *ppszIcon*, see [PathParseIconLocation](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathparseiconlocationa).

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[PathParseIconLocation](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathparseiconlocationa)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))