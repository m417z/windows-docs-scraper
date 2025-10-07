# SM\_RemoveLink function

The SM\_RemoveLink WMI method configures the WMI provider so that it stops passing fabric link event information to the WMI client.

## Parameters

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_RemoveLink\_OUT structure.

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

[**SM\_RemoveLink\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removelink_out)

