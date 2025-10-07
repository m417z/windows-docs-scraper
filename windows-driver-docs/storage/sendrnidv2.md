# SendRNIDV2 function

The **SendRNIDV2** WMI method sends a version 2 RNID command to the indicated port.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SendRNIDV2\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_out) structure.

*PortWWN*
A worldwide name for the local port through which the version 2 RNID command is sent. This information is delivered to the miniport driver in the **PortWWN** member of a [**SendRNIDV2\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_in) structure.

*DestWWN*
A worldwide name for the destination port. This information is delivered to the miniport driver in the **DestWWN** member of a [**SendRNIDV2\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_in) structure.

*DestFCID*
An address identifier of the destination port. This information is delivered to the miniport driver in the **DestFCID** member of a [**SendRNIDV2\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_in) structure.

*NodeIdDataFormat*
The node identification data format. For a description of the values that this member can have, see the T11 committee's *Fibre Channel HBA API* specification. This information is delivered to the miniport driver in the **NodeIdDataFormat** member of a [**SendRNIDV2\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_in) structure.

*TotalRspBufferSize*
The size in bytes of the results of the version 2 RNID command. The miniport driver returns this information in the **TotalRspBufferSize** member of a [**SendRNIDV2\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_out) structure.

*ActualRspBufferSize*
The size in bytes of the data that was actually retrieved. The miniport driver returns this information in the **ActualRspBufferSize** member of a [**SendRNIDV2\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_out) structure.

*RspBuffer*
The results of the version 2 RNID command. The miniport driver returns this information in the **RspBuffer** member of a [**SendRNIDV2\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_out) structure.

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

[**SendRNIDV2\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_in)

[**SendRNIDV2\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendrnidv2_out)

