# IDiscFormat2RawCD::get_RequestedWriteSpeed

## Description

Retrieves the requested write speed.

## Parameters

### `value` [out]

Requested write speed measured in disc sectors per second.

A value of 0xFFFFFFFF (-1) requests that the write occurs using the fastest supported speed for the media.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

This is the value specified in the most recent call to the [IDiscFormat2RawCD::SetWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-setwritespeed) method.

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

[IDiscFormat2RawCD::SetWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-setwritespeed)

[IDiscFormat2RawCD::get_CurrentWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_currentwritespeed)

[IDiscFormat2RawCD::get_SupportedWriteSpeeds](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_supportedwritespeeds)