# IWriteSpeedDescriptor::get_WriteSpeed

## Description

Retrieves the supported write speed for writing to the media.

## Parameters

### `value` [out]

Write speed of the current media, measured in sectors per second.

## Return value

S_OK is typically returned on success, but the return of other success values is possible. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The write speed is based on the media write speeds. The value of this property can change when a media change occurs.

## See also

[IWriteSpeedDescriptor](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwritespeeddescriptor)