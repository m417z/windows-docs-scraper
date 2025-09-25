# IDiscFormat2RawCD::get_StartOfNextSession

## Description

Retrieves the first sector of the next session.

## Parameters

### `value` [out]

Sector number for the start of the next write operation. This value can be negative for blank media.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED** | The requested operation is only valid when media has been "prepared".<br><br>Value: 0xC0AA0602 |

## Remarks

The client application that creates an image must provide appropriately sized lead-in and lead-out data. The application developer using the [IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd) interface must understand the formats of lead-in and lead-out for the first and subsequent sessions. Note that lead-in LBA for the first session is negative.

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)