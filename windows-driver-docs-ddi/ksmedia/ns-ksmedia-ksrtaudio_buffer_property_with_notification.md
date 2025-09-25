# KSRTAUDIO_BUFFER_PROPERTY_WITH_NOTIFICATION structure

## Description

The KSRTAUDIO_BUFFER_PROPERTY_WITH_NOTIFICATION structure appends a buffer base address, a requested buffer size, and a notification count to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure. This structure is used by the client to request allocation of the audio buffer via [KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification).

## Members

### `Property`

A KSPROPERTY structure that the client initializes appropriately prior to calling KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION.

### `BaseAddress`

Specifies the buffer base address. Unless the client specifies a base address, this parameter is set to **NULL**.

### `RequestedBufferSize`

Specifies the buffer size in bytes. The driver returns the actual size of the allocated buffer in the [KSRTAUDIO_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_buffer) structure that it returns.

### `NotificationCount`

Specifies the number of notifications per cycle of the cyclic buffer. Currently, the valid values are 1 or 2. A value of 1 results in notification to registered notification events at the end of the cyclic buffer. A value of 2 results in notifications at both the mid-point and the end of the cyclic buffer.

## Remarks

The KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION request uses the KSRTAUDIO_BUFFER_PROPERTY_WITH_NOTIFICATION structure to describe the cyclic buffer that the client requests. The driver returns a KSRTAUDIO_BUFFER structure to describe the buffer actually allocated.

As with KSPROPERTY_RTAUDIO_BUFFER, the value that the client writes into the **RequestedBufferSize** member is not binding on the driver.

Using KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION facilitates event signaling as DMA progresses through the cyclic buffer. [KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event) is used to register events to receive these notifications and [KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-unregister-notification-event) is used to unregister events.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification)

[KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event)

[KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-unregister-notification-event)