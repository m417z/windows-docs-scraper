# IDiscFormat2TrackAtOnce::get_Recorder

## Description

Retrieves the recording device to use for the write operation.

## Parameters

### `value` [out]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface that identifies the recording device to use in the write operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::put_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_recorder)