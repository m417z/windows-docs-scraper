# KsGenerateEvent function

## Description

The **KsGenerateEvent** function generates a standard event notification given an event entry structure.

## Parameters

### `EventEntry` [in]

Specifies the event entry structure that references the event data. The information is used to determine what type of notification to perform. If the notification type is not one of the predefined standards, an error is returned. In the case of a single, nonrecurring event, this entry will be invalid on returning from the function. Therefore, any code that enumerates a list of events must preincrement to acquire the next event in the list before passing this event to the function.

## Return value

The **KsGenerateEvent** function returns STATUS_SUCCESS if successful, or if unsuccessful it returns an exception or memory error.

## Remarks

A device determines when event notifications are generated using the [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure, then uses this function to perform the actual notification. **KsGenerateEvent** can be called at any IRQL. If called above DISPATCH_LEVEL, signaling of the event will be performed asynchronously in a DPC.

## See also

[KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)