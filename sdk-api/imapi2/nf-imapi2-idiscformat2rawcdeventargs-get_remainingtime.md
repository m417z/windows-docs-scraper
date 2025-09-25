# IDiscFormat2RawCDEventArgs::get_RemainingTime

## Description

Retrieves the estimated remaining time of the write operation.

## Parameters

### `value` [out]

Estimated time, in seconds, needed for the remainder of the write operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The estimate for a single write operation can vary as the operation progresses. The drive provides updated information that can affect the projected duration of the write operation.

## See also

[DDiscFormat2RawCDEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2rawcdevents)

[IDiscFormat2RawCDEventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcdeventargs)