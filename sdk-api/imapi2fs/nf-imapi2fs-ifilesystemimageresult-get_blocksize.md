# IFileSystemImageResult::get_BlockSize

## Description

Retrieves the size, in bytes, of a block of data.

## Parameters

### `pVal` [out]

Number of bytes in a block.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFileSystemImageResult](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimageresult)

[IFileSystemImageResult::get_TotalBlocks](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimageresult-get_totalblocks)