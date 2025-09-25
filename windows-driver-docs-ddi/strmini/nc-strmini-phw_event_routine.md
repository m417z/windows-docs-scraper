# PHW_EVENT_ROUTINE callback function

## Description

The class driver calls the stream minidriver's *StrMiniEvent* routine to signal to a minidriver an event should be enabled or disabled.

## Parameters

### `EventDescriptor` [in]

Describes the event, and whether it should be enabled or disabled.

## Return value

For event enable events, *StrMiniEvent* returns STATUS_SUCCESS if the event is successfully enabled, or an error code on failure. The class driver ignores the return value on disable requests.

## Remarks

The class driver queues the [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure it passes in *EventDescriptor*->**EventEntry**. Every other member of *EventDescriptor* is deallocated once *StrMiniEvent* exits, so any event-specific data contained in the **EventData** member of *EventDescriptor* that the minidriver needs to keep should be stored by the minidriver.

For that purpose, the minidriver can allocate space directly after the KSEVENT_ENTRY structure by providing a nonzero value in the **ExtraEntryData** member of the [KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item) structure it used to declare the event.