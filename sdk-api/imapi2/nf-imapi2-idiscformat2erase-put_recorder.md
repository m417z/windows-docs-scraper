# IDiscFormat2Erase::put_Recorder

## Description

Sets the recording device to use in the erase operation.

## Parameters

### `value` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the recording device to use in the erase operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

The recorder must be compatible with the format defined by this interface. To determine compatibility, call the [IDiscFormat2::IsRecorderSupported](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2-isrecordersupported) method.

## See also

[IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase)

[IDiscFormat2Erase::get_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-get_recorder)