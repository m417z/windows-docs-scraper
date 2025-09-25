# IFileSystemImage2::put_BootImageOptionsArray

## Description

Sets the boot option array that will be utilized to generate the file system image. Unlike [IFileSystemImage::put_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_bootimageoptions), this method will not create a complete copy of each boot options array element, but instead use references to each element.

## Parameters

### `newVal` [in]

List of [IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions) interfaces of the boot images that will be utilized to generate the file system image. Each element of the list is a **VARIANT** of the type **VT_DISPATCH**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | No such interface supported.<br><br>Value: 0x80004002 |
| **IMAPI_E_BOOT_OBJECT_CONFLICT** | A boot object can only be included in an initial disc image.<br><br>Value: 0xC0AAB149 |
| **IMAPI_E_BOOT_IMAGE_DATA** | The boot object could not be added to the image.<br><br>Value: 0xC0AAB148 |

## Remarks

The **SAFEARRAY** must be a one dimensional array. A zero-size array is allowed, but it will result in a regular, non-bootable disc.

The boot images sequence on the disc will match the sequence specified in the **SAFEARRAY**. Both **put_BootImageOptionsArray** and [put_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_bootimageoptions) are used for specifying the boot image, the latter function being invoked before the disc image created takes effect.

The [get_BootImageOptionsArray](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage2-get_bootimageoptionsarray) and [get_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_bootimageoptions) functions will retrieve the result of the last calls of put_BootImageOptionsArray or [put_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_bootimageoptions). The use of these functions should be synchronized.

## See also

[IFileSystemImage2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage2)

[IFileSystemImage2::get_BootImageOptionsArray](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage2-get_bootimageoptionsarray)