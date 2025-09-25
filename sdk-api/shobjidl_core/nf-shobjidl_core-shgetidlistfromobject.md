# SHGetIDListFromObject function

## Description

Retrieves the pointer to an item identifier list (PIDL) of an object.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the object from which to get the PIDL.

### `ppidl` [out]

Type: **PIDLIST_ABSOLUTE***

When this function returns, contains a pointer to the PIDL of the given object.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[SHCreateItemFromIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromidlist)