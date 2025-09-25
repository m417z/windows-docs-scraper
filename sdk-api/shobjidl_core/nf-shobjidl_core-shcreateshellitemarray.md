# SHCreateShellItemArray function

## Description

Creates a Shell item array object.

## Parameters

### `pidlParent` [in]

Type: **PCIDLIST_ABSOLUTE**

The ID list of the parent folder of the items specified in *ppidl*. If *psf* is specified, this parameter can be **NULL**. If this *pidlParent* is not specified, it is computed from the *psf* parameter using [IPersistFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder2).

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

The Shell data source object that is the parent of the child items specified in *ppidl*. If *pidlParent* is specified, this parameter can be **NULL**.

### `cidl` [in]

Type: **UINT**

The number of elements in the array specified by *ppidl*.

### `ppidl` [in]

Type: **PCUITEMID_CHILD_ARRAY**

The list of child item IDs for which the array is being created. This value can be **NULL**.

### `ppsiItemArray` [out]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)****

When this function returns, contains the address of an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) interface pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.