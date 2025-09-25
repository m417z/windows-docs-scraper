# NdisMReadDmaCounter function

## Description

The
**NdisMReadDmaCounter** function returns the current value of the system DMA controller's counter.

## Parameters

### `MiniportDmaHandle` [in]

The handle returned when the miniport driver called the
[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) function
during initialization.

## Return value

**NdisMReadDmaCounter** returns the number of bytes remaining in the current DMA transfer on the
channel used by the NIC.

## Remarks

Miniport drivers of devices that use the system DMA controller's auto-initialize mode can call
**NdisMReadDmaCounter**.

## See also

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)