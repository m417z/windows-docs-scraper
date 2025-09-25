# IKsControl::KsEvent (ks.h)

## Description

The **IKsControl::KsEvent** method enables or disables an event, together with any other defined support operations available on an event set.

## Parameters

### `Event`

Pointer to a [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) structure that describes an event to enable the event and **NULL** to disable the event.

### `EventLength`

Specifies size, in bytes, of the buffer at *Event* when the event is enabled and zero when the event is disabled.

### `EventData`

Pointer to a [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that contains data for the event and buffer space that receives data for the event.

### `DataLength`

Specifies size, in bytes, of the buffer at *EventData*.

### `BytesReturned`

Pointer to a variable that receives the size, in bytes, of the data that **KsEvent** stores in the buffer at *EventData*.

## Return value

The **IKsControl::KsEvent** method returns the same value that would be returned if the event had been sent by IOCTL.

## Remarks

To disable an event, set *Event* to **NULL**, *EventLength* to zero, and *EventData* to the pointer to the [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that was previously used to enable the event.

## See also

[KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)