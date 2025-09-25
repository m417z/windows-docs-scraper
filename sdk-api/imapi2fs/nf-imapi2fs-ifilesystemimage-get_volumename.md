# IFileSystemImage::get_VolumeName

## Description

Retrieves the volume name for this file system image.

## Parameters

### `pVal` [out]

String that contains the volume name for this file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

To set the volume name, call the [IFileSystemImage::put_VolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_volumename) method.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_ImportedVolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_importedvolumename)

[IFileSystemImage::put_VolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_volumename)