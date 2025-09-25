# IFileSystemImage2::get_BootImageOptionsArray

## Description

Retrieves the boot option array that will be utilized to generate the file system image.

## Parameters

### `pVal` [out]

Pointer to a boot option array that contains a list of [IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions) interfaces of boot images used to generate the file system image. Each element of the list is a **VARIANT** of type **VT_DISPATCH**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_BOOT_OBJECT_CONFLICT** | A boot object can only be included in an initial disc image.<br><br>Value: 0xC0AAB149 |
| **IMAPI_E_BOOT_IMAGE_DATA** | The boot object could not be added to the image.<br><br>Value: 0xC0AAB148 |

## Remarks

 The **SAFEARRAY** will be a one-dimensional array. If a boot image is not specified, a zero-sized array will be returned.

## See also

[IFileSystemImage2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage2)

[IFileSystemImage2::put_BootImageOptionsArray](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage2-put_bootimageoptionsarray)