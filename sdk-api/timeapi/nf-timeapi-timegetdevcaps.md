# timeGetDevCaps function

## Description

The **timeGetDevCaps** function queries the timer device to determine its resolution.

## Parameters

### `ptc`

A pointer to a [TIMECAPS](https://learn.microsoft.com/windows/desktop/api/timeapi/ns-timeapi-timecaps) structure. This structure is filled with information about the resolution of the timer device.

### `cbtc`

The size, in bytes, of the [TIMECAPS](https://learn.microsoft.com/windows/desktop/api/timeapi/ns-timeapi-timecaps) structure.

## Return value

Returns **MMSYSERR_NOERROR** if successful or an error code otherwise. Possible error codes include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_ERROR** | General error code. |
| **TIMERR_NOCANDO** | The *ptc* parameter is **NULL**, or the *cbtc* parameter is invalid, or some other error occurred. |

## See also

[Multimedia Timer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timer-functions)

[Multimedia Timers](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers)

[Timer Resolution](https://learn.microsoft.com/windows/desktop/Multimedia/timer-resolution)