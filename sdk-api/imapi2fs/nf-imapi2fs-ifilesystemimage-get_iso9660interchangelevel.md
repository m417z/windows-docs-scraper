# IFileSystemImage::get_ISO9660InterchangeLevel

## Description

Retrieves the ISO9660 compatibility level to use when creating the result image.

## Parameters

### `pVal` [out]

Identifies the interchange level of the ISO9660 file system.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

For a list of supported compatibility levels, call the [IFileSystemImage::get_ISO9660InterchangeLevelsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_iso9660interchangelevelssupported) method.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_ISO9660InterchangeLevelsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_iso9660interchangelevelssupported)

[IFileSystemImage::put_ISO9660InterchangeLevel](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_iso9660interchangelevel)