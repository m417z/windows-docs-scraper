# SM\_AddTarget function

The SM\_AddTarget WMI method configures the WMI provider to inform the WMI client about events that are associated with the indicated targets.

## Parameters

*HbaPortWWN*
The worldwide name (WWN) of the local port whose events the WMI client will receive.

*DiscoveredPortWWN*
A worldwide name (WWN) that specifies the discovered target whose events the WMI client will receive.

*DomainPortWWN*
A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port whose events the WMI client will receive.

*AllTargets*
The scope of the target events to report. If this member is zero, the WMI client receives events that are associated with the port that is indicated by DiscoveredPortWWN. If this member is nonzero, the WMI client receives all events that are associated with all currently discovered targets as well as targets that are discovered in the future.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_AddTarget\_OUT structure.

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

[**SM\_AddTarget\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_addtarget_in)

[**SM\_AddTarget\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_addtarget_out)

