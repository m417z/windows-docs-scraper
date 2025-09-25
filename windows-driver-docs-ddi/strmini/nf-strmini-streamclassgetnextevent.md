## Description

Minidrivers can use the **StreamClassGetNextEvent** routine to search the event queue of a device or of a particular stream.

## Parameters

### `HwInstanceExtension_OR_HwDeviceExtension` [in, optional]

Pointer to the minidriver's device extension. The minidriver specifies the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver then passes pointers to the buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

This first parameter was PVOID HwDeviceExtension. It MUST be HwInstanceExtension for multi-instance and multi-filter types (version 20) drivers. Legacy single instance drivers can continue to specify HwDeviceExtension as the first parameter. It can also specify HwInstanceExtension.

### `HwStreamObject` [in, optional]

Pointer to a [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object). Set to **NULL** to search the event queue of the device itself. To search the event queue of a particular stream, set to the stream's stream object.

### `EventGuid` [in, optional]

Specifies the event set to match when walking the queue, or **NULL** to match any event set.

### `EventItem` [in]

Specifies the event ID to match when walking the queue, or -1 to match any event.

### `CurrentEvent` [in, optional]

Pointer to an event in the event queue, or **NULL**.

## Return value

If *CurrentEvent* is not **NULL**, **StreamClassGetNextEvent** returns the next matching event after *CurrentEvent* in the queue (or **NULL** if there is no such next event). If *CurrentEvent* is **NULL**, **StreamClassGetNextEvent** returns the first matching event in the queue.

## Remarks

The minidriver can call **StreamClassGetNextEvent** successively to loop through the event queue, examining one event at a time.

The caller may specify additional search criteria to match events on the event queue.