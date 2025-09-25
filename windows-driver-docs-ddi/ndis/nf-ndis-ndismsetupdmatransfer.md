# NdisMSetupDmaTransfer macro

## Description

The
**NdisMSetupDmaTransfer** function sets up the host DMA controller for a DMA transfer.

## Parameters

### `_S`

A pointer to a caller-supplied variable in which this function returns the status of the request,
which can be one of the following:

#### NDIS_STATUS_SUCCESS

The DMA controller has been set up to transfer the specified data, which has been flushed to or
from the device to maintain data integrity.

#### NDIS_STATUS_RESOURCES

An attempt to set up the DMA controller for the transfer has failed, either because the channel
designated by
*MiniportDmaHandle* is currently in use transferring data or because the given
*Length* is invalid.

### `_H`

The DMA handle returned by the
[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) function
during initialization.

### `_B`

A pointer to the buffer descriptor mapping the range of host memory from which or into which the
data will be transferred.

### `_O`

The byte offset within the mapped buffer at which the transfer should start. Zero indicates the
transfer should begin at the initial byte of the range specified at
*Buffer* .

### `_L`

The number of bytes of data to be transferred. The range specified by
*Offset* and
*Length* must be a proper subrange of that specified at
*Buffer* .

### `_M_`

A boolean value that is **TRUE** for an outbound transfer from the system through the NIC. Otherwise,
it is **FALSE**.

## Remarks

Drivers of subordinate-DMA NICs call
**NdisMSetupDmaTransfer** in response to incoming send requests, for which the driver sets
*WriteToDevice* to **TRUE**. They set
*WriteToDevice* to **FALSE** when they transfer received data from the NIC to host memory.

The caller of
**NdisMSetupDmaTransfer** supplies a buffer descriptor mapping the host memory range that is the target
of the transfer or that contains data for a download operation from the host to the NIC. To specify a
transfer sized to suit the DMA constraints of the NIC, the caller can set up a subrange to be transferred
with the
*Offset* and
*Length* parameters if necessary.

The caller must supply a buffer descriptor that specifies the host range into which received data will
be transferred from the NIC when
*WriteToDevice* is **FALSE**. Otherwise, the buffer descriptor at
*Buffer* was chained to a packet descriptor input to the miniport driver's
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function.

To improve performance for small transmit requests, such as a send request of less than 256 bytes in
length, a miniport driver can copy the packet data into an internal staging buffer and pass a
driver-allocated buffer descriptor mapping that buffer to
**NdisMSetupDmaTransfer**.

On return from
**NdisMSetupDmaTransfer**, the host DMA controller has been programmed for the transfer. The miniport
driver then programs the NIC for the transfer operation.

When the transfer is complete, the miniport driver must call the
[NdisMCompleteDmaTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcompletedmatransfer) function.

## See also

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[NdisMCompleteDmaTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcompletedmatransfer)

[NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel)