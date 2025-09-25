# IFileSystemImage::get_ChangePoint

## Description

Retrieves the change point identifier.

## Parameters

### `pVal` [out]

Change point identifier. The identifier is a count of the changes to the file system image since its inception.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

An application can store the value of this property prior to making a change to the file system, then at a later point pass the value to the [IFileSystemImage::RollbackToChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-rollbacktochangepoint) method to revert changes since that point in development.

An application can call the [IFileSystemImage::LockInChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-lockinchangepoint) method to lock the state of a file system image at any point in its development. Once a lock is set, you cannot call [RollbackToChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-rollbacktochangepoint) to revert the file system image to its earlier state.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::LockInChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-lockinchangepoint)

[IFileSystemImage::RollbackToChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-rollbacktochangepoint)