# NdisQueryMdl macro

The **NdisQueryMdl** macro retrieves the buffer length, and optionally the base virtual address, from an MDL.

## Parameters

*\_Mdl*
A pointer to an MDL.

*\_VirtualAddress*
A pointer to a caller-supplied variable in which this macro returns the base virtual address of the virtual address range that is described by the MDL. The base virtual address can be **NULL** for either of the following reasons:

- System resources are low or exhausted and the *\_Priority* parameter is set to **LowPagePriority** or **NormalPagePriority**.

- System resources are exhausted and the *\_Priority* parameter is set to **HighPagePriority**.

*\_Length*
A pointer to a caller-supplied variable in which this macro returns the length, in bytes, of the virtual address range that is described by the MDL.

*\_Priority*
A page priority value. For a list of the possible values for this parameter, see the *Priority* parameter of the [**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe) macro.

## Return value

None

## Remarks

The **NdisQueryMdl** macro provides an MDL-based version of the [**NdisQueryBuffer**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff554407(v=vs.85)) function.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in NDIS 6.0 and later. |
| Header | Ndis.h (include Ndis.h) |
| IRQL | <= DISPATCH_LEVEL |
| DDI compliance rules | [**Irql_NetBuffer_Function**](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-irql-netbuffer-function) |

## See also

[**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[**NdisQueryBuffer**](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff554407(v=vs.85))