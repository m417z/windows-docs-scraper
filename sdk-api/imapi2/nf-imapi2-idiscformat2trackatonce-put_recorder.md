# IDiscFormat2TrackAtOnce::put_Recorder

## Description

Sets the recording device to use for the write operation.

## Parameters

### `value` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the recording device to use in the write operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2TAO_WRITE_IN_PROGRESS** | A write operation is in progress.<br><br>Value: 0xC0AA0500 |
| **E_IMAPI_DF2TAO_MEDIA_IS_PREPARED** | The requested operation is not valid when media has been "prepared" but not released.<br><br>Value: 0xC0AA0503 |
| **E_IMAPI_DF2TAO_RECORDER_NOT_SUPPORTED** | This device does not support the operations required by this disc format.<br><br>Value: 0xC0AA050E |

## Remarks

The recorder must be compatible with the format defined by this interface. To determine compatibility, call the [IDiscFormat2::IsRecorderSupported](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2-isrecordersupported) method.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::get_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_recorder)