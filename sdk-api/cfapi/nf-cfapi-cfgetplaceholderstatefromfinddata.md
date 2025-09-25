# CfGetPlaceholderStateFromFindData function

## Description

Gets a set of placeholder states based on the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

## Parameters

### `FindData` [in]

The find data information on the file.

## Return value

Can include [CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state); the placeholder state.

## Remarks

The **WIN32_FIND_DATA** structure is obtained from the [FindFirstFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findfirstfilea)/[FindNextFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findnextfilea) functions.

## See also

[WIN32_FIND_DATA](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa)

[CF_PLACEHOLDER_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state)

[FindFirstFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findfirstfilea)

[FindNextFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-findnextfilea)