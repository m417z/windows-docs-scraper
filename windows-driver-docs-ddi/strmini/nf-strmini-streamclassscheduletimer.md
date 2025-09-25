# StreamClassScheduleTimer function

## Description

The minidriver calls the **StreamClassScheduleTimer** routine to schedule a timer, and to specify a routine that is called when the timer expires.

## Parameters

### `StreamObject` [in, optional]

Specifies the stream that sets the timer, or **NULL** if the timer is set for the whole driver. The minidriver may only schedule one timer per stream, and one for the driver as a whole. This parameter is optional.

### `HwDeviceExtension` [in]

Pointer to the minidriver's device extension. The minidriver specifies the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver then passes pointers to the buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `NumberOfMicroseconds` [in]

Specifies the amount of time, in microseconds, before the timer expires.

### `TimerRoutine` [in]

Specifies the routine called when the timer expires. The routine's prototype must be of the form:

```cpp
TimerRoutine(PVOID Context);
```

### `Context` [in]

Pointer to a context that the class driver passes to the callback routine once the timer expires.

## Return value

None