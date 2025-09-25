# PREGISTER_NOTIFICATION_CALLBACK callback function

## Description

The RegisterNotificationCallback routine registers a callback routine so that it can receive DMA progress notifications with more accurate timing information.

## Parameters

### `_context`

Specifies the context value from the Context member of the [HDAUDIO_BUS_INTERFACE_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v3) structure.

### `Handle`

Handle that identifies the DMA engine. This handle value was obtained from a previous call to AllocateCaptureDmaEngine or AllocateRenderDmaEngine.

### `Fdo`

The FDO that owns the callback. The hdaudbus driver will take a reference on this FDO while the callback is registered to ensure the callback routine is valid.

### `NotificationCallback`

The callback routine that will be called to notify the driver as DMA is progressing. Depending on the notification count parameter that is used with AllocateDmaBufferWithNotification, the registered event is signaled one or two times for every time that the DMA passes through the audio buffer.

### `CallbackContext`

Driver-specific context value for the callback routine.

## Return value

RegisterNotificationCallback returns STATUS_SUCCESS if the call successfully registers the event. Otherwise, the routine returns STATUS_INSUFFICIENT_RESOURCES to indicate that there are insufficient resources that are available to complete the operation.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Prototype

The function pointer type for a RegisterNotificationCallback routine is defined as follows.

```cpp
//Declaration

PREGISTER_NOTIFICATION_CALLBACK PRegisterNotificationCallback;

// Definition

NTSTATUS PRegisterNotificationCallback
(
	PVOID _context
	HANDLE Handle
	PDEVICE_OBJECT Fdo
	PHDAUDIO_DMA_NOTIFICATION_CALLBACK NotificationCallback
	PVOID CallbackContext
)
{...}

```

## Remarks

RegisterNotificationCallback registers the notification callback routine with the HD Audio bus driver. The HD Audio bus driver maintains a list of the registered notification events and callback routines for each DMA engine. Every time the engine receives an IOC interrupt all events will be signaled and all notification callback routines will be called at IRQL=DPC with the QPC timestamp at the time the IOC occurred.

Notification Callback routines are unregistered by calling UnregisterNotificationCallback with the same NotificationCallback and CallbackContext values.

The HD Audio bus driver will maintain a reference on the FDO after registration until the matching unregistration is called.

## See also

[HDAUDIO_BUS_INTERFACE_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v3)

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)