# SM\_SendRNID function

The SM\_SendRNID WMI method sends a request node identification data (RNID) command to the indicated port.

## Parameters

*PortWWN*
A worldwide name (WWN) for the local port through which the RNID command is sent. This information is delivered to the miniport driver in the PortWWN member of a SM\_SendRNID\_IN structure.

*DestWWN*
A worldwide name (WWN) for the destination port. This information is delivered to the miniport driver in the DestWWN member of a SM\_SendRNID\_IN structure.

*DestFCID*
An address identifier of the destination port. This information is delivered to the miniport driver in the DestFCID member of a SM\_SendRNID\_IN structure.

*NodeIdDataFormat*
The node identification data format. For a description of the values that this member can have, see the T11 committee's *Fibre Channel HBA API* specification. This information is delivered to the miniport driver in the NodeIdDataFormat member of a SM\_SendRNID\_IN structure.

*InRespBufferMaxSize*
The maximum size of the response buffer.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_SendRNID\_OUT structure.

*TotalRespBufferSize*
The size, in bytes, of the results of the RNID command. The miniport driver returns this information in the TotalRspBufferSize member of a SM\_SendRNID\_OUT structure.

*ResponseBufferSize*
The size, in bytes, of the results of the RNID command. The miniport driver returns this information in the ResponseBufferSize member of a SM\_SendRNID\_OUT structure.

*ResponseBuffer*
The results of the RNID command. The miniport driver returns this information in the ResponseBuffer member of a SM\_SendRNID\_OUT structure.

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

[**SM\_SendRNID\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendrnid_in)

[**SM\_SendRNID\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendrnid_out)

