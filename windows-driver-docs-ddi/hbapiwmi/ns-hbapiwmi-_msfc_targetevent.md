# _MSFC_TargetEvent structure

## Description

A WMI provider uses the MSFC_TargetEvent structure to report port events for the indicated adapter.

## Members

### `EventType`

Indicates the type of the event. The values that can be assigned to this member are defined by the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) WMI class qualifier.

### `PortWWN`

Contains a worldwide name that indicates the local port for which the event occurred.

### `DiscoveredPortWWN`

Contains a worldwide name that indicates the remote port for which the event occurred.

## See also

[EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers)