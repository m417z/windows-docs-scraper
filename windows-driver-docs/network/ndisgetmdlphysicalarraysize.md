# NdisGetMdlPhysicalArraySize macro

The **NdisGetMdlPhysicalArraySize** macro retrieves the number of disconnected physical memory blocks that are associated with an MDL.

## Parameters

*\_Mdl*
A pointer to an MDL.

*\_ArraySize*
A pointer to a caller-supplied variable in which this macro returns the number of disconnected physical memory blocks that are associated with the specified MDL.

## Return value

None

## Remarks

The **NdisGetMdlPhysicalArraySize** macro provides an MDL-based version of the [**NdisGetBufferPhysicalArraySize**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff552033(v=vs.85)) function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in NDIS 6.0 and later. |
| Header | Ndis.h (include Ndis.h) |
| IRQL | <= DISPATCH_LEVEL |
| DDI compliance rules | [**Irql_NetBuffer_Function**](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-irql-netbuffer-function) |

## See also

[**NdisGetBufferPhysicalArraySize**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff552033(v=vs.85))