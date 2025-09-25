# IFileSystemImage::put_StrictFileSystemCompliance

## Description

Determines the compliance level for creating and developing the file-system image.

## Parameters

### `newVal` [in]

Set to VARIANT_TRUE to create the file system images in strict compliance with applicable standards. You can specify VARIANT_TRUE only when the file system image is empty.

Set to VARIANT_FALSE to relax the compliance standards to be compatible with IMAPI version 1.0.

The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

If this property is VARIANT_TRUE and a method requests an action that violates one of the file system constraints, an exception is thrown.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_StrictFileSystemCompliance](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_strictfilesystemcompliance)