# PCPFNEVENT_HANDLER callback function

## Description

An `EventHandler` routine processes event requests.

## Parameters

### `EventRequest` [in]

Pointer to an initialized [PCEVENT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcevent_request) structure

## Return value

The event handler returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

Each event that a miniport driver exposes is associated with an event handler. The purpose of the event handler is to process event requests from the port driver and its clients. *EventRequest* is an input parameter to the handler that contains the following information about the event:

* The event set GUID and event ID.
* How the event is to be triggered.
* Pointers to the target miniport object and (for a pin) stream object.

This is similar to the type of information that is provided with property requests.

The miniport driver exposes its event handlers through its [IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription) method. This method outputs a descriptor structure (see [PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor)) that defines the filter that the miniport driver and its associated port driver implement together. This structure contains a pointer to the miniport driver's automation table (see [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table)), which in turn contains a pointer to an array of the miniport driver's events. Each array element is a [PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item) structure and contains a PCPFNEVENT_HANDLER function pointer to the handler for the event.

The `EventHandler` routine must reside in nonpaged memory.

## See also

[IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription)

[IPortEvents::AddEventToEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportevents-addeventtoeventlist)

[IPortEvents::GenerateEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportevents-generateeventlist)

[PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table)

[PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item)

[PCEVENT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcevent_request)

[PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor)