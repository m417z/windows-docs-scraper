# SendLIRR function

The **SendLIRR** WMI method sends a link incident record registration (LIRR) command through the indicated local port to the indicated remote port.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SendLIRR\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_out) structure.

*SourceWWN*
A worldwide name for the local port through which the LIRR command is sent. This information is delivered to the miniport driver in the **SourceWWN** member of a [**SendLIRR\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_in) structure.

*DestWWN*
A worldwide name for the destination port. This information is delivered to the miniport driver in the **DestWWN** member of a [**SendLIRR\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_in) structure.

*Function*
The code that identifies which registration function is to be performed. For an explanation of which values can be assigned to this member, see the T11 committee's *Fibre Channel Framing and Signaling* specification. This information is delivered to the miniport driver in the **Function** member of a [**SendLIRR\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_in) structure.

*Type*
The device type for which link information is requested. For an explanation of which values can be assigned to this member, see the T11 committee's *Fibre Channel Framing and Signaling* specification. This information is delivered to the miniport driver in the **Function** member of a [**SendLIRR\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_in) structure.

*TotalRspBufferSize*
The size in bytes of the results of the LIRR command. The miniport driver returns this information in the **TotalRspBufferSize** member of a [**SendLIRR\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_out) structure.

*ActualRspBufferSize*
The size in bytes of the data that was actually retrieved. The miniport driver returns this information in the **ActualRspBufferSize** member of a [**SendLIRR\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_out) structure.

*RspBuffer*
The results of the LIRR command. The miniport driver returns this information in the **RspBuffer** member of a [**SendLIRR\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_out) structure.

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

[**SendLIRR\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_in)

[**SendLIRR\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendlirr_out)

