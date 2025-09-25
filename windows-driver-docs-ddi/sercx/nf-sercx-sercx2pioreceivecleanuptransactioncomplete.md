# SerCx2PioReceiveCleanupTransactionComplete function

## Description

The **SerCx2PioReceiveCleanupTransactionComplete** method informs version 2 of the serial framework extension (SerCx2) that the serial controller driver has finished cleaning up the serial controller's hardware state after a PIO-receive transaction.

## Parameters

### `PioReceive` [in]

A [SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a PIO-receive object. The serial controller driver previously called the [SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate) method to create this object.

## Remarks

After a PIO-receive transaction ends, SerCx2 calls the [EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction) event callback function, if it is implemented, to clean up the serial controller state. In response to this call, the driver should first do any clean-up work that is needed; then the driver must call **SerCx2PioReceiveCleanupTransactionComplete** to notify SerCx2. SerCx2 expects this notification and does not start the next transaction until it is notified.

The serial controller driver must call **SerCx2PioReceiveCleanupTransactionComplete** only in response to a call to the *EvtSerCx2PioReceiveCleanupTransaction* function.

For more information, see [SerCx2 PIO-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265332(v=vs.85)).

## See also

[EvtSerCx2PioReceiveCleanupTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx2_pio_receive_cleanup_transaction)

[SERCX2PIORECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SerCx2PioReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2pioreceivecreate)