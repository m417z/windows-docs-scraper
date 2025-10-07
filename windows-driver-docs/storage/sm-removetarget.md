# SM\_RemoveTarget function

The SM\_RemoveTarget WMI method configures the WMI provider so that it stops passing events that are associated with the indicated target to the WMI client.

## Parameters

*HbaPortWWN*
A 64-bit worldwide name (WWN) that uniquely identifies the local port that should be removed from the list of ports whose events are reported to the WMI client. For more information about worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

*DiscoveredPortWWN*
A worldwide name (WWN) that indicates the remote discovered port that should be removed from the list of ports whose events are reported to the WMI client.

*AllTargets*
The events to stop reporting. If this member is zero, the WMI provider client stops reporting events that are associated with the port that is indicated by DiscoveredPortWWN. If this member is nonzero, the WMI provider stops reporting all events associated any target.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_RemoveTarget\_OUT structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the MS\_SM\_EventControl WMI Class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**SM\_RemoveTarget\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removetarget_in)

[**SM\_RemoveTarget\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removetarget_out)

