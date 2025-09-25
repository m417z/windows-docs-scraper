# IBootOptions::AssignBootImage

## Description

Sets the data stream that contains the boot image.

## Parameters

### `newVal` [in]

An **IStream** interface of the data stream that contains the boot image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_BOOT_IMAGE_DATA** | The boot object could not be added to the image.<br><br>Value: 0xC0AAB142 |

## Remarks

If the size of the newly assigned boot image is either 1.2, 1.44. or 2.88 MB, this method will automatically adjust the [EmulationType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-emulationtype) value to the respective "floppy" type value. It is, however, possible to override the default or previously assigned **EmulationType** value by calling the [IBootOptions::put_Emulation](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-put_emulation) method.

The additional specification of the platform on which to use the boot image requires the call to the [IBootOptions::put_PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-put_platformid) method.

IMAPI does not include any boot images; developers must provide their own boot images.

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::get_BootImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-get_bootimage)

[IFileSystemImage::get_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_bootimageoptions)

[IFileSystemImage::put_BootImageOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_bootimageoptions)