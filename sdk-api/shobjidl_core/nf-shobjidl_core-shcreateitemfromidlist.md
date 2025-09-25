# SHCreateItemFromIDList function

## Description

Creates and initializes a Shell item object from a pointer to an item identifier list (PIDL). The resulting shell item object supports the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

The source PIDL.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in riid. This will typically be [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) or
[IShellItem2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem2).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[SHGetIDListFromObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shgetidlistfromobject)