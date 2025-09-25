# IFileSystemImage::put_ISO9660InterchangeLevel

## Description

Sets the ISO9660 compatibility level of the file system image.

## Parameters

### `newVal` [in]

ISO9660 compatibility level of the file system image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |

## Remarks

To determine the supported compatibility levels, call the [IFileSystemImage::get_ISO9660InterchangeLevelsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_iso9660interchangelevelssupported) method.

This property is meaningful only if you specified FsiFileSystemISO9660 when calling [IFileSystemImage::put_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_filesystemstocreate).

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_ISO9660InterchangeLevel](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_iso9660interchangelevel)

[IFileSystemImage::get_ISO9660InterchangeLevelsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_iso9660interchangelevelssupported)