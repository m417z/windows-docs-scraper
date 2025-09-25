# IPortEvents::GenerateEventList

## Description

The `GenerateEventList` method notifies clients through the port driver's list of event entries that a particular event has occurred.

## Parameters

### `Set` [in, optional]

Identifies the event set that the event belongs to. This parameter is a pointer to a GUID. *Set* is an optional parameter. A *Set* value of **NULL** is a wild card that matches all event-set GUIDs in the list. Otherwise, only event entries with matching event-set GUIDs are signaled.

### `EventId` [in]

Specifies an event ID. This parameter specifies the index of the event in the event set. If an event set contains *n* events, valid event IDs are in the range 0 to *n*-1. Only event entries with matching event IDs are signaled.

### `PinEvent` [in]

Specifies whether *PinId* should be used in qualifying which event entries to signal. If *PinEvent* is **FALSE**, *PinId* is treated as a wild card that matches all pin IDs in the list.

### `PinId` [in]

Specifies the pin ID of the event to be signaled. If *PinEvent* is **TRUE**, then only event entries with matching pin IDs are signaled.

### `NodeEvent` [in]

Indicates whether *NodeId* should be used in qualifying which event entries to signal. If *NodeEvent* is **FALSE**, *NodeId* is treated as a wild card that matches all node IDs in the list.

### `NodeId` [in]

Specifies the node ID of the event to be signaled. If *NodeEvent* is **TRUE**, then only event entries with matching node IDs are signaled.

## Remarks

This method is used by miniport drivers to signal event entries in the port driver's event list. In response to the miniport driver calling this method, the port driver walks its list of event entries and signals all registered event entries that meet the criteria expressed by the call parameters.

Although callers of `GenerateEventList` can be running at any IRQL, they are subject to some limitations when calling at IRQL > DISPATCH_LEVEL. Specifically, if the current implementation of `GenerateEventList` is called at IRQL > DISPATCH_LEVEL, the method queues a DPC to process the event list. That DPC contains the parameter context for a single call. As a result, signaling events might occasionally be missed if multiple calls are made at IRQL > DISPATCH_LEVEL.

## See also

[EventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nc-portcls-pcpfnevent_handler)

[IPortEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportevents)

[IPortEvents::AddEventToEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportevents-addeventtoeventlist)