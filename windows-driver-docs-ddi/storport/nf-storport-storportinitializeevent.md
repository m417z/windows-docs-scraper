# StorPortInitializeEvent function

## Description

**StorPortInitializeEvent** initializes an event object as a synchronization or notification type event, and sets it to a signaled or not-signaled state.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport's hardware device extension.

### `Event`

Pointer to a caller-allocated [**STOR_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event) structure that describes the event object.

### `Type`

A [**STOR_EVENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_event_type) enum that identifies the event type.

### `State`

Boolean value that specifies the initial state of the event.

## Return value

**StorPortInitializeEvent** returns STOR_STATUS_SUCCESS on success. It returns STOR_STATUS_INVALID_PARAMETER if any of the parameters are invalid.

## Remarks

A miniport can call **StorPortInitializeEvent** to initialize an event object as a synchronization or notification-type event, and set the event object to a signaled or not-signaled state.

See [**KeInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent) for more details.

## See also

[**KeInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[**STOR_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event)

[**STOR_EVENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_event_type)

[**StorPortSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetevent)

[**StoPortWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwaitforsingleobject)