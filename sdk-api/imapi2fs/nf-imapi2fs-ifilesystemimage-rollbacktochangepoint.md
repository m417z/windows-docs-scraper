# IFileSystemImage::RollbackToChangePoint

## Description

Reverts the image back to the specified change point.

## Parameters

### `changePoint` [in]

Change point that identifies the target state for rollback.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_TOO_MANY_DIRS** | This file system image has too many directories for the *%1!ls!* file system.<br><br>Value: 0xC0AAB130 |
| **IMAPI_E_ISO9660_LEVELS** | ISO9660 is limited to 8 levels of directories.<br><br>Value: 0xC0AAB131 |

## Remarks

Typically, an application calls the [IFileSystemImage::get_ChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_changepoint) method and stores the change point value prior to making a change to the file system. If necessary, you can pass the change point value to this method to revert changes since that point in development.

An application can call the [IFileSystemImage::LockInChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-lockinchangepoint) method to lock the state of a file system image at any point in its development. After a lock is set, you cannot call this method to revert the file system image to its earlier state.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::LockInChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-lockinchangepoint)

[IFileSystemImage::get_ChangePoint](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_changepoint)