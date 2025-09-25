# ISearchFolderItemFactory::GetShellItem

## Description

Gets the search folder as a [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the desired IID.

### `ppv` [out]

Type: **void****

The [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface pointer specified in *riid*.

## Return value

Type: **HRESULT**

Returns a success value if successful, or an error value otherwise.

## Remarks

When the retrieved [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) is enumerated, it returns the search results.

## See also

[ISearchFolderItemFactory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-isearchfolderitemfactory)

[SHCreateItemFromIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromidlist)