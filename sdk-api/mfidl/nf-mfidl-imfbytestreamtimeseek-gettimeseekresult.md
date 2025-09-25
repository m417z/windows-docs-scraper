# IMFByteStreamTimeSeek::GetTimeSeekResult

## Description

Gets the result of a time-based seek.

## Parameters

### `pqwStartTime` [out]

Receives the new position after the seek, in 100-nanosecond units.

### `pqwStopTime` [out]

Receives the stop time, in 100-nanosecond units. If the stop time is unknown, the value is zero.

### `pqwDuration` [out]

Receives the total duration of the file, in 100-nanosecond units. If the duration is unknown, the value is –1.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The byte stream does not support time-based seeking, or no data is available. |

## Remarks

This method returns the server response from a previous time-based seek.

**Note** This method normally cannot be invoked until some data
is read from the byte stream, because the [IMFByteStreamTimeSeek::TimeSeek](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfbytestreamtimeseek-timeseek) method does not send a server request immediately.

## See also

[IMFByteStreamTimeSeek](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfbytestreamtimeseek)