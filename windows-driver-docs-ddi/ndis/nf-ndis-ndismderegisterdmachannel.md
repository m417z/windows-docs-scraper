# NdisMDeregisterDmaChannel function

## Description

The
**NdisMDeregisterDmaChannel** function releases a miniport driver's claim on a DMA channel for a
NIC.

## Parameters

### `MiniportDmaHandle` [in]

The DMA handle returned by the
[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) function.

## Remarks

The caller should consider
*MiniportDmaHandle* invalid as soon as it is passed to
**NdisMDeregisterDmaChannel**. This function releases the NIC's claim on the DMA channel in the
registry.

**NdisMDeregisterDmaChannel** can be called only from a miniport driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) and
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) functions.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)