# IFileSystemImage::get_BootImageOptions

## Description

Retrieves the boot image that you want to add to the file system image.

## Parameters

### `pVal` [out]

An [IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions) interface of the boot image to add to the disc. Is **NULL** if a boot image has not been specified.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_BOOT_OBJECT_CONFLICT** | A boot object can only be included in an initial disc image.<br><br>Value: 0xC0AAB149 |
| **IMAPI_E_BOOT_IMAGE_DATA** | The boot object could not be added to the image.<br><br>Value: 0xC0AAB148 |

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::put_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_bootimageoptions)