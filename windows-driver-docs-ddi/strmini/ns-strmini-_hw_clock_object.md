# _HW_CLOCK_OBJECT structure

## Description

The HW_CLOCK_OBJECT structure describes the clock associated with a stream.

## Members

### `HwClockFunction`

Pointer to the stream's [StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine) routine.

### `ClockSupportFlags`

Specifies which options the *StrMiniClock* routine supports.

#### CLOCK_SUPPORT_CAN_READ_ONBOARD_CLOCK

The *StrMiniClock* routine can return the current clock value for the stream's clock. The *StrMiniClock* routine must be able to handle a **Function** setting of TIME_READ_ONBOARD_CLOCK in the [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context) structure passed as a parameter.

#### CLOCK_SUPPORT_CAN_RETURN_STREAM_TIME

The *StrMiniClock* routine can return the current presentation time stamp for the stream. The *StrMiniClock* routine must be able to handle a **Function** setting of TIME_GET_STREAM_TIME in the [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context) structure passed as a parameter.

### `Reserved`

Reserved for system use. Do not use.

## See also

[HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object)

[HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context)

[StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine)