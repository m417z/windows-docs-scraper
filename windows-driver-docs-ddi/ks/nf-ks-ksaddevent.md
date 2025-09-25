# KsAddEvent function

## Description

The **KsAddEvent** function adds an event to *Object*'s event list.

## Parameters

### `Object` [in]

The object to which to add the event.

### `EventEntry` [in]

A pointer to an [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure describing the event to add to *Object*.

## Remarks

Minidrivers typically do not call this routine directly; instead, they use [KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent) or [KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent).

After events have been added to the event list, these events can be generated as data events by a **Ks***Xxx***GenerateEvents** call. Typecasting of the object (a filter or pin) to PVOID must be provided by the caller.

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsDefaultAddEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdefaultaddeventhandler)

[KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent)

[KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents)

[KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent)