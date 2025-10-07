# AddTarget function

The **AddTarget** WMI method configures the WMI provider to inform the WMI client about events that are associated with the indicated targets.

## Parameters

*HbaPortWWN\[8\]*
The worldwide name of the local port whose events the WMI client will receive.

*DiscoveredPortWWN\[8\]*
A worldwide name that specifies the discovered target whose events the WMI client will receive.

*AllTargets*
The scope of the target events to report. If this member is zero, the WMI client will receive events associated with the port that is indicated by *DiscoveredPortWWN*. If this member is nonzero, the WMI client will receive all events associated with all currently discovered targets as well as targets that are discovered in the future.

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**AddTarget\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_addtarget_out) structure.

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

[**AddTarget\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_addtarget_in)

[**AddTarget\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_addtarget_out)

