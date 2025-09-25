# IDiscFormat2Data::put_Recorder

## Description

Sets the recording device to use for the write operation.

## Parameters

### `value` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the recording device to use in the write operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2DATA_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0400 |
| **E_IMAPI_DF2DATA_RECORDER_NOT_SUPPORTED** | This device does not support the operations required by this disc format.<br><br>Value: 0xC0AA0407 |

## Remarks

The recorder must be compatible with the format defined by this interface. To determine compatibility, call the [IDiscFormat2::IsRecorderSupported](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2-isrecordersupported) method.

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::get_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_recorder)