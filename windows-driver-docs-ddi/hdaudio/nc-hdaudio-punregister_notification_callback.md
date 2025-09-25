# PUNREGISTER_NOTIFICATION_CALLBACK callback function

## Description

The **PUNREGISTER_NOTIFICATION_CALLBACK** callback function deletes the registration of a notification callback routine that was previously registered by a call to RegisterNotificationCallback.

## Parameters

### `_context:`

Specifies the context value from the Context member of the [HDAUDIO_BUS_INTERFACE_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v3) structure.

### `Handle:`

Handle that identifies the DMA engine. This handle value was obtained from a previous call to [AllocateCaptureDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_capture_dma_engine) or [AllocateRenderDmaEngine](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_render_dma_engine).

### `NotificationCallback:`

A callback routine that was previously registered for DMA progress notification with a call to [PREGISTER_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_callback).

### `CallbackContext:`

Driver-specific context value for the callback routine.

## Return value

PUNREGISTER_NOTIFICATION_CALLBACK returns STATUS_SUCCESS if the call successfully unregisters the notification event. Otherwise, the routine returns STATUS_INVALID_PARAMETER to indicate that the specified callback routine and context are not valid.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Prototype

The function pointer type for an UnregisterNotificationCallback routine is defined as follows.

```cpp
//Declaration

PUNREGISTER_NOTIFICATION_CALLBACK PUnregisterNotificationCallback;

// Definition

NTSTATUS PUnregisterNotificationCallback(
  PVOID _context,
  HANDLE Handle,
  PHDAUDIO_DMA_NOTIFICATION_CALLBACK NotificationCallback,
  PVOID CallbackContext
)
{...}

```

## Remarks

PUNREGISTER_NOTIFICATION_CALLBACK will use both the NotificationCallback and CallbackContext to find the matching previously-registered callback routine to remove.

The HD Audio bus driver will release the reference it took on the driver FDO when the notification callback routine was previously registered.

## See also

[PREGISTER_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_notification_callback)

[HDAUDIO_BUS_INTERFACE_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v3)

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)