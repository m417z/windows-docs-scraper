# _MSFC_PortEvent structure

## Description

A WMI provider uses the MSFC_PortEvent structure to report port events for the indicated adapter.

## Members

### `EventType`

Indicates the type of the event. The values that can be assigned to this member are defined by the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) WMI class qualifier.

### `FabricPortId`

Contains the fabric port ID.

### `PortWWN`

Contains the worldwide name that indicates the port for which the event occurred.

## See also

[EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers)