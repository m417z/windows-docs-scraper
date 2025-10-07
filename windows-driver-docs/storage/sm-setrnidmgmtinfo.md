# SM\_SetRNIDMgmtInfo function

The SM\_SetRNIDMgmtInfo WMI method sets FC3 management information that is associated with a fibre channel adapter.

## Parameters

*MgmtInfo*
A structure of type HBAFC3MgmtInfo that holds FC3 management information that is associated with a fibre channel adapter.

*HBAStatus*
A WMI qualifier value that indicates the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_GetRNIDMgmtInfo\_OUT structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the MS\_SM\_FabricAndDomainManagementMethods WMI Class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**SM\_SetRNIDMgmtInfo\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_setrnidmgmtinfo_in)

[**SM\_SetRNIDMgmtInfo\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_setrnidmgmtinfo_out)

