# PCEVENT_ITEM structure

## Description

The **PCEVENT_ITEM** structure is used to describe an event that is supported by a particular filter, pin, or node.

## Members

### `Set`

Specifies the event set. This member is a pointer to a GUID that uniquely identifies the event set. See the list of event-set GUIDs in [Audio Drivers Event Sets](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-drivers-event-sets).

### `Id`

Specifies the event ID. This member identifies an event item within the event set. If the event set contains N items, valid event IDs are integers in the range 0 to N-1.

### `Flags`

Specifies the type of event. This member is set to one of the following values:

#### PCEVENT_ITEM_FLAG_ENABLE

Indicates the event notification should be enabled for this event type. The driver should continue event notification until the client explicitly disables it.

#### PCEVENT_ITEM_FLAG_ONESHOT

Indicates that the event notification should be enabled for the next occurrence of this event only. The client does not (and should not) disable the event once it has occurred.

#### PCEVENT_ITEM_FLAG_BASICSUPPORT

If the client specifies this flag, the driver returns STATUS_SUCCESS if it supports the event and an error code if it does not.

### `Handler`

Pointer to the miniport driver's event-handler routine. This member is a function pointer of type PCPFNEVENT_HANDLER, which is defined as follows:

```
  typedef NTSTATUS (*PCPFNEVENT_HANDLER)
  (
      IN PPCEVENT_REQUEST  EventRequest
  );
```

When calling the **Handler** routine, the caller passes in a single call parameter, which is a pointer to a caller-allocated [PCEVENT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcevent_request) structure.

## Remarks

The **PCEVENT_ITEM** structure specifies a particular event item in an automation table. The [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table) structure points to an array of **PCEVENT_ITEM** structures.

In WDM audio, the target for an event request is either a pin instance or a node on a pin. A filter instance cannot be the target of an event request.

## See also

[PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table)

[PCEVENT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcevent_request)