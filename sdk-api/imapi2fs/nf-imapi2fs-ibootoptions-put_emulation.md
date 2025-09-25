# IBootOptions::put_Emulation

## Description

Sets the media type that the boot image is intended to emulate.

## Parameters

### `newVal` [in]

Media type that the boot image is intended to emulate. For possible values, see the [EmulationType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-emulationtype) enumeration type. The default value is **EmulationNone**, which means the BIOS will not emulate any device type or special sector size for the CD during boot from the CD.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_BOOT_EMULATION_IMAGE_SIZE_MISMATCH** | The emulation type requested does not match the boot image size.<br><br>Value: 0xC0AAB14A |

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::get_Emulation](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-get_emulation)