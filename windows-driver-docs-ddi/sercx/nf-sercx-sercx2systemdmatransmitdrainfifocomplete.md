# SerCx2SystemDmaTransmitDrainFifoComplete function

## Description

The **SerCx2SystemDmaTransmitDrainFifoComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished draining the data from the transmit FIFO in the serial controller hardware.

## Parameters

### `SystemDmaTransmit`

A [**SERCX2SYSTEMDMATRANSMIT**](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [**SerCx2SystemDmaTransmitCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method to create this object.

## Remarks

SerCx2 calls the [EvtSerCx2SystemDmaTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_drain_fifo) event callback function, if it is implemented, to drain the transmit FIFO at the end of a system-DMA-transmit transaction. This function makes sure that any data bytes that remain in the FIFO are transmitted from the serial port before SerCx2 completes the write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request that initiated the transaction. After the last byte is transmitted from the FIFO, the serial controller driver must call the **SerCx2SystemDmaTransmitDrainFifoComplete** method to notify SerCx2. SerCx2 expects this notification and does not complete the write request until it is notified.

The serial controller must call **SerCx2SystemDmaTransmitDrainFifoComplete** only in response to a call to the *EvtSerCx2SystemDmaTransmitDrainFifo* function.

For more information, see [SerCx2 System-DMA-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265338(v=vs.85)).

## See also

[EvtSerCx2SystemDmaTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_system_dma_transmit_drain_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)