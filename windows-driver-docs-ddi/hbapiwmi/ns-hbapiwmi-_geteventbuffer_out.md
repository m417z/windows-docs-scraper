# _GetEventBuffer_OUT structure

## Description

The GetEventBuffer_OUT structure is used to report the output parameter data of the [GetEventBuffer](https://learn.microsoft.com/windows-hardware/drivers/storage/geteventbuffer) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `EventCount`

Indicates the number of events in **Events** that were retrieved by the [GetEventBuffer](https://learn.microsoft.com/windows-hardware/drivers/storage/geteventbuffer) WMI method.

### `Events`

Contains an array of type [MSFC_EventBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_eventbuffer) that contains the next events in the HBA's event queue.

## Remarks

The [GetEventBuffer](https://learn.microsoft.com/windows-hardware/drivers/storage/geteventbuffer) method retrieves the next events in the HBA's event queue.

The WMI tool suite generates a declaration of the GetEventBuffer_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetEventBuffer](https://learn.microsoft.com/windows-hardware/drivers/storage/geteventbuffer)