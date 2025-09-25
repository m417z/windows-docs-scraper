# SHCreateShellItemArrayFromIDLists function

## Description

Creates a Shell item array object from a list of [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures.

## Parameters

### `cidl` [in]

Type: **UINT**

The number of elements in the array.

### `rgpidl` [in]

Type: **PCIDLIST_ABSOLUTE_ARRAY**

A list of *cidl* constant pointers to [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structures.

### `ppsiItemArray` [out]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)****

When this function returns, contains an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) interface pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.