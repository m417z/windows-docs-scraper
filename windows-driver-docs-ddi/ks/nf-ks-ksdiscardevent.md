# KsDiscardEvent function

## Description

The **KsDiscardEvent** function discards the memory used by an event entry after the objects have been dereferenced. The function can be called when manually disabling events that have not been disabled by the event owner (by calling the **KsFreeEventList** function to disable events). For example, the function can be called when asynchronously enabling an event fails and the event entry needs to be discarded.

## Parameters

### `EventEntry` [in]

Specifies the pointer to the entry to discard. This pointer is no longer valid after a successful call to this function.

## Return value

None

## Remarks

Typically, the **KsDiscardEvent** function is automatically called by the [KsDisableEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdisableevent) function when a request to disable an event occurs, or by the [KsFreeEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeeventlist) function when a request to free a list of events occurs. This function can only be called at PASSIVE_LEVEL.

## See also

[KsDisableEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdisableevent)

[KsFreeEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeeventlist)