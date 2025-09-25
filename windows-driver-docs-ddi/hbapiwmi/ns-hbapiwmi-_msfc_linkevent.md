# _MSFC_LinkEvent structure

## Description

A WMI provider uses the MSFC_LinkEvent structure to report link events for the indicated adapter.

## Members

### `EventType`

Indicates the type of the event. The values that can be assigned to this member are defined by the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) WMI class qualifier.

### `AdapterWWN`

Contains a worldwide name that indicates the adapter for which the event occurred.

### `RLIRBufferSize`

Indicates the size of the buffer at **RLIRBuffer**.

### `RLIRBuffer`

Contains the data associated with a register link incident request (RLIR).

## See also

[EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers)