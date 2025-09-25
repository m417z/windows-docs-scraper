# KsFilterAddEvent function

## Description

The **KsFilterAddEvent** function adds an event to *Filter*'s event list.

## Parameters

### `Filter` [in]

*A pointer* to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure representing the filter to which to add a specified event.

### `EventEntry` [in]

*A pointer* to an [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure describing the event to add to *Filter*.

## Remarks

This function is an inline function call to [KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent).

## See also

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KsAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddevent)

[KsGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgenerateevents)