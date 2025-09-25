# SerCx2PioTransmitDrainFifoComplete function

## Description

The **SerCx2PioTransmitDrainFifoComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished draining the data from the transmit FIFO in the serial controller hardware.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

## Remarks

SerCx2 calls the **SerCx2PioTransmitDrainFifoComplete** event callback function, if it is implemented, to drain the transmit FIFO at the end of a PIO-transmit transaction. This function makes sure that any data bytes that remain in the FIFO are transmitted from the serial port before SerCx2 completes the write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request that initiated the transaction. After the last byte is transmitted from the FIFO, the serial controller driver must call the **SerCx2PioTransmitDrainFifoComplete** method to notify SerCx2. SerCx2 expects this notification and does not complete the write request until it is notified.

The serial controller driver must call **SerCx2PioTransmitDrainFifoComplete** only in response to a call to the *EvtSerCx2PioTransmitDrainFifo* function.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

## See also

[EvtSerCx2PioTransmitDrainFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_drain_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)