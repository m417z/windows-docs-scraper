## Description

Each stream may have a clock associated to it. The class driver queries the clock by calling the stream minidriver-supplied *StrMiniClock* function, provided in each stream's [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object).

## Parameters

### `TimeContext` [in]

Pointer to the [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context) structure that *StrMiniClock* must fill out with the requested information.

## Remarks

A stream specifies its *StrMiniClock* function within the **HwClockFunction** member of the [HW_CLOCK_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_clock_object) substructure of its [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object). The minidriver fills out the **HW_STREAM_OBJECT** for a stream within its [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routine in response to a SRB_OPEN_STREAM request.

When the class driver calls *StrMiniClock*, it fills in the **HwDeviceExtension**, **HwStreamObject**, and **Function** members of the *TimeContext* parameter. It expects *StrMiniClock* to fill in the **Time** member with the time value, in 100-nanosecond units, specified in the *Function* parameter. *StrMiniClock* must also fill in the **SystemTime** member with the current system time, by calling [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter), and converting the result to 100-nanosecond units.

The *StrMiniClock* routine must handle the functions specified in the **ClockSupportFlags** of the clock's HW_CLOCK_OBJECT. See [HW_CLOCK_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_clock_object) for details.

## See also

[HW_CLOCK_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_clock_object)

[HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context)