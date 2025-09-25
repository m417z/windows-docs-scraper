# IFileSystemImage::put_BootImageOptions

## Description

Sets the boot image that you want to add to the file-system image. This method creates a complete copy of the passed-in boot options by copying the stream from the supplied [IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions) interface.

## Parameters

### `newVal` [in]

An [IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions) interface of the boot image that you want to add to the file-system image. Can be **NULL**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_BOOT_OBJECT_CONFLICT** | A boot object can only be included in an initial disc image.<br><br>Value: 0xC0AAB149 |
| **IMAPI_E_BOOT_IMAGE_DATA** | The boot object could not be added to the image.<br><br>Value: 0xC0AAB148 |

## Remarks

You can specify a boot image only if the file system image has no previous sessions. The boot image must start at the first sector of the disc.

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_bootimageoptions)