# IShellFolder2::EnumSearches

## Description

Requests a pointer to an interface that allows a client to enumerate the available search objects.

## Parameters

### `ppenum`

Type: **[IEnumExtraSearch](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumextrasearch)****

The address of a pointer to an enumerator object's [IEnumExtraSearch](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumextrasearch) interface.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.