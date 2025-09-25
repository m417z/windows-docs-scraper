# _HW_TIME_CONTEXT structure

## Description

The class driver passes an HW_TIME_CONTEXT structure as a parameter to be filled in by a stream's [StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine) routine, or returns a completed HW_TIME_CONTEXT structure when it responds to a [StreamClassQueryMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclock) or [StreamClassQueryMasterClockSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclocksync) request.

## Members

### `HwDeviceExtension`

Points to the minidriver's device extension buffer. The class driver fills in this member when it passes the structure to a stream's [StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine), or to the callback passed to [StreamClassQueryMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclock). When passed as a parameter to [StreamClassQueryMasterClockSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclocksync), the caller must fill in this member itself.

The minidriver may use its device extension to record private information global to the minidriver. The minidriver sets the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver also passes pointers to this buffer in the **HwDeviceExtension** member of the [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `HwStreamObject`

When the class driver passes HW_TIME_CONTEXT to a stream's [StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine) routine, this member points to the stream's [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object) structure.

When the class driver passes a completed HW_TIME_CONTEXT structure to the callback provided by [StreamClassQueryMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclock), it fills in this member with a pointer to the stream object of the stream that makes the query request.

### `Function`

Specifies the type of time value that is stored in the **Time** member. The possible values are:

#### TIME_GET_STREAM_TIME

The **Time** member holds the current presentation time stamp.

#### TIME_READ_ONBOARD_CLOCK

The **Time** member holds the current clock time.

### `Time`

The time value, in 100-nanosecond units, specified by the **Function** member.

### `SystemTime`

The current system time, in 100-nanosecond units.

## See also

[HW_CLOCK_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_clock_object)

[StrMiniClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_query_clock_routine)

[StreamClassQueryMasterClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclock)

[StreamClassQueryMasterClockSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassquerymasterclocksync)