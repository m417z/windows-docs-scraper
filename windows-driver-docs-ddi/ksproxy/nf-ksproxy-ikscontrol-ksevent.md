# IKsControl::KsEvent (ksproxy.h)

## Description

The **KsEvent** method enables or disables an event, along with any other defined support operations available on an event set.

## Parameters

### `Event` [in, optional]

Pointer to a [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) structure that describes an event to enable the event and **NULL** to disable the event.

### `EventLength` [in]

Size, in bytes, of the buffer at *Event* when the event is enabled and zero when the event is disabled.

### `EventData` [in, out]

Pointer to a [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that contains data for the event and buffer space that receives data for the event.

### `DataLength` [in]

Size, in bytes, of the buffer at *EventData*.

### `BytesReturned` [in, out]

Pointer to a variable that receives the size, in bytes, of the data that **KsEvent** stores in the buffer at *EventData*.

## Return value

Returns NOERROR if successful; otherwise, returns an error code. If the call succeeds, the event is on the driver's list of events.

## Remarks

To disable an event, set *Event* to **NULL**, *EventLength* to zero, and *EventData* to the pointer to the [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that was previously used to enable the event.

The *EventData* parameter of **IKsControl::KsEvent** contains a handle in **EventHandle.Event**. You can wait for the handle to become available and get notifications when the minidriver calls **Ks***Xxx***GenerateEvents** or [StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification).

## See also

[KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)