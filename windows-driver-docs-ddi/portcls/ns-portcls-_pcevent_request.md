# _PCEVENT_REQUEST structure

## Description

The **PCEVENT_REQUEST** structure specifies an event request.

## Members

### `MajorTarget`

[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointer to the main miniport object. This member contains the *UnknownMiniport* pointer that the adapter driver previously passed to the [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init) method.

### `MinorTarget`

[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointer to a stream object that is associated with the *MajorTarget* miniport object. This member contains the stream-object pointer that the port driver previously retrieved from the IMiniport*Xxx*::NewStream method (for example, the [IMiniportWaveCyclic::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavecyclic-newstream) method's *Stream* parameter).

### `Node`

Specifies a node ID. This member identifies the target node for the request. If the target is not a node, this member is set to ULONG(-1).

### `EventItem`

Pointer to the [PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item) structure for this request

### `EventEntry`

Pointer to the [KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry) structure for this request

### `Verb`

Specifies the type of event request. This member should be set to one of the values in the following table.

| Value | Meaning |
| --- | --- |
| PCEVENT_VERB_ADD | Indicates that a client wants to enable the specified event. After validating the event and target information, the [EventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nc-portcls-pcpfnevent_handler) routine adds the event by calling the [IPortEvents::AddEventToEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportevents-addeventtoeventlist) method. |
| PCEVENT_VERB_REMOVE | Notifies the [EventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nc-portcls-pcpfnevent_handler) that an event is being disabled and removed from the list. |
| PCEVENT_VERB_SUPPORT | This request is a query for support. If the miniport driver supports the event for the target identified in the request, it should succeed this query. Otherwise, it should fail the query. |
| PCEVENT_VERB_NONE | No action is needed. |

### `Irp`

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) containing the event request

## Remarks

This is the structure that the port driver passes to the miniport driver's [EventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nc-portcls-pcpfnevent_handler) routine. The [PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item) structure contains a function pointer to an event handler that takes a **PCEVENT_REQUEST** pointer as its only call parameter. The port driver allocates a **PCEVENT_REQUEST** structure, extracts the relevant information from the original event request (which the **Irp** member points to), and loads the information into this structure before calling the handler.

In WDM audio, the target of an event request can be a pin instance but not a filter instance. The target can also include a node ID.

The **MajorTarget** and **MinorTarget** members are [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointers to the main miniport object and an associated stream object, respectively. The event handler can query these objects for their miniport and stream interfaces.

For example, if the target for the event request is a pin instance on a WaveCyclic filter:

* The handler can call [QueryInterface](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the **MajorTarget** object's [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface to obtain a reference to the object's [IMiniportWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavecyclic) interface.
* The handler can call [QueryInterface](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the **MinorTarget** object's [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface to obtain a reference to the object's [IMiniportWaveCyclicStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavecyclicstream) interface.

## See also

[EventHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nc-portcls-pcpfnevent_handler)

[IPortEvents::AddEventToEventList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportevents-addeventtoeventlist)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[PCEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcevent_item)

[PCFILTER_NODE](https://learn.microsoft.com/previous-versions/ff537695(v=vs.85))