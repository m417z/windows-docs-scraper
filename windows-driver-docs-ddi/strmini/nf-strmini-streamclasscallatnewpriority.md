## Description

The **StreamClassCallAtNewPriority** routine schedules a routine to be called at a different priority.

## Parameters

### `StreamObject` [in, optional]

Pointer to an HW_STREAM_OBJECT structure specifying the stream is associated with the routine, or **NULL** if the routine is associated with the device as a whole. There can be only one routine per stream, and only one routine for the device. This parameter is optional.

### `HwDeviceExtension` [in]

Pointer to the minidriver's device extension. The minidriver specifies the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver then passes pointers to the buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `Priority` [in]

Specifies one of the values listed in the following table.

| Priority | Usage |
|---|---|
| High | The stream class driver calls the routine at the same priority as the minidriver's **StrMini***Xxx* callbacks. Do not use this setting unless the routine must be synchronized with the minidriver's interrupt service routine. |
| Dispatch | The stream class driver calls the routine at DISPATCH_LEVEL. Use this priority if the routine takes less than 1 millisecond to complete. |
| Low | The stream class driver calls the routine at PASSIVE_LEVEL. Use this priority if the routine takes less than 1 millisecond to complete. |
| LowToHigh | Used to allow a thread called at low priority to return to high priority so that other stream class driver services can be called. |

### `PriorityRoutine` [in]

Pointer to a minidriver-supplied [StrMiniPriorityRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_priority_routine) to be called at the specified priority level.

### `Context` [in]

Specifies the parameter to be passed to the *PriorityRoutine*.

## Return value

None