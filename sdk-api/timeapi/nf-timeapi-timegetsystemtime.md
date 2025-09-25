# timeGetSystemTime function

## Description

The **timeGetSystemTime** function retrieves the system time, in milliseconds. The system time is the time elapsed since Windows was started. This function works very much like the [timeGetTime](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timegettime) function. See **timeGetTime** for details of these functions' operation.

## Parameters

### `pmmt`

Pointer to an [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

### `cbmmt`

Size, in bytes, of the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

## Return value

If successful, returns **TIMERR_NOERROR**. Otherwise, returns an error code.

## Remarks

The system time is returned in the **ms** member of the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

## See also

[Multimedia Timer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timer-functions)

[Multimedia Timers](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers)