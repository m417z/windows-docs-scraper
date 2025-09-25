# IShellLinkDataList::CopyDataBlock

## Description

Retrieves a copy of a link's data block.

## Parameters

### `dwSig` [in]

Type: **DWORD**

The data block's signature. The signature value for a particular type of data block can be found in its structure reference. For a list of supported data block types and their associated structures, see [IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist).

### `ppDataBlock` [out]

Type: **VOID****

The address of a pointer to a copy of the data block structure. If **IShellLinkDataList::CopyDataBlock** returns a successful result, the calling application must free the memory when it is no longer needed by calling [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a COM error code otherwise.

## See also

[IShellLinkDataList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinkdatalist)