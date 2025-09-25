# IQueryInfo::GetInfoFlags

## Description

Gets the information flags for an item. This method is not currently used.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

A pointer to a value that receives the flags for the item. If no flags are to be returned, this value should be set to zero.

## Return value

Type: **HRESULT**

Returns S_OK if *pdwFlags* returns any flag values, or a COM-defined error value otherwise.

## See also

[IQueryInfo](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iqueryinfo)