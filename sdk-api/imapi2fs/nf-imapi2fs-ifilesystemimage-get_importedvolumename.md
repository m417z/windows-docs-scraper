# IFileSystemImage::get_ImportedVolumeName

## Description

Retrieves the volume name provided from an imported file system.

## Parameters

### `pVal` [out]

String that contains the volume name provided from an imported file system. Is **NULL** until a file system is imported.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The imported volume name is provided for user information and is not automatically carried forward to subsequent sessions.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_VolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_volumename)

[IFileSystemImage::put_VolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_volumename)