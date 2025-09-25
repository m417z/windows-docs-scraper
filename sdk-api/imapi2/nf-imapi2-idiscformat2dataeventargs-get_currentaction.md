# IDiscFormat2DataEventArgs::get_CurrentAction

## Description

Retrieves the current write action being performed.

## Parameters

### `value` [out]

Current write action being performed. For a list of possible actions, see the [IMAPI_FORMAT2_DATA_WRITE_ACTION](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_format2_data_write_action) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[DDiscFormat2DataEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2dataevents)

[IDiscFormat2DataEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2dataeventargs)