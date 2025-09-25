# IWriteSpeedDescriptor::get_MediaType

## Description

Retrieves type of media in the current drive.

## Parameters

### `value` [out]

Type of media in the current drive. For possible values, see the [IMAPI_MEDIA_PHYSICAL_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_media_physical_type) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

IMAPI_MEDIA_PHYSICAL_TYPE

[IWriteSpeedDescriptor](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwritespeeddescriptor)