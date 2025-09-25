# IFileSystemImage::LockInChangePoint

## Description

Locks the file system information at the current change-point level.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_FSI_INTERNAL_ERROR** | Internal error occurred: *%1!ls!*. |

## Remarks

Once the change point is locked, rollback to earlier change points is not permitted.

Locking the change point does not change the [IFileSystemImage::get_ChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_changepoint) property.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::RollbackToChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-rollbacktochangepoint)

[IFileSystemImage::get_ChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_changepoint)