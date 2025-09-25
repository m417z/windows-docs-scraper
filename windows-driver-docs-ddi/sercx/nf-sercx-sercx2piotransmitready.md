# SerCx2PioTransmitReady function

## Description

The **SerCx2PioTransmitReady** method notifies version 2 of the serial framework extension (SerCx2) that the transmit FIFO in the serial controller hardware is ready to accept more data.

## Parameters

### `PioTransmit` [in]

A [SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-transmit object. The serial controller driver previously called the [SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate) method to create this object.

## Remarks

To initiate a PIO-transmit transaction, SerCx2 calls the [EvtSerCx2PioTransmitWriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_write_buffer) event callback function and supplies a write buffer that contains the data to be transmitted. If the return value from this call indicates that the transmit FIFO in the serial controller became full before the entire contents of the write buffer could be transmitted, SerCx2 calls the [EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification) event callback function to enable a ready notification to occur when the FIFO is ready to accept more data.

If the ready notification is enabled, the serial controller driver must call **SerCx2PioTransmitReady** to notify SerCx2 after the transmit FIFO becomes ready to accept more data. In response to this notification, SerCx2 calls the *EvtSerCx2PioTransmitWriteBuffer* function again to transfer more data from the write buffer to the transmit FIFO.

The serial controller driver must call **SerCx2PioTransmitReady** only in response to a call to the *EvtSerCx2PioTransmitEnableReadyNotification* function.

For more information, see [SerCx2 PIO-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265336(v=vs.85)).

## See also

[EvtSerCx2PioTransmitEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_enable_ready_notification)

[EvtSerCx2PioTransmitWriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_transmit_write_buffer)

[SERCX2PIOTRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2piotransmitcreate)