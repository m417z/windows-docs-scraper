# IDiscRecorder::GetRecorderType

## Description

Determines whether the disc recorder is a CD-R or CD-RW type device. This does not indicate the type of media that is currently inserted in the device.

## Parameters

### `fTypeCode` [out]

One of the following values.

| Value | Meaning |
| --- | --- |
| **RECORDER_CDR** | 0x1 |
| **RECORDER_CDRW** | 0x2 |

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)