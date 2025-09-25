# SerCx2PioReceiveReady function

## Description

The **SerCx2PioReceiveReady** method notifies version 2 of the serial framework extension (SerCx2) that data is available to be read from the receive FIFO in the serial controller.

## Parameters

### `PioReceive` [in]

A [SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-receive object. The serial controller driver previously called the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method to create this object.

## Remarks

To initiate a PIO-receive transaction, SerCx2 calls the [EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer) event callback function and supplies a read buffer to which to transfer the data from the receive FIFO in the serial controller. If the return value from this function indicates that the read buffer was only partially filled before the receive FIFO became empty, SerCx2 calls the [EvtSerCx2PioReceiveEnableReadyNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_enable_ready_notification) event callback routine to enable a ready notification to occur when more data is available to be read.

If the ready notification is enabled and more data is available to be read, the serial controller driver must call **SerCx2PioReceiveReady** to notify SerCx2. In response to this notification, SerCx2 calls the *EvtSerCx2PioReceiveReadBuffer* function again to transfer more data from the receive FIFO to the read buffer.

The serial controller driver must call **SerCx2PioReceiveReady** only in response to a call to the *EvtSerCx2PioReceiveEnableReadyNotification* function.

Additionally, SerCx2 uses these ready notifications to detect interval time-outs during the handling of a read request. For more information about interval time-outs, see [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts). For more information about ready notifications, see [SerCx2 PIO-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265332(v=vs.85)).

## See also

[EvtSerCx2PioReceiveReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_read_buffer)

[SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)