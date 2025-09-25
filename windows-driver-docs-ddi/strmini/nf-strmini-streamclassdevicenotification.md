## Description

Minidrivers use the **StreamClassDeviceNotification** routine to notify the class driver that it has completed a stream request, or that an event has occurred.

## Parameters

### `NotificationType` [in]

This is an enumeration value that contains the type of notification that the minidriver is sending.

#### DeviceRequestComplete

Indicates that the minidriver has completed its handling of the device stream request block. Once the minidriver calls **StreamClassDeviceNotification** with this value, the relevant SRB is owned by the class driver, which is free to deallocate it.

#### ReadyForNextDeviceRequest

Indicates that the minidriver is ready to receive another device request.

#### SignalDeviceEvent

Signals that the event specified by an optional parameter has occurred.

#### SignalMultipleDeviceEvents

Signals all events that match the criteria specified in optional parameters.

#### DeleteDeviceEvent

Deletes the event specified by an optional parameter.

### `HwDeviceExtension` [in]

Pointer to the minidriver's device extension. The minidriver specifies the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver then passes pointers to the buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `...`

## Remarks

The minidriver uses this routine for requests or events that apply to the minidriver as a whole. Stream-specific requests or events use [StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification).

## See also

[StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification)