# PUNREGISTER_NOTIFICATION_EVENT callback function

## Description

The *UnregisterNotificationEvent* routine deletes the registration of an event that was previously registered by a call to [RegisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_event).

The function pointer type for an *UnregisterNotificationEvent* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the Context member of the [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2) structure.

### `Handle` [in]

Handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `NotificationEvent` [in]

A pointer to a kernel event that was previously registered for DMA progress notification with a call to [RegisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_event).

## Return value

*UnregisterNotificationEvent* returns STATUS_SUCCESS if the call successfully unregisters the notification event. Otherwise, the routine returns STATUS_INVALID_PARAMETER to indicate that the specified callback routine and context are not valid.

## See also

[AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine)

[AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[RegisterNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_event)

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)