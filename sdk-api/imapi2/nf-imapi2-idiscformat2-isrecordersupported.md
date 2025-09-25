# IDiscFormat2::IsRecorderSupported

## Description

Determines if the recorder supports the given format.

## Parameters

### `recorder` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface of the recorder to test.

### `value` [out]

Is VARIANT_TRUE if the recorder supports the given format; otherwise, VARIANT_FALSE.

## Return value

S_OK or S_FALSE are returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

When implemented by the [IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd) interface, this method will return E_IMAPI_DF2RAW_MEDIA_IS_NOT_SUPPORTED in the event the recorder does not support the given format. It is important to note that in this specific scenario the value does not indicate that an error has occurred, but rather the result of a successful operation.

## See also

[IDiscFormat2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2)