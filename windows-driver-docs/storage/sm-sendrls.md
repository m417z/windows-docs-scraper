# SM\_SendRLS function

The SM\_SendRLS WMI method sends a read link status (RLS) through the indicated local port. This RLS is sent to the indicated remote port to retrieve a link error status block that is associated with the remote port.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the local port through which the RLS command is sent. This information is delivered to the miniport driver in the HbaPortWWN member of a SM\_SendRLS\_IN structure.

*DestWWN*
A worldwide name (WWN) for the destination port. This information is delivered to the miniport driver in the DestWWN member of a SM\_SendRLS\_IN structure.

*InRespBufferMaxSize*
The maximum size, in bytes, of the response buffer.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_SendRLS\_OUT structure.

*TotalRespBufferSize*
The size, in bytes, of the results of the RLS command. The miniport driver returns this information in the TotalRespBufferSize member of a SM\_SendRLS\_OUT structure.

*OutRespBufferSize*
The size, in bytes, of the data that was actually retrieved. The miniport driver returns this information in the OutRespBufferSize member of a SM\_SendRLS\_OUT structure.

*RespBuffer*
The results of the RLS command. The miniport driver returns this information in the RespBuffer member of a SM\_SendRLS\_OUT structure.

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

[**SM\_SendRLS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendrls_out)

