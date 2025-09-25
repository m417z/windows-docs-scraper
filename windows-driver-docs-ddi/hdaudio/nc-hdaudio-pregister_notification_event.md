# PREGISTER_NOTIFICATION_EVENT callback function

## Description

The *RegisterNotificationEvent* routine registers a kernel event so that it can receive DMA progress notifications.

The function pointer type for a *RegisterNotificationEvent* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the Context member of the [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structure.

### `Handle` [in]

Handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `NotificationEvent` [in]

A pointer to a kernel event that must be notified as DMA progresses. Depending on the notification count parameter that is used with [AllocateDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer_with_notification), the registered event is signaled one or two times for every time that the DMA passes through the audio buffer.

## Return value

*RegisterNotificationEvent* returns STATUS_SUCCESS if the call successfully registers the event. Otherwise, the routine returns STATUS_INSUFFICIENT_RESOURCES to indicate that there are insufficient resources that are available to complete the operation.

## Remarks

*RegisterNotificationEvent* registers a kernel event with the HD Audio bus driver. The HD Audio bus driver maintains a list of registered notification events for each DMA engine, and signals them every time that the engine receives an IOC interrupt. Events are unregistered by using [UnregisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_notification_event).

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateDmaBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_dma_buffer_with_notification)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[UnregisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_notification_event)