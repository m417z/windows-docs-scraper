# NetDmaGetVersion function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaGetVersion** function returns the version of the NetDMA interface that the local computer
supports.

## Return value

**NetDmaGetVersion** returns a UINT value that contains the major and minor version numbers as
follows:

| Return code | Description |
| --- | --- |
| **High 16 bits** | The major version number of the NetDMA interface. |
| **Low 16 bits** | The minor version of NetDMA interface. |

## Remarks

NetDMA provider drivers can call the
**NetDmaGetVersion** function to obtain the version of the NetDMA interface. A NetDMA provider must
register as a NetDMA provider with a version equal to or lower than the NetDMA provider interface version
that the local computer supports. The NetDMA provider driver specifies the major and minor version of the
NetDMA provider in the
**MajorVersion** and
**MinorVersion** members of the
[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics) structure that it passes to the
[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider) function.

**Note** **NetDmaGetVersion** is not available in NetDMA version 1.0. To avoid using a function import that
might stop the driver from loading, a NetDMA 1.1 or later provider driver must verify the presence of
**NetDmaGetVersion** before it calls
**NetDmaGetVersion**. To call
**NetDmaGetVersion**, first call the
[NdisGetRoutineAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetroutineaddress) function to
get the entry point and then, if
**NetDmaGetVersion** is available, call
**NetDmaGetVersion** at the entry point that
**NdisGetRoutineAddress** provided. If the provider driver cannot get the address of
**NetDmaGetVersion**, the supported NetDMA interface must be version 1.0.

NetDMA provider drivers call
**NetDmaGetVersion** at IRQL = PASSIVE_LEVEL.

## See also

[NET_DMA_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_provider_characteristics)

[NdisGetRoutineAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetroutineaddress)

[NetDmaRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaregisterprovider)