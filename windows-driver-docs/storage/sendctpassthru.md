# SendCTPassThru function

The **SendCTPassThru** WMI method sends a common transport (CT) passthrough command to the indicated port.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SendCTPassThru\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_out) structure.

*PortWWN*
A worldwide name for the HBA through which the target is accessed. This information is delivered to the miniport driver in the **PortWWN** member of a [**SendCTPassThru\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_in) structure.

*RequestBufferCount*
The size in bytes of the buffer that will hold the results of the common transport command. The miniport driver returns this information in the **RequestBufferCount** member of a [**SendCTPassThru\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_in) structure.

*RequestBuffer*
The results of the common transport command. The miniport driver returns this information in the **RequestBuffer** member of a [**SendCTPassThru\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_in) structure.

*TotalResponseBufferCount*
The size in bytes of the results common transport command. The miniport driver returns this information in the **TotalResponseBufferCount** member of a [**SendCTPassThru\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_out) structure.

*ActualResponseBufferCount*
The size in bytes of the data that was actually retrieved. The miniport driver returns this information in the **ActualResponseBufferCount** member of a [**SendCTPassThru\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_out) structure.

*ResponseBuffer*
The results of the common transport command. The miniport driver returns this information in the **ResponseBuffer** member of a [**SendCTPassThru\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_out) structure.

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

[**SendCTPassThru\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_in)

[**SendCTPassThru\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sendctpassthru_out)

