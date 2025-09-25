# IFileSystemImageResult2::get_ModifiedBlocks

## Description

Retrieves the list of modified blocks in the result image.

## Parameters

### `pVal` [out]

Pointer to an [IBlockRangeList](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrangelist) interface representing the modified block ranges in the result image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## Remarks

This method returns **E_NOTIMPL** if the entire result image must be recorded. If this method returns a successful return code, it is sufficient to record only the sectors described by [IBlockRangeList](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrangelist) returned in *pVal*. It is highly recommended to record the sector ranges in exactly the same order as they are listed in **IBlockRangeList**.

## See also

[IFileSystemImageResult2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimageresult2)