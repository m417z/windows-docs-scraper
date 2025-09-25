# StreamClassQueryMasterClock function

## Description

When the minidriver calls the **StreamClassQueryMasterClock** routine, the class driver queries the appropriate time value of the master clock asynchronously, and passes the result to the routine passed in the *ClockCallbackRoutine* parameter.

## Parameters

### `HwStreamObject` [in]

Pointer to a [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object) indicating the stream that is querying its master clock. The stream may only have one query pending at a time. The class driver passes this value to the callback in the **HwStreamObject** member of the callback's *TimeContext* parameter.

### `MasterClockHandle` [in]

Specifies the handle for the master clock that is being queried. The class driver passes this in the SRB_INDICATE_MASTER_CLOCK request to the minidriver's [StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85)) routine.

### `TimeFunction` [in]

Specifies what time function to query the master clock for. See [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context) for the possible values. The class driver passes this value to the callback in the **Function** member of the *TimeContext* parameter.

### `ClockCallbackRoutine` [in]

Specifies the routine to which the class driver passes the results. The function prototype must be:

```cpp
ClockCallbackRoutine(PHW_TIME_CONTEXT TimeContext);
```

## Remarks

The class driver queries the master clock and passes the results in the *TimeContext* parameter (of type [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context)) of the callback. In particular, it sets the **Time** member of this structure to the time value requested in the *TimeFunction* parameter, the current system time in the **SystemTime** member of the same structure, and the minidriver's device extension in the **HwDeviceExtension** member of that structure.

The class driver deallocates the HW_TIME_CONTEXT structure after the clock callback routine terminates, so the callback must store any information the minidriver wishes to maintain. For that purpose, the callback routine may use previously-allocated space in either the minidriver's device extension (*TimeContext-*>**HwDeviceExtension**), or the stream extension of the stream that queried its master clock (*TimeContext*->**HwStreamObject**->**HwStreamExtension**).

On rare occasions, the graph manager switches the master clock. The class driver exposes a race condition in handling the new master clock. If the minidriver calls a stream class master clock routine immediately after it receives a new clock from the class driver, the class driver may produce unexpected results.

## See also

[HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context)

[StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85))

[StreamClassQueryMasterClockSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclocksync)