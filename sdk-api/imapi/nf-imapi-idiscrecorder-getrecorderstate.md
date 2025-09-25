# IDiscRecorder::GetRecorderState

## Description

Retrieves the disc recorder state.

## Parameters

### `pulDevStateFlags` [out]

One of the following values.

| Value | Meaning |
| --- | --- |
| **RECORDER_BURNING** | 0x2 |
| **RECORDER_DOING_NOTHING** | 0x0 |
| **RECORDER_OPENED** | 0x1 |

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)