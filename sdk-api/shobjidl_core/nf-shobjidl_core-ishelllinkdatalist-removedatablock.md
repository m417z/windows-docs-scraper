# IShellLinkDataList::RemoveDataBlock

## Description

Removes a data block from a link.

## Parameters

### `dwSig` [in]

Type: **DWORD**

The data block's signature. The signature value for a particular type of data block can be found in its structure reference. For a list of supported data block types and their associated structures, see [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error code otherwise.

## See also

[IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist)