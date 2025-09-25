# _MSFC_EventBuffer structure

## Description

The MSFC_EventBuffer structure is used in conjunction with the [GetEventBuffer](https://learn.microsoft.com/windows-hardware/drivers/storage/geteventbuffer) method to retrieve the next events in the HBA's event queue.

## Members

### `EventType`

Indicates the type of the event. The values that can be assigned to this member are defined by the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) WMI class qualifier.

### `EventInfo`

Contains a structure of type [HBA_EventInfo](https://learn.microsoft.com/previous-versions/ff556048(v=vs.85)) that holds information about the events that were retrieved.

## Remarks

The WMI tool suite generates a declaration for this structure in *hbapiwm.h* after compiling the [MSFC_EventBuffer WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventbuffer-wmi-class).

The [HBA_EventInfo](https://learn.microsoft.com/previous-versions/ff556048(v=vs.85)) structure is declared in *hbaapi.h*. You must include *hbaapi.h* to reference this structure.

## See also

[EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers)

[GetEventBuffer](https://learn.microsoft.com/windows-hardware/drivers/storage/geteventbuffer)

[HBA_EventInfo](https://learn.microsoft.com/previous-versions/ff556048(v=vs.85))