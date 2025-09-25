# EVENT_EXTENDED_ITEM_INSTANCE structure (evntcons.h)

## Description

Defines the relationship between events if [TraceEventInstance](https://learn.microsoft.com/windows/desktop/ETW/traceeventinstance) was used to log related events.

## Members

### `InstanceId`

A unique transaction identifier that maps an event to a specific transaction.

### `ParentInstanceId`

A unique transaction identifier of a parent event if you are mapping a hierarchical relationship.

### `ParentGuid`

A GUID that uniquely identifies the provider that logged the event referenced by the **ParentInstanceId** member.

## See also

[EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)