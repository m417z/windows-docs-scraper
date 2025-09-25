# IPortEvents::AddEventToEventList

## Description

The `AddEventToEventList` method adds an event to the port driver's event list.

## Parameters

### `EventEntry` [in]

Pointer to the event entry that describes the event. This is an opaque system structure of type [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry).

## Remarks

This method is used by a miniport driver's to add events to the event list that is maintained by the associated port object. The miniport driver's event handler typically calls this method in response to a PCEVENT_VERB_ADD request after the handler has validated support for the event being requested.

## See also

[EventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nc-portcls-pcpfnevent_handler)

[IPortEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportevents)

[IPortEvents::GenerateEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportevents-generateeventlist)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)