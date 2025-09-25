# SerCx2SystemDmaTransmitPurgeFifoComplete function

## Description

The **SerCx2SystemDmaTransmitPurgeFifoComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished purging the data from the transmit FIFO in the serial controller hardware.

## Parameters

### `SystemDmaTransmit` [in]

A [SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-transmit object. The serial controller driver previously called the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method to create this object.

### `BytesPurged` [in]

The number of bytes of unsent data that the serial controller driver purged from the transmit FIFO.

## Remarks

SerCx2 calls the [EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo) event callback function, if it is implemented, to tell the serial controller driver to terminate the current system-DMA-transmit transaction. SerCx2 previously initiated this transaction in response to a write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request from a client. For example, SerCx2 might call this function if the client cancels the pending write request, or if the write request times out. For more information, see [SerCx2 Handling of Read and Write Requests](https://learn.microsoft.com/previous-versions/hh406672(v=vs.85)).

In response to the *EvtSerCx2SystemDmaTransmitPurgeFifo* call, the driver stops the transfer of data from the write buffer to the transmit FIFO, and discards any previously transferred data that remains in the transmit FIFO. After the purge finishes, the serial controller driver must call **SerCx2SystemDmaTransmitPurgeFifoComplete** to notify SerCx2. SerCx2 expects this notification and does not complete the write request until it is notified.

The serial controller driver must call **SerCx2SystemDmaTransmitPurgeFifoComplete** only in response to a call to the [EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo) function.

SerCx2 uses the *BytesPurged* parameter value to determine how many bytes were successfully transmitted before the transmit FIFO was purged. SerCx2 requires this information to complete a write request that times out, or a write request that is canceled after one or more bytes are transmitted.

For more information, see [SerCx2 System-DMA-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265338(v=vs.85)).

## See also

[EvtSerCx2SystemDmaTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_purge_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)