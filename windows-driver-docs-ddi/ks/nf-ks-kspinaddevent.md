# KsPinAddEvent function

## Description

The **KsPinAddEvent** function adds a specified event to *Pin*'s event list.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure to which to add a specified event.

### `EventEntry` [in]

A pointer to a [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure describing the event to add to *Pin*.

## Remarks

This function is an inline function call to [KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent).

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent)

[KsDefaultAddEventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdefaultaddeventhandler)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

**KsGenerateEvents**

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)