# SM\_SendSRL function

The SM\_SendSRL WMI method sends a scan remote loop (SRL) command through the indicated port to the indicated domain controller.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the local port through which the SRL command is sent. This information is delivered to the miniport driver in the HbaPortWWN member of a SM\_SendSRL\_IN structure.

*WWN*
A worldwide name (WWN) for the port of type FL\_Port whose loop is to be scanned. This information is delivered to the miniport driver in the WWN member of a SM\_SendSRL\_IN structure.

*Domain*
The domain number for the domain whose loops are to be scanned. This information is delivered to the miniport driver in the Domain member of a SM\_SendSRL\_IN structure.

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

[**SM\_SendSRL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_sendsrl_out)

