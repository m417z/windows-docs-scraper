# IBootOptions::put_Manufacturer

## Description

Sets an identifier that identifies the manufacturer or developer of the CD.

## Parameters

### `newVal` [in]

Identifier that identifies the manufacturer or developer of the CD. This is an ANSI string that is limited to 24 bytes. The string does not need to include a NULL character; however, you must set unused bytes to 0x00.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The provided *newVal* parameter is not valid.<br><br>Value: 0xC0AAB101 |

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::get_Manufacturer](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-get_manufacturer)