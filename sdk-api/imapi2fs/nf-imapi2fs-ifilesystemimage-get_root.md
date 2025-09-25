# IFileSystemImage::get_Root

## Description

Retrieves the root directory item.

## Parameters

### `pVal` [out]

An [IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem) interface of the root directory item.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFsiDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsidirectoryitem)