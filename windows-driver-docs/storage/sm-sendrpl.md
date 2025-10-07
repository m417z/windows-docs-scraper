# SM\_SendRPL function

The SM\_SendRPL WMI method sends a read port list (RPL) command through the indicated port to indicated destination port.

## Parameters

*PortWWN*
A worldwide name (WWN) for the local port through which the read port list (RPL) command is sent. This information is delivered to the miniport driver in the PortWWN member of a SM\_SendRPL\_IN structure.

*AgentWWN*
A worldwide name (WWN) for the port that is to be queried for a list of ports of type FC\_Port. For a definition of FC\_Port, see the T11 committee's *Fibre Channel HBA API* specification. This information is delivered to the miniport driver in the AgentWWN member of a SM\_SendRPL\_IN structure.

*AgentDomain*
The domain number for the domain controller that is to be queried for a list of ports of type FC\_Port. For a definition of FC\_Port, see the T11 committee's *Fibre Channel HBA API* specification. This information is delivered to the miniport driver in the agent\_domain member of a SM\_SendRPL\_IN structure.

*PortIndex*
The port index of the first port in the list of ports of type FC\_Port to be returned. This information is delivered to the miniport driver in the portIndex member of a SM\_SendRPL\_IN structure.

*InRespBufferMaxSize*
The maximum size of the response buffer.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SendRPL\_OUT structure.

*TotalRespBufferSize*
The size, in bytes, of the results of the read port list (RPL) command. The miniport driver returns this information in the TotalRespBufferSize member of a SM\_SendRPL\_OUT structure.

*OutRespBufferSize*
The size, in bytes, of the data that was actually retrieved. The miniport driver returns this information in the OutRespBufferSize member of a SM\_SendRPL\_OUT structure.

*RespBuffer*
The results of the read port list (RPL) command. The miniport driver returns this information in the RespBuffer member of a SendRPL\_OUT structure.

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

[**SM\_SendRPL\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendrpl_in)

[**SM\_SendRPL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendrpl_out)

