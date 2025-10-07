# SendSRL function

The **SendSRL** WMI method sends a scan remote loop (SRL) command through the indicated port to the indicated domain controller.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SendSRL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendsrl_out) structure.

*PortWWN*
A worldwide name for the local port through which the SRL command is sent. This information is delivered to the miniport driver in the **PortWWN** member of a SendSRL\_IN structure.

*WWN*
A worldwide name for the port of type FL\_Port whose loop is to be scanned. This information is delivered to the miniport driver in the **WWN** member of a SendSRL\_IN structure.

*Domain*
The domain number for the domain whose loops are to be scanned. This information is delivered to the miniport driver in the **Domain** member of a SendSRL\_IN structure.

*TotalRspBufferSize*
The size in bytes of the results of the SRL command. The miniport driver returns this information in the **TotalRspBufferSize** member of a [**SendSRL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendsrl_out) structure.

*ActualRspBufferSize*
The size in bytes of the data that was actually retrieved. The miniport driver returns this information in the **ActualRspBufferSize** member of a [**SendSRL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendsrl_out) structure.

*RspBuffer*
The results of the SRL command. The miniport driver returns this information in the **RspBuffer** member of a [**SendSRL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendsrl_out) structure.

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

SendSRL\_IN
[**SendSRL\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendsrl_out)

