# StreamClassQueryMasterClockSync function

## Description

The minidriver may call the **StreamClassQueryMasterClockSync** routine to synchronously query a stream's master clock.

## Parameters

### `MasterClockHandle` [in]

Specifies the handle for the master clock that is being queried. The class driver passes this in the SRB_INDICATE_MASTER_CLOCK request to the minidriver's [StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85)) routine.

### `TimeContext` [in, out]

Specifies the [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context) structure that the class driver passes to the master clock's [StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine) routine. Before calling this routine, the minidriver must fill in the **HwDeviceExtension**, **HwStreamObject**, and **Function** members of *TimeContext*. **StreamClassQueryMasterClockSync** completes the **Time** and **SystemTime** members.

## Return value

None

## Remarks

The routine must be called at or below DISPATCH_LEVEL. If the caller is running at a raised IRQL, it should use the asynchronous version, [StreamClassQueryMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclock), instead.

The class driver calls the master clock's [StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine) routine to query the clock.

On rare occasions, the graph manager switches the master clock. The class driver exposes a race condition in handling the new master clock. If the minidriver calls a stream class master clock routine immediately after it receives a new clock from the class driver, the class driver may produce unexpected results.

## See also

[HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context)

[StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine)

[StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85))

[StreamClassQueryMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclock)