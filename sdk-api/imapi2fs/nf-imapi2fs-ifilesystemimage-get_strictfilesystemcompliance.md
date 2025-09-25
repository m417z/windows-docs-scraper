# IFileSystemImage::get_StrictFileSystemCompliance

## Description

Determines the compliance level for creating and developing the file-system image.

## Parameters

### `pVal` [out]

Is VARIANT_TRUE if the file system images are created in strict compliance with applicable standards.

Is VARIANT_FALSE if the compliance standards are relaxed to be compatible with IMAPI version 1.0.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::put_StrictFileSystemCompliance](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_strictfilesystemcompliance)