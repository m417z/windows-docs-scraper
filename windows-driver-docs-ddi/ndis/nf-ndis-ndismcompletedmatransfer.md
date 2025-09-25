# NdisMCompleteDmaTransfer macro

## Description

The
**NdisMCompleteDmaTransfer** function indicates that a system DMA transfer operation has completed. It
resets the system DMA controller in preparation for further DMA transfers.

## Parameters

### `_S`

A pointer to a caller-supplied variable in which this function returns the final status of the DMA
transfer, which can be one of the following:

#### NDIS_STATUS_SUCCESS

The data has been transferred and flushed to host memory or to the device to maintain data
integrity.

#### NDIS_STATUS_RESOURCES

The DMA controller was released but the data transfer might be incoherent.

### `_H`

The handle returned when the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
called the
[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) function.

### `_B`

A pointer to the buffer descriptor previously passed to
[NdisMSetupDmaTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetupdmatransfer).

### `_O`

The byte offset at which the transfer began. This value also was passed to
**NdisMSetupDmaTransfer**.

### `_L`

The length in bytes of the transfer. This value also was passed to
**NdisMSetupDmaTransfer**.

### `_M_`

**TRUE** if the transfer was from the host to the NIC, as, for example, a send operation.

## Remarks

**NdisMCompleteDmaTransfer** must be called with
*WriteToDevice* set to **TRUE** before the transferred data is considered present in the NIC's memory.
**NdisMCompleteDmaTransfer** must be called with
*WriteToDevice* set to **FALSE** before the transferred data can be read from host memory.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)

[NdisMSetupDmaTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetupdmatransfer)