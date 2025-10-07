# SM\_SendRPS function

The SM\_SendRPS WMI method sends a read port status block (RPS) request to the indicated port or domain controller.

## Parameters

*PortWWN*
A worldwide name (WWN) for the local port through which the RPS command is sent. This information is delivered to the miniport driver in the PortWWN member of a SM\_SendRPS\_IN structure.

*AgentWWN*
A worldwide name (WWN) for the port that is to be queried for the status of the port that is indicated by ObjectWWN. This information is delivered to the miniport driver in the AgentWWN member of a SM\_SendRPS\_IN structure.

*ObjectWWN*
The worldwide name (WWN) of the port for which port status is to be returned. This information is delivered to the miniport driver in the ObjectWWN member of a SM\_SendRPS\_IN structure.

*AgentDomain*
The domain number of the domain controller to be queried for the status of the port that is indicated by ObjectWWN. This information is delivered to the miniport driver in the AgentDomain member of a SM\_SendRPS\_IN structure.

*ObjectPortNumber*
The worldwide name (WWN) of the port for which port status is to be returned. This information is delivered to the miniport driver in the ObjectPortNumber member of a SM\_SendRPS\_IN structure.

*InRespBufferMaxSize*
The maximum size of the response buffer.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SendRPL\_OUT structure.

*TotalRespBufferSize*
The size, in bytes, of the results of the RPS command. The miniport driver returns this information in the TotalRespBufferSize member of a SM\_SendRPS\_OUT structure.

*OutRespBufferSize*
The size, in bytes, of the data that was actually retrieved. The miniport driver returns this information in the OutRespBufferSize member of a SM\_SendRPL\_OUT structure.

*RespBuffer*
The results of the RPS command. The miniport driver returns this information in the RespBuffer member of a SM\_SendRPS\_OUT structure.

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

[**SM\_SendRPS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendrps_out)

