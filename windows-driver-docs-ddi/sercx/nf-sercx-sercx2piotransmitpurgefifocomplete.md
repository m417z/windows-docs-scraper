# SerCx2PioTransmitPurgeFifoComplete function

## Description

The **SerCx2PioTransmitPurgeFifoComplete** method notifies version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished purging the data from the transmit FIFO in the serial controller hardware.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

### `BytesPurged` [in]

The number of bytes of unsent data that the serial controller driver purged from the transmit FIFO.

## Remarks

SerCx2 calls the [EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo) event callback function, if it is implemented, to end the current PIO-transmit transaction. SerCx2 previously initiated this transaction in response to a write ([IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)) request from a client. For example, SerCx2 might call this function if the client cancels the pending write request, or the write request times out. For more information, see [SerCx2 Handling of Read and Write Requests](https://learn.microsoft.com/previous-versions/hh406672(v=vs.85)).

In response to the *EvtSerCx2PioTransmitPurgeFifo* function call, the driver first discards any data that remains in the transmit FIFO; then the driver must call **SerCx2PioTransmitPurgeFifoComplete** to notify SerCx2. SerCx2 expects this notification and does not complete the write request until it is notified.

The serial controller driver must call **SerCx2PioTransmitPurgeFifoComplete** only in response to a call to the *EvtSerCx2PioTransmitPurgeFifo* function.

SerCx2 uses the *BytesPurged* parameter value to determine how many bytes were successfully transmitted before the transmit FIFO was purged. SerCx2 requires this information to complete a write request that times out, or a write request that is canceled after one or more bytes are transmitted.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

## See also

[EvtSerCx2PioTransmitPurgeFifo](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_purge_fifo)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)