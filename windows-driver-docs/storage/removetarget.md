# RemoveTarget function

The **RemoveTarget** WMI method configures the WMI provider so that it stops passing events associated with the indicated target to the WMI client.

## Parameters

*HbaPortWWN*
A 64 bit worldwide name (WWN) that uniquely identifies the local port that should be removed from the list of ports whose events are reported to the WMI client. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

*DiscoveredPortWWN*
A WWN that indicates the remote discovered port that should be removed from the list of ports whose events are reported to the WMI client.

*AllTargets*
The events to stop reporting. If this member is zero, the WMI provider client will stop reporting events associated with the port that is indicated by *DiscoveredPortWWN*. If this member is nonzero, the WMI provider will cease reporting all events associated any target.

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**RemoveTarget\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_removetarget_out) structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_EventControl WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventcontrol-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |

## See also

[**RemoveTarget\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_removetarget_in)

[**RemoveTarget\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_removetarget_out)

