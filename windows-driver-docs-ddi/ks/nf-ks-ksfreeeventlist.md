# KsFreeEventList function

## Description

The **KsFreeEventList** function handles freeing all events from a specified list, with the assumption that these events are composed of **KSEVENT_ENTRY** structures. This function can only be called at PASSIVE_LEVEL.

## Parameters

### `FileObject` [in]

Specifies the file object passed to the removal function for context information. The file object associated is used to compare against the file object originally specified when enabling the event. This allows a single event list to be used for multiple clients differentiated by file objects.

### `EventsList` [in, out]

Points to the head of the list of KSEVENT_ENTRY items to be freed. If any events on the list are currently being disabled, they are passed over. If any new elements are added to the list while it is being processed, they may not be freed.

### `EventsFlags` [in]

Specifies a [KSEVENTS_LOCKTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksevents_locktype) flag specifying the type of exclusion lock to be used in accessing the event list. If no flag is set, then no lock is taken.

### `EventsLock` [in]

Used to synchronize access to an element on the list. After the element has been accessed, it is marked as being deleted so subsequent removal requests fail. The lock is then released after calling the removal function, if any. The removal function must synchronize with event generation before actually removing the element from the list.

## Return value

None

## Remarks

The **KsFreeEventList** function calls the remove handler, and then it calls **KsDiscardEvent** for each event. It does not assume that the caller is the event owner.

## See also

[KsDiscardEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdiscardevent)