# IBootOptions::get_Emulation

## Description

Retrieves the media type that the boot image is intended to emulate.

## Parameters

### `pVal` [out]

Media type that the boot image is intended to emulate. For possible values, see the [EmulationType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-emulationtype) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::put_Emulation](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-put_emulation)