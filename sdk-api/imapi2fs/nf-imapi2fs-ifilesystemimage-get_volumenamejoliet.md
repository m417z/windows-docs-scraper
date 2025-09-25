# IFileSystemImage::get_VolumeNameJoliet

## Description

Retrieves the volume name for the Joliet system image.

## Parameters

### `pVal` [out]

String that contains the volume name for the Joliet system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_VolumeName](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_volumename)

[IFileSystemImage::get_VolumeNameISO9660](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_volumenameiso9660)

[IFileSystemImage::get_VolumeNameUDF](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_volumenameudf)