# SendRPS function

The **SendRPS** WMI method sends a read port status block (RPS) request to the indicated port or domain controller.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SendRPS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_out) structure.

*PortWWN*
A worldwide name for the local port through which the RPS command is sent. This information is delivered to the miniport driver in the **PortWWN** member of a [**SendRPS\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_in) structure.

*AgentWWN*
A worldwide name for the port that is to be queried for the status of the port indicated by *ObjectWWN*. This information is delivered to the miniport driver in the **AgentWWN** member of a [**SendRPS\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_in) structure.

*ObjectWWN*
The worldwide name of the port for which port status is to be returned. This information is delivered to the miniport driver in the **ObjectWWN** member of a [**SendRPS\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_in) structure.

*AgentDomain*
The domain number of the domain controller to be queried for the status of the port indicated by *ObjectWWN*. This information is delivered to the miniport driver in the **AgentDomain** member of a [**SendRPS\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_in) structure.

*ObjectPortNumber*
The worldwide name of the port for which port status is to be returned. This information is delivered to the miniport driver in the **ObjectPortNumber** member of a [**SendRPS\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_in) structure.

*TotalRspBufferSize*
The size in bytes of the results of the RPS command. The miniport driver returns this information in the **TotalRspBufferSize** member of a [**SendRPS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_out) structure.

*ActualRspBufferSize*
The size in bytes of the data that was actually retrieved. The miniport driver returns this information in the **ActualRspBufferSize** member of a [**SendRPS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_out) structure.

*RspBuffer*
The results of the RPS command. The miniport driver returns this information in the **RspBuffer** member of a [**SendRPS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_out) structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |
| Library | Hbaapi.lib |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**SendRPS\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_in)

[**SendRPS\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrps_out)

