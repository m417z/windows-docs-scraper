# IFileSystemImage::get_ISO9660InterchangeLevelsSupported

## Description

Retrieves the supported ISO9660 compatibility levels.

## Parameters

### `pVal` [out]

List of supported ISO9660 compatibility levels. Each item in the list is a VARIANT that identifies one supported interchange level. The variant type is **VT_UI4**. The **ulVal** member of the variant contains the compatibility level.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_ISO9660InterchangeLevel](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_iso9660interchangelevel)

[IFileSystemImage::put_ISO9660InterchangeLevel](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_iso9660interchangelevel)