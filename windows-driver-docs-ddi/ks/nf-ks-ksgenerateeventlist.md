# KsGenerateEventList function

## Description

The **KsGenerateEventList** function enumerates the event list and searches for the specified event to generate.

## Parameters

### `Set` [in, optional]

Specifies an optional set that the event to be generated belongs to. If present, this value is compared against the set identifier for each event in the list. If not present, the set identifiers are ignored and just the specific event identifier is used in the comparison for matching events on the list. This comparison saves time when all events are known to be contained in a single set.

### `EventId` [in]

Specifies the specific event identifier to look for on the list.

### `EventsList` [in]

Points to the head of the list of KSEVENT_ENTRY items on which the event can be found.

### `EventsFlags` [in]

Specifies the [KSEVENTS_LOCKTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksevents_locktype) flag specifying the exclusion lock type to be used in accessing the event list. If no flag is set, then no lock is taken.

### `EventsLock` [in]

Used to synchronize access to an element on the list. The lock is taken before enumerating the list and released after enumeration.

## Return value

None

## Remarks

This function can be called at any IRQL level if the locking mechanism permits it.

## See also

[KsFilterAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteraddevent)

[KsFilterGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergenerateevents)

[KsPinAddEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinaddevent)

[KsPinGenerateEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingenerateevents)