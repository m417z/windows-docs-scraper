# SM\_SendLIRR function

The SM\_SendLIRR WMI method sends a link incident record registration (LIRR) command through the indicated local port to the indicated remote port.

## Parameters

*SourceWWN*
A worldwide name (WWN) for the local port through which the LIRR command is sent. This information is delivered to the miniport driver in the SourceWWN member of a SM\_SendLIRR\_IN structure.

*DestWWN*
A worldwide name (WWN) for the destination port. This information is delivered to the miniport driver in the DestWWN member of a SM\_SendLIRR\_IN structure.

*Function*
The code that identifies which registration function is to be performed. For an explanation of which values can be assigned to this member, see the T11 committee's Fibre Channel Framing and Signaling specification. This information is delivered to the miniport driver in the Function member of a SM\_SendLIRR\_IN structure.

*Type*
The device type for which link information is requested. For an explanation of which values can be assigned to this member, see the T11 committee's *Fibre Channel Framing and Signaling* specification. This information is delivered to the miniport driver in the Function member of a SM\_SendLIRR\_IN structure.

*InRespBufferMaxSize*
The maximum size, in bytes, of the response buffer.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_SendLIRR\_OUT structure.

*TotalRespBufferSize*
The size, in bytes, of the results of the LIRR command. The miniport driver returns this information in the TotalRespBufferSize member of a SM\_SendLIRR\_OUT structure.

*OutRespBufferSize*
The size, in bytes, of the data that was actually retrieved. The miniport driver returns this information in the OutRespBufferSize member of a SM\_SendLIRR\_OUT structure.

*RespBuffer*
The results of the LIRR command. The miniport driver returns this information in the RespBuffer member of a SM\_SendLIRR\_OUT structure.

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

[**SM\_SendLIRR\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendlirr_out)

