# KsDefaultAddEventHandler function

## Description

The **KsDefaultAddEventHandler** function is a default routine to handle event 'add' requests.

## Parameters

### `Irp` [in]

The event [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp). This contains the object into which the event is inserted.

### `EventData` [in]

A pointer to a [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that describes an event notification method.

### `EventEntry` [in, out]

The event entry that is to be inserted into the object's event list. The object is determined by *Irp*.

## Return value

Returns the success or failure of adding the event into the object's event list.

## Remarks

**KsDefaultAddEventHandler** determines the relevant object from *Irp* and adds the specified event to the object's event list.

This is functionally equivalent to [KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent) (or **Ks***Xxx***AddEvent**, see below) for the object that is associated with *Irp*. Use **KsDefaultAddEventHandler** from a minidriver-specified *AddEvent* handler to insert the event into the object's event list.

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent)

[KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent)

[KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents)

[KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent)