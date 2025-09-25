# _MSFC_AdapterEvent structure

## Description

The MSFC_AdapterEvent structure is used by HBA miniport drivers that support the T11 committee's *Fibre Channel HBA API* specification to report adapter events to WMI clients that have registered to be notified of these events.

## Members

### `EventType`

Indicates the type of the event. The values that can be assigned to this member are defined by the [EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers) WMI class qualifier.

### `PortWWN`

Contains the worldwide name of the port that generated the event.

## Remarks

The WMI tool suite generates a declaration for this structure in *Hbapiwm.h* after compiling the [MSFC_AdapterEvent WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-adapterevent-wmi-class).

For more information about event types and worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

## See also

[EVENT_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/event-types-qualifiers)

[MSFC_AdapterEvent WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-adapterevent-wmi-class)