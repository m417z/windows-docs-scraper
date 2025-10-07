# SendRPL function

The **SendRPL** WMI method sends a read port list (RPL) command through the indicated port to indicated destination port.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SendRPL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_out) structure.

*PortWWN*
A worldwide name for the local port through which the read port list (RPL) command is sent. This information is delivered to the miniport driver in the **PortWWN** member of a [**SendRPL\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_in) structure.

*AgentWWN*
A worldwide name for the port that is to be queried for a list of ports of type FC\_Port. For a definition of FC\_Port, see the T11 committee's *Fibre Channel HBA API* specification. This information is delivered to the miniport driver in the **AgentWWN** member of a [**SendRPL\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_in) structure.

*agent\_domain*
The domain number for the domain controller that is to be queried for a list of ports of type FC\_Port. For a definition of FC\_Port, see the T11 committee's *Fibre Channel HBA API* specification. This information is delivered to the miniport driver in the **agent\_domain** member of a [**SendRPL\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_in) structure.

*portIndex*
The port index of the first port in the list of ports of type FC\_Port to be returned. This information is delivered to the miniport driver in the **portIndex** member of a [**SendRPL\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_in) structure.

*TotalRspBufferSize*
The size in bytes of the results of the read port list (RPL) command. The miniport driver returns this information in the **TotalRspBufferSize** member of a [**SendRPL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_out) structure.

*ActualRspBufferSize*
The size in bytes of the data that was actually retrieved. The miniport driver returns this information in the **ActualRspBufferSize** member of a [**SendRPL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_out) structure.

*RspBuffer*
The results of the read port list (RPL) command. The miniport driver returns this information in the **RspBuffer** member of a [**SendRPL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_out) structure.

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

[**SendRPL\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_in)

[**SendRPL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrpl_out)

