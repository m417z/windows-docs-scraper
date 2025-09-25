# PFNKSADDEVENT callback function

## Description

An AVStream minidriver's *AVStrMiniAddEvent* routine is called when a client registers to be notified of an event. This routine is optional.

## Parameters

### `Irp` [in]

Specifies the IRP describing the event add request.

### `EventData` [in]

Pointer to a [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure describing the notification method for this event.

### `EventEntry` [in]

Pointer to an AVStream-generated [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure describing how the event is triggered.

## Return value

*AVStrMiniAddEvent* should return STATUS_SUCCESS or an error specific to the event being enabled.

## Remarks

If you do not provide an add event handler, AVStream adds the event to the object list. See [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream).

Frequently this callback implements vendor-specific behavior and then calls [KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent) or [KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent). The minidriver passes the *EventEntry* pointer received here in calls to *KsFilterAddEvent* or *KsPinAddEvent*.

The minidriver specifies this routine's address in the **AddHandler** member of a [KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item) structure. [Event Handling in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/event-handling-in-avstream) describes how the minidriver provides this structure to the class driver.

If an AVStream minidriver specifies **AddHandler** as non-NULL, AVStream does not add the item to the object's event list. If minidriver specifies an **AddHandler** and does not add the event to the object's event list through **KsDefaultAddEventHandler()** or a **Ks*AddEvent** call, the minidriver is responsible for cleaning up the event.

## See also

[AVStrMiniRemoveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksremoveevent)

[KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item)

[KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)