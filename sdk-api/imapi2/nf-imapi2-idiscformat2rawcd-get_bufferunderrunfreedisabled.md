# IDiscFormat2RawCD::get_BufferUnderrunFreeDisabled

## Description

Determines if Buffer Underrun Free recording is enabled.

## Parameters

### `value` [out]

Is VARIANT_TRUE if Buffer Underrun Free recording is disabled; otherwise, VARIANT_FALSE (enabled).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

[IDiscFormat2RawCD::put_BufferUnderrunFreeDisabled](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-put_bufferunderrunfreedisabled)