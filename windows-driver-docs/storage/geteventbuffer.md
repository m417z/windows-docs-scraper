# GetEventBuffer function

The **GetEventBuffer** WMI method retrieves the next events in the HBA's event queue.

## Parameters

*HBAStatus*
On return, contains a WMI qualifier value that indicates the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetEventBuffer\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_geteventbuffer_out) structure.

*EventCount*
On return, indicates the number of events whose information was retrieved. The miniport driver returns this information in the **EventCount** member of a [**GetEventBuffer\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_geteventbuffer_out) structure.

*Events\[\]*
An array of structures of type [**MSFC\_EventBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_eventbuffer) that contain information about the next events in the HBA event queue. The miniport driver returns this information in the **Events** member of a [**GetEventBuffer\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_geteventbuffer_out) structure.

## Return value

Not applicable to WMI methods.

## Remarks

The **GetEventBuffer** method removes events from the queue after retrieving their information.

This WMI method belongs to the [MSFC\_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |
| Library | Hbaapi.lib |

## See also

[**GetEventBuffer\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_geteventbuffer_out)

[**MSFC\_EventBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_eventbuffer)

