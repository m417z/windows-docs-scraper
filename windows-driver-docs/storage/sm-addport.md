# SM\_AddPort function

The SM\_AddPort WMI method configures the WMI provider to inform the WMI client about events that are associated with the indicated port.

## Parameters

*PortWWN*
A worldwide name (WWN) that indicates the port whose events are to be reported.

*EventType*
The type of the event. The values that can be assigned to this member are defined by the EVENT\_TYPES\_QUALIFIERS WMI class qualifier.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_AddPort\_OUT structure.

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

[**SM\_AddPort\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_addport_in)

[**SM\_AddPort\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_addport_out)

