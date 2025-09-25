# IDiscFormat2RawCD::get_LastPossibleStartOfLeadout

## Description

Retrieves the last possible starting position for the leadout area.

## Parameters

### `value` [out]

Sector address of the starting position for the leadout area.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED** | The requested operation is only valid when media has been "prepared".<br><br>Value: 0xC0AA0602 |

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)