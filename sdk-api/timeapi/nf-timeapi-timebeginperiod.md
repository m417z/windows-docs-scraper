# timeBeginPeriod function

## Description

The **timeBeginPeriod** function requests a minimum resolution for periodic timers.

## Parameters

### `uPeriod`

Minimum timer resolution, in milliseconds, for the application or device driver. A lower value specifies a higher (more accurate) resolution.

## Return value

Returns **TIMERR_NOERROR** if successful or **TIMERR_NOCANDO** if the resolution specified in *uPeriod* is out of range.

## Remarks

Call this function immediately before using timer services, and call the [timeEndPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timeendperiod) function immediately after you are finished using the timer services.

You must match each call to **timeBeginPeriod** with a call to [timeEndPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timeendperiod), specifying the same minimum resolution in both calls. An application can make multiple **timeBeginPeriod** calls as long as each call is matched with a call to **timeEndPeriod**.

Prior to Windows 10, version 2004, this function affects a global Windows setting. For all processes Windows uses the lowest value (that is, highest resolution) requested by any process. Starting with Windows 10, version 2004, this function no longer affects global timer resolution. For processes which call this function, Windows uses the lowest value (that is, highest resolution) requested by any process. For processes which have not called this function, Windows does not guarantee a higher resolution than the default system resolution.

Starting with Windows 11, if a window-owning process becomes fully occluded, minimized, or otherwise invisible or inaudible to the end user, Windows does not guarantee a higher resolution than the default system resolution. See [SetProcessInformation](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessinformation) for more information on this behavior.

Setting a higher resolution can improve the accuracy of time-out intervals in wait functions. However, it can also reduce overall system performance, because the thread scheduler switches tasks more often. High resolutions can also prevent the CPU power management system from entering power-saving modes. Setting a higher resolution does not improve the accuracy of the high-resolution performance counter.

## See also

[Multimedia Timer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timer-functions)

[Multimedia Timers](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers)