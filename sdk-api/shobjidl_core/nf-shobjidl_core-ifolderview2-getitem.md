# IFolderView2::GetItem

## Description

Retrieves an object that represents a specified item.

## Parameters

### `iItem` [in]

Type: **int**

The zero-based index of the item to retrieve.

### `riid` [in]

Type: **REFIID**

Reference to the desired IID to represent the item, such as IID_IShellItem.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

## Return value

Type: **HRESULT**

Returns S_OK if the specified item was found, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The index in *iItem* is out of range. |

## See also

[IFolderView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview2)

[IFolderView2::GetSelectedItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview2-getselecteditem)