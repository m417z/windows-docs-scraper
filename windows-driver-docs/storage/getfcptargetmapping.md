# GetFcpTargetMapping function

The **GetFcpTargetMapping** WMI method retrieves a mapping between the information that uniquely identifies a set of logical units for the operating system and the Fibre Channel protocol (FCP) identifiers for these logical units.

## Parameters

*HbaPortWWN\[8\]*
A worldwide name for the port whose table of mappings is to be retrieved. This information is delivered to the miniport driver in the **HbaPortWWN** member of a [**GetFcpTargetMapping\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcptargetmapping_in) structure.

*InEntryCount*
Indicates the number of binding entries that the WMI provider can report in the *Entry* parameter.

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetFcpTargetMapping\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcptargetmapping_out) structure.

*TotalEntryCount*
Indicates the total number of persistent bindings associated with the HBA.

*OutEntryCount*
Indicates the total number of mappings retrieved by the **GetFcpTargetMapping** method. This value will be less than or equal to *TotalEntryCount*.

*Entry\[\]*
An array of structures of type [**HBAFCPScsiEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpscsientry) that describe an HBA's bindings between operating system and Fibre Channel protocol (FCP) identifiers.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |
| Library | Hbaapi.lib |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**GetFcpTargetMapping\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcptargetmapping_in)

[**GetFcpTargetMapping\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcptargetmapping_out)

