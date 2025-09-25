# IFileSystemImageResult::get_ProgressItems

## Description

Retrieves the progress item block mapping collection.

## Parameters

### `pVal` [out]

An [IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems) interface that contains a collection of progress items. Each progress item identifies the blocks written since the previous progress status was taken.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## See also

[IEnumProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ienumprogressitems)

[IFileSystemImageResult](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimageresult)

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)