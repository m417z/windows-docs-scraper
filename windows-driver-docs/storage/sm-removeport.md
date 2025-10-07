# SM\_RemovePort function

The SM\_RemovePort WMI method configures the WMI provider so that it stops passing events that are associated with the indicated port to the WMI client.

## Parameters

*PortWWN*
A worldwide name (WWN) that indicates the port that should be removed from the list of ports whose events are reported to the WMI client.

*EventType*
The type of the event. The values that can be assigned to this member are defined by the EVENT\_TYPES\_QUALIFIERS WMI class qualifier.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_RemovePort\_OUT structure.

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

[**SM\_RemovePort\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removeport_in)

[**SM\_RemovePort\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removeport_out)

